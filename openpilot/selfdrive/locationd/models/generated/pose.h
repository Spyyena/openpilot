#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_998230528870208424);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3012158639090115677);
void pose_H_mod_fun(double *state, double *out_4279409851358741827);
void pose_f_fun(double *state, double dt, double *out_2258497738805810057);
void pose_F_fun(double *state, double dt, double *out_2761687256171107949);
void pose_h_4(double *state, double *unused, double *out_6883854925923645053);
void pose_H_4(double *state, double *unused, double *out_6941928404350447480);
void pose_h_10(double *state, double *unused, double *out_2421520088911358791);
void pose_H_10(double *state, double *unused, double *out_767792537126218551);
void pose_h_13(double *state, double *unused, double *out_4000631945198786439);
void pose_H_13(double *state, double *unused, double *out_7671060206056580112);
void pose_h_14(double *state, double *unused, double *out_1906502337268970664);
void pose_H_14(double *state, double *unused, double *out_4023669854079363712);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}