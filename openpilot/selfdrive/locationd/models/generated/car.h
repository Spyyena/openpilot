#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8357671443470322918);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1475244586979939250);
void car_H_mod_fun(double *state, double *out_5997040658792740711);
void car_f_fun(double *state, double dt, double *out_2227498500027403860);
void car_F_fun(double *state, double dt, double *out_976225617616189007);
void car_h_25(double *state, double *unused, double *out_5533497581884027539);
void car_H_25(double *state, double *unused, double *out_1093348833608075871);
void car_h_24(double *state, double *unused, double *out_3868635513509090583);
void car_H_24(double *state, double *unused, double *out_5482222972983442230);
void car_h_30(double *state, double *unused, double *out_8481223572239512500);
void car_H_30(double *state, double *unused, double *out_5823341507883540884);
void car_h_26(double *state, double *unused, double *out_3479550304578666855);
void car_H_26(double *state, double *unused, double *out_4834852152482132095);
void car_h_27(double *state, double *unused, double *out_3448471590122813226);
void car_H_27(double *state, double *unused, double *out_3648578196083115973);
void car_h_29(double *state, double *unused, double *out_3173277527838307337);
void car_H_29(double *state, double *unused, double *out_1935215469213564940);
void car_h_28(double *state, double *unused, double *out_1553201677538032419);
void car_H_28(double *state, double *unused, double *out_3147183547855965634);
void car_h_31(double *state, double *unused, double *out_6359149687671870395);
void car_H_31(double *state, double *unused, double *out_1062702871731115443);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}