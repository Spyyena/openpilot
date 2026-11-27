"""
Copyright (c) 2021-, Haibin Wen, sunnypilot, and a number of other contributors.

This file is part of sunnypilot and is licensed under the MIT License.
See the LICENSE.md file in the root directory for more details.
"""
from enum import StrEnum

from opendbc.car import Bus, structs
from opendbc.car.common.conversions import Conversions as CV
from opendbc.car.honda.values import HondaFlags
from opendbc.can.parser import CANParser
from opendbc.sunnypilot.car.honda.values_ext import HondaFlagsSP


def speed_limit_sign_available(CP) -> bool:
  # Camera traffic sign recognition, seen on the powertrain bus of Bosch (non-radarless, non-CAN FD) cars.
  # Verified on the 2018-22 Accord (imperial cluster).
  return bool(CP.flags & HondaFlags.BOSCH) and not (CP.flags & (HondaFlags.BOSCH_RADARLESS | HondaFlags.BOSCH_CANFD))


class CarStateExt:
  def __init__(self, CP, CP_SP):
    self.CP = CP
    self.CP_SP = CP_SP

  @staticmethod
  def pt_messages_ext(CP) -> list[tuple[str, float]]:
    # NaN frequency: never affects CAN validity, so cars without this message are unaffected
    return [("CAMERA_MESSAGES", float('nan'))] if speed_limit_sign_available(CP) else []

  def update_speed_limit(self, cp) -> float:
    if not speed_limit_sign_available(self.CP) or self.is_metric:
      return 0.
    # low 5 bits = sign value / 5 mph; 1-17 = 5-85 mph, other codes (e.g. 29) = no sign
    code = int(cp.vl["CAMERA_MESSAGES"]["SPEED_LIMIT_SIGN"]) & 0x1F
    return code * 5 * CV.MPH_TO_MS if 1 <= code <= 17 else 0.

  def update(self, ret: structs.CarState, ret_sp: structs.CarStateSP, can_parsers: dict[StrEnum, CANParser]) -> None:
    cp = can_parsers[Bus.pt]
    cp_cam = can_parsers[Bus.cam]

    ret_sp.speedLimit = self.update_speed_limit(cp)

    if self.CP_SP.flags & HondaFlagsSP.NIDEC_HYBRID:
      ret.accFaulted = bool(cp.vl["HYBRID_BRAKE_ERROR"]["BRAKE_ERROR_1"] or cp.vl["HYBRID_BRAKE_ERROR"]["BRAKE_ERROR_2"])
      ret.stockAeb = bool(cp_cam.vl["BRAKE_COMMAND"]["AEB_REQ_1"] and cp_cam.vl["BRAKE_COMMAND"]["COMPUTER_BRAKE_HYBRID"] > 1e-5)

    if self.CP_SP.flags & HondaFlagsSP.HYBRID_ALT_BRAKEHOLD:
      ret.brakeHoldActive = cp.vl["BRAKE_HOLD_HYBRID_ALT"]["BRAKE_HOLD_ACTIVE"] == 1
      ret.blockPcmEnable = ret.brakeHoldActive and not self.CP_SP.enableGasInterceptor

    if self.CP_SP.enableGasInterceptor:
      # Same threshold as panda, equivalent to 1e-5 with previous DBC scaling
      gas = (cp.vl["GAS_SENSOR"]["INTERCEPTOR_GAS"] + cp.vl["GAS_SENSOR"]["INTERCEPTOR_GAS2"]) // 2
      ret.gasPressed = gas > 492
