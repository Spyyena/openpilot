#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8357671443470322918) {
   out_8357671443470322918[0] = delta_x[0] + nom_x[0];
   out_8357671443470322918[1] = delta_x[1] + nom_x[1];
   out_8357671443470322918[2] = delta_x[2] + nom_x[2];
   out_8357671443470322918[3] = delta_x[3] + nom_x[3];
   out_8357671443470322918[4] = delta_x[4] + nom_x[4];
   out_8357671443470322918[5] = delta_x[5] + nom_x[5];
   out_8357671443470322918[6] = delta_x[6] + nom_x[6];
   out_8357671443470322918[7] = delta_x[7] + nom_x[7];
   out_8357671443470322918[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1475244586979939250) {
   out_1475244586979939250[0] = -nom_x[0] + true_x[0];
   out_1475244586979939250[1] = -nom_x[1] + true_x[1];
   out_1475244586979939250[2] = -nom_x[2] + true_x[2];
   out_1475244586979939250[3] = -nom_x[3] + true_x[3];
   out_1475244586979939250[4] = -nom_x[4] + true_x[4];
   out_1475244586979939250[5] = -nom_x[5] + true_x[5];
   out_1475244586979939250[6] = -nom_x[6] + true_x[6];
   out_1475244586979939250[7] = -nom_x[7] + true_x[7];
   out_1475244586979939250[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5997040658792740711) {
   out_5997040658792740711[0] = 1.0;
   out_5997040658792740711[1] = 0.0;
   out_5997040658792740711[2] = 0.0;
   out_5997040658792740711[3] = 0.0;
   out_5997040658792740711[4] = 0.0;
   out_5997040658792740711[5] = 0.0;
   out_5997040658792740711[6] = 0.0;
   out_5997040658792740711[7] = 0.0;
   out_5997040658792740711[8] = 0.0;
   out_5997040658792740711[9] = 0.0;
   out_5997040658792740711[10] = 1.0;
   out_5997040658792740711[11] = 0.0;
   out_5997040658792740711[12] = 0.0;
   out_5997040658792740711[13] = 0.0;
   out_5997040658792740711[14] = 0.0;
   out_5997040658792740711[15] = 0.0;
   out_5997040658792740711[16] = 0.0;
   out_5997040658792740711[17] = 0.0;
   out_5997040658792740711[18] = 0.0;
   out_5997040658792740711[19] = 0.0;
   out_5997040658792740711[20] = 1.0;
   out_5997040658792740711[21] = 0.0;
   out_5997040658792740711[22] = 0.0;
   out_5997040658792740711[23] = 0.0;
   out_5997040658792740711[24] = 0.0;
   out_5997040658792740711[25] = 0.0;
   out_5997040658792740711[26] = 0.0;
   out_5997040658792740711[27] = 0.0;
   out_5997040658792740711[28] = 0.0;
   out_5997040658792740711[29] = 0.0;
   out_5997040658792740711[30] = 1.0;
   out_5997040658792740711[31] = 0.0;
   out_5997040658792740711[32] = 0.0;
   out_5997040658792740711[33] = 0.0;
   out_5997040658792740711[34] = 0.0;
   out_5997040658792740711[35] = 0.0;
   out_5997040658792740711[36] = 0.0;
   out_5997040658792740711[37] = 0.0;
   out_5997040658792740711[38] = 0.0;
   out_5997040658792740711[39] = 0.0;
   out_5997040658792740711[40] = 1.0;
   out_5997040658792740711[41] = 0.0;
   out_5997040658792740711[42] = 0.0;
   out_5997040658792740711[43] = 0.0;
   out_5997040658792740711[44] = 0.0;
   out_5997040658792740711[45] = 0.0;
   out_5997040658792740711[46] = 0.0;
   out_5997040658792740711[47] = 0.0;
   out_5997040658792740711[48] = 0.0;
   out_5997040658792740711[49] = 0.0;
   out_5997040658792740711[50] = 1.0;
   out_5997040658792740711[51] = 0.0;
   out_5997040658792740711[52] = 0.0;
   out_5997040658792740711[53] = 0.0;
   out_5997040658792740711[54] = 0.0;
   out_5997040658792740711[55] = 0.0;
   out_5997040658792740711[56] = 0.0;
   out_5997040658792740711[57] = 0.0;
   out_5997040658792740711[58] = 0.0;
   out_5997040658792740711[59] = 0.0;
   out_5997040658792740711[60] = 1.0;
   out_5997040658792740711[61] = 0.0;
   out_5997040658792740711[62] = 0.0;
   out_5997040658792740711[63] = 0.0;
   out_5997040658792740711[64] = 0.0;
   out_5997040658792740711[65] = 0.0;
   out_5997040658792740711[66] = 0.0;
   out_5997040658792740711[67] = 0.0;
   out_5997040658792740711[68] = 0.0;
   out_5997040658792740711[69] = 0.0;
   out_5997040658792740711[70] = 1.0;
   out_5997040658792740711[71] = 0.0;
   out_5997040658792740711[72] = 0.0;
   out_5997040658792740711[73] = 0.0;
   out_5997040658792740711[74] = 0.0;
   out_5997040658792740711[75] = 0.0;
   out_5997040658792740711[76] = 0.0;
   out_5997040658792740711[77] = 0.0;
   out_5997040658792740711[78] = 0.0;
   out_5997040658792740711[79] = 0.0;
   out_5997040658792740711[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2227498500027403860) {
   out_2227498500027403860[0] = state[0];
   out_2227498500027403860[1] = state[1];
   out_2227498500027403860[2] = state[2];
   out_2227498500027403860[3] = state[3];
   out_2227498500027403860[4] = state[4];
   out_2227498500027403860[5] = dt*(stiffness_front*(-state[2] - state[3] + state[7])*state[0]/state[1] + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/state[4] + ((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4])*state[6] - 9.8100000000000005*state[8]) + state[5];
   out_2227498500027403860[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2227498500027403860[7] = state[7];
   out_2227498500027403860[8] = state[8];
}
void F_fun(double *state, double dt, double *out_976225617616189007) {
   out_976225617616189007[0] = 1;
   out_976225617616189007[1] = 0;
   out_976225617616189007[2] = 0;
   out_976225617616189007[3] = 0;
   out_976225617616189007[4] = 0;
   out_976225617616189007[5] = 0;
   out_976225617616189007[6] = 0;
   out_976225617616189007[7] = 0;
   out_976225617616189007[8] = 0;
   out_976225617616189007[9] = 0;
   out_976225617616189007[10] = 1;
   out_976225617616189007[11] = 0;
   out_976225617616189007[12] = 0;
   out_976225617616189007[13] = 0;
   out_976225617616189007[14] = 0;
   out_976225617616189007[15] = 0;
   out_976225617616189007[16] = 0;
   out_976225617616189007[17] = 0;
   out_976225617616189007[18] = 0;
   out_976225617616189007[19] = 0;
   out_976225617616189007[20] = 1;
   out_976225617616189007[21] = 0;
   out_976225617616189007[22] = 0;
   out_976225617616189007[23] = 0;
   out_976225617616189007[24] = 0;
   out_976225617616189007[25] = 0;
   out_976225617616189007[26] = 0;
   out_976225617616189007[27] = 0;
   out_976225617616189007[28] = 0;
   out_976225617616189007[29] = 0;
   out_976225617616189007[30] = 1;
   out_976225617616189007[31] = 0;
   out_976225617616189007[32] = 0;
   out_976225617616189007[33] = 0;
   out_976225617616189007[34] = 0;
   out_976225617616189007[35] = 0;
   out_976225617616189007[36] = 0;
   out_976225617616189007[37] = 0;
   out_976225617616189007[38] = 0;
   out_976225617616189007[39] = 0;
   out_976225617616189007[40] = 1;
   out_976225617616189007[41] = 0;
   out_976225617616189007[42] = 0;
   out_976225617616189007[43] = 0;
   out_976225617616189007[44] = 0;
   out_976225617616189007[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/state[1] + (-stiffness_front - stiffness_rear)*state[5]/state[4] + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/state[4]);
   out_976225617616189007[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/pow(state[1], 2);
   out_976225617616189007[47] = -dt*stiffness_front*state[0]/state[1];
   out_976225617616189007[48] = -dt*stiffness_front*state[0]/state[1];
   out_976225617616189007[49] = dt*(-(-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/pow(state[4], 2) + (-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/pow(state[4], 2) - 1)*state[6]);
   out_976225617616189007[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/state[4] + 1;
   out_976225617616189007[51] = dt*((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4]);
   out_976225617616189007[52] = dt*stiffness_front*state[0]/state[1];
   out_976225617616189007[53] = -9.8100000000000005*dt;
   out_976225617616189007[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_976225617616189007[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_976225617616189007[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_976225617616189007[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_976225617616189007[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_976225617616189007[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_976225617616189007[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_976225617616189007[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_976225617616189007[62] = 0;
   out_976225617616189007[63] = 0;
   out_976225617616189007[64] = 0;
   out_976225617616189007[65] = 0;
   out_976225617616189007[66] = 0;
   out_976225617616189007[67] = 0;
   out_976225617616189007[68] = 0;
   out_976225617616189007[69] = 0;
   out_976225617616189007[70] = 1;
   out_976225617616189007[71] = 0;
   out_976225617616189007[72] = 0;
   out_976225617616189007[73] = 0;
   out_976225617616189007[74] = 0;
   out_976225617616189007[75] = 0;
   out_976225617616189007[76] = 0;
   out_976225617616189007[77] = 0;
   out_976225617616189007[78] = 0;
   out_976225617616189007[79] = 0;
   out_976225617616189007[80] = 1;
}
void h_25(double *state, double *unused, double *out_5533497581884027539) {
   out_5533497581884027539[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1093348833608075871) {
   out_1093348833608075871[0] = 0;
   out_1093348833608075871[1] = 0;
   out_1093348833608075871[2] = 0;
   out_1093348833608075871[3] = 0;
   out_1093348833608075871[4] = 0;
   out_1093348833608075871[5] = 0;
   out_1093348833608075871[6] = 1;
   out_1093348833608075871[7] = 0;
   out_1093348833608075871[8] = 0;
}
void h_24(double *state, double *unused, double *out_3868635513509090583) {
   out_3868635513509090583[0] = state[4];
   out_3868635513509090583[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5482222972983442230) {
   out_5482222972983442230[0] = 0;
   out_5482222972983442230[1] = 0;
   out_5482222972983442230[2] = 0;
   out_5482222972983442230[3] = 0;
   out_5482222972983442230[4] = 1;
   out_5482222972983442230[5] = 0;
   out_5482222972983442230[6] = 0;
   out_5482222972983442230[7] = 0;
   out_5482222972983442230[8] = 0;
   out_5482222972983442230[9] = 0;
   out_5482222972983442230[10] = 0;
   out_5482222972983442230[11] = 0;
   out_5482222972983442230[12] = 0;
   out_5482222972983442230[13] = 0;
   out_5482222972983442230[14] = 1;
   out_5482222972983442230[15] = 0;
   out_5482222972983442230[16] = 0;
   out_5482222972983442230[17] = 0;
}
void h_30(double *state, double *unused, double *out_8481223572239512500) {
   out_8481223572239512500[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5823341507883540884) {
   out_5823341507883540884[0] = 0;
   out_5823341507883540884[1] = 0;
   out_5823341507883540884[2] = 0;
   out_5823341507883540884[3] = 0;
   out_5823341507883540884[4] = 1;
   out_5823341507883540884[5] = 0;
   out_5823341507883540884[6] = 0;
   out_5823341507883540884[7] = 0;
   out_5823341507883540884[8] = 0;
}
void h_26(double *state, double *unused, double *out_3479550304578666855) {
   out_3479550304578666855[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4834852152482132095) {
   out_4834852152482132095[0] = 0;
   out_4834852152482132095[1] = 0;
   out_4834852152482132095[2] = 0;
   out_4834852152482132095[3] = 0;
   out_4834852152482132095[4] = 0;
   out_4834852152482132095[5] = 0;
   out_4834852152482132095[6] = 0;
   out_4834852152482132095[7] = 1;
   out_4834852152482132095[8] = 0;
}
void h_27(double *state, double *unused, double *out_3448471590122813226) {
   out_3448471590122813226[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3648578196083115973) {
   out_3648578196083115973[0] = 0;
   out_3648578196083115973[1] = 0;
   out_3648578196083115973[2] = 0;
   out_3648578196083115973[3] = 1;
   out_3648578196083115973[4] = 0;
   out_3648578196083115973[5] = 0;
   out_3648578196083115973[6] = 0;
   out_3648578196083115973[7] = 0;
   out_3648578196083115973[8] = 0;
}
void h_29(double *state, double *unused, double *out_3173277527838307337) {
   out_3173277527838307337[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1935215469213564940) {
   out_1935215469213564940[0] = 0;
   out_1935215469213564940[1] = 1;
   out_1935215469213564940[2] = 0;
   out_1935215469213564940[3] = 0;
   out_1935215469213564940[4] = 0;
   out_1935215469213564940[5] = 0;
   out_1935215469213564940[6] = 0;
   out_1935215469213564940[7] = 0;
   out_1935215469213564940[8] = 0;
}
void h_28(double *state, double *unused, double *out_1553201677538032419) {
   out_1553201677538032419[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3147183547855965634) {
   out_3147183547855965634[0] = 1;
   out_3147183547855965634[1] = 0;
   out_3147183547855965634[2] = 0;
   out_3147183547855965634[3] = 0;
   out_3147183547855965634[4] = 0;
   out_3147183547855965634[5] = 0;
   out_3147183547855965634[6] = 0;
   out_3147183547855965634[7] = 0;
   out_3147183547855965634[8] = 0;
}
void h_31(double *state, double *unused, double *out_6359149687671870395) {
   out_6359149687671870395[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1062702871731115443) {
   out_1062702871731115443[0] = 0;
   out_1062702871731115443[1] = 0;
   out_1062702871731115443[2] = 0;
   out_1062702871731115443[3] = 0;
   out_1062702871731115443[4] = 0;
   out_1062702871731115443[5] = 0;
   out_1062702871731115443[6] = 0;
   out_1062702871731115443[7] = 0;
   out_1062702871731115443[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8357671443470322918) {
  err_fun(nom_x, delta_x, out_8357671443470322918);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1475244586979939250) {
  inv_err_fun(nom_x, true_x, out_1475244586979939250);
}
void car_H_mod_fun(double *state, double *out_5997040658792740711) {
  H_mod_fun(state, out_5997040658792740711);
}
void car_f_fun(double *state, double dt, double *out_2227498500027403860) {
  f_fun(state,  dt, out_2227498500027403860);
}
void car_F_fun(double *state, double dt, double *out_976225617616189007) {
  F_fun(state,  dt, out_976225617616189007);
}
void car_h_25(double *state, double *unused, double *out_5533497581884027539) {
  h_25(state, unused, out_5533497581884027539);
}
void car_H_25(double *state, double *unused, double *out_1093348833608075871) {
  H_25(state, unused, out_1093348833608075871);
}
void car_h_24(double *state, double *unused, double *out_3868635513509090583) {
  h_24(state, unused, out_3868635513509090583);
}
void car_H_24(double *state, double *unused, double *out_5482222972983442230) {
  H_24(state, unused, out_5482222972983442230);
}
void car_h_30(double *state, double *unused, double *out_8481223572239512500) {
  h_30(state, unused, out_8481223572239512500);
}
void car_H_30(double *state, double *unused, double *out_5823341507883540884) {
  H_30(state, unused, out_5823341507883540884);
}
void car_h_26(double *state, double *unused, double *out_3479550304578666855) {
  h_26(state, unused, out_3479550304578666855);
}
void car_H_26(double *state, double *unused, double *out_4834852152482132095) {
  H_26(state, unused, out_4834852152482132095);
}
void car_h_27(double *state, double *unused, double *out_3448471590122813226) {
  h_27(state, unused, out_3448471590122813226);
}
void car_H_27(double *state, double *unused, double *out_3648578196083115973) {
  H_27(state, unused, out_3648578196083115973);
}
void car_h_29(double *state, double *unused, double *out_3173277527838307337) {
  h_29(state, unused, out_3173277527838307337);
}
void car_H_29(double *state, double *unused, double *out_1935215469213564940) {
  H_29(state, unused, out_1935215469213564940);
}
void car_h_28(double *state, double *unused, double *out_1553201677538032419) {
  h_28(state, unused, out_1553201677538032419);
}
void car_H_28(double *state, double *unused, double *out_3147183547855965634) {
  H_28(state, unused, out_3147183547855965634);
}
void car_h_31(double *state, double *unused, double *out_6359149687671870395) {
  h_31(state, unused, out_6359149687671870395);
}
void car_H_31(double *state, double *unused, double *out_1062702871731115443) {
  H_31(state, unused, out_1062702871731115443);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
