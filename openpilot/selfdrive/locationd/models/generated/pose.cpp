#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_998230528870208424) {
   out_998230528870208424[0] = delta_x[0] + nom_x[0];
   out_998230528870208424[1] = delta_x[1] + nom_x[1];
   out_998230528870208424[2] = delta_x[2] + nom_x[2];
   out_998230528870208424[3] = delta_x[3] + nom_x[3];
   out_998230528870208424[4] = delta_x[4] + nom_x[4];
   out_998230528870208424[5] = delta_x[5] + nom_x[5];
   out_998230528870208424[6] = delta_x[6] + nom_x[6];
   out_998230528870208424[7] = delta_x[7] + nom_x[7];
   out_998230528870208424[8] = delta_x[8] + nom_x[8];
   out_998230528870208424[9] = delta_x[9] + nom_x[9];
   out_998230528870208424[10] = delta_x[10] + nom_x[10];
   out_998230528870208424[11] = delta_x[11] + nom_x[11];
   out_998230528870208424[12] = delta_x[12] + nom_x[12];
   out_998230528870208424[13] = delta_x[13] + nom_x[13];
   out_998230528870208424[14] = delta_x[14] + nom_x[14];
   out_998230528870208424[15] = delta_x[15] + nom_x[15];
   out_998230528870208424[16] = delta_x[16] + nom_x[16];
   out_998230528870208424[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3012158639090115677) {
   out_3012158639090115677[0] = -nom_x[0] + true_x[0];
   out_3012158639090115677[1] = -nom_x[1] + true_x[1];
   out_3012158639090115677[2] = -nom_x[2] + true_x[2];
   out_3012158639090115677[3] = -nom_x[3] + true_x[3];
   out_3012158639090115677[4] = -nom_x[4] + true_x[4];
   out_3012158639090115677[5] = -nom_x[5] + true_x[5];
   out_3012158639090115677[6] = -nom_x[6] + true_x[6];
   out_3012158639090115677[7] = -nom_x[7] + true_x[7];
   out_3012158639090115677[8] = -nom_x[8] + true_x[8];
   out_3012158639090115677[9] = -nom_x[9] + true_x[9];
   out_3012158639090115677[10] = -nom_x[10] + true_x[10];
   out_3012158639090115677[11] = -nom_x[11] + true_x[11];
   out_3012158639090115677[12] = -nom_x[12] + true_x[12];
   out_3012158639090115677[13] = -nom_x[13] + true_x[13];
   out_3012158639090115677[14] = -nom_x[14] + true_x[14];
   out_3012158639090115677[15] = -nom_x[15] + true_x[15];
   out_3012158639090115677[16] = -nom_x[16] + true_x[16];
   out_3012158639090115677[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4279409851358741827) {
   out_4279409851358741827[0] = 1.0;
   out_4279409851358741827[1] = 0.0;
   out_4279409851358741827[2] = 0.0;
   out_4279409851358741827[3] = 0.0;
   out_4279409851358741827[4] = 0.0;
   out_4279409851358741827[5] = 0.0;
   out_4279409851358741827[6] = 0.0;
   out_4279409851358741827[7] = 0.0;
   out_4279409851358741827[8] = 0.0;
   out_4279409851358741827[9] = 0.0;
   out_4279409851358741827[10] = 0.0;
   out_4279409851358741827[11] = 0.0;
   out_4279409851358741827[12] = 0.0;
   out_4279409851358741827[13] = 0.0;
   out_4279409851358741827[14] = 0.0;
   out_4279409851358741827[15] = 0.0;
   out_4279409851358741827[16] = 0.0;
   out_4279409851358741827[17] = 0.0;
   out_4279409851358741827[18] = 0.0;
   out_4279409851358741827[19] = 1.0;
   out_4279409851358741827[20] = 0.0;
   out_4279409851358741827[21] = 0.0;
   out_4279409851358741827[22] = 0.0;
   out_4279409851358741827[23] = 0.0;
   out_4279409851358741827[24] = 0.0;
   out_4279409851358741827[25] = 0.0;
   out_4279409851358741827[26] = 0.0;
   out_4279409851358741827[27] = 0.0;
   out_4279409851358741827[28] = 0.0;
   out_4279409851358741827[29] = 0.0;
   out_4279409851358741827[30] = 0.0;
   out_4279409851358741827[31] = 0.0;
   out_4279409851358741827[32] = 0.0;
   out_4279409851358741827[33] = 0.0;
   out_4279409851358741827[34] = 0.0;
   out_4279409851358741827[35] = 0.0;
   out_4279409851358741827[36] = 0.0;
   out_4279409851358741827[37] = 0.0;
   out_4279409851358741827[38] = 1.0;
   out_4279409851358741827[39] = 0.0;
   out_4279409851358741827[40] = 0.0;
   out_4279409851358741827[41] = 0.0;
   out_4279409851358741827[42] = 0.0;
   out_4279409851358741827[43] = 0.0;
   out_4279409851358741827[44] = 0.0;
   out_4279409851358741827[45] = 0.0;
   out_4279409851358741827[46] = 0.0;
   out_4279409851358741827[47] = 0.0;
   out_4279409851358741827[48] = 0.0;
   out_4279409851358741827[49] = 0.0;
   out_4279409851358741827[50] = 0.0;
   out_4279409851358741827[51] = 0.0;
   out_4279409851358741827[52] = 0.0;
   out_4279409851358741827[53] = 0.0;
   out_4279409851358741827[54] = 0.0;
   out_4279409851358741827[55] = 0.0;
   out_4279409851358741827[56] = 0.0;
   out_4279409851358741827[57] = 1.0;
   out_4279409851358741827[58] = 0.0;
   out_4279409851358741827[59] = 0.0;
   out_4279409851358741827[60] = 0.0;
   out_4279409851358741827[61] = 0.0;
   out_4279409851358741827[62] = 0.0;
   out_4279409851358741827[63] = 0.0;
   out_4279409851358741827[64] = 0.0;
   out_4279409851358741827[65] = 0.0;
   out_4279409851358741827[66] = 0.0;
   out_4279409851358741827[67] = 0.0;
   out_4279409851358741827[68] = 0.0;
   out_4279409851358741827[69] = 0.0;
   out_4279409851358741827[70] = 0.0;
   out_4279409851358741827[71] = 0.0;
   out_4279409851358741827[72] = 0.0;
   out_4279409851358741827[73] = 0.0;
   out_4279409851358741827[74] = 0.0;
   out_4279409851358741827[75] = 0.0;
   out_4279409851358741827[76] = 1.0;
   out_4279409851358741827[77] = 0.0;
   out_4279409851358741827[78] = 0.0;
   out_4279409851358741827[79] = 0.0;
   out_4279409851358741827[80] = 0.0;
   out_4279409851358741827[81] = 0.0;
   out_4279409851358741827[82] = 0.0;
   out_4279409851358741827[83] = 0.0;
   out_4279409851358741827[84] = 0.0;
   out_4279409851358741827[85] = 0.0;
   out_4279409851358741827[86] = 0.0;
   out_4279409851358741827[87] = 0.0;
   out_4279409851358741827[88] = 0.0;
   out_4279409851358741827[89] = 0.0;
   out_4279409851358741827[90] = 0.0;
   out_4279409851358741827[91] = 0.0;
   out_4279409851358741827[92] = 0.0;
   out_4279409851358741827[93] = 0.0;
   out_4279409851358741827[94] = 0.0;
   out_4279409851358741827[95] = 1.0;
   out_4279409851358741827[96] = 0.0;
   out_4279409851358741827[97] = 0.0;
   out_4279409851358741827[98] = 0.0;
   out_4279409851358741827[99] = 0.0;
   out_4279409851358741827[100] = 0.0;
   out_4279409851358741827[101] = 0.0;
   out_4279409851358741827[102] = 0.0;
   out_4279409851358741827[103] = 0.0;
   out_4279409851358741827[104] = 0.0;
   out_4279409851358741827[105] = 0.0;
   out_4279409851358741827[106] = 0.0;
   out_4279409851358741827[107] = 0.0;
   out_4279409851358741827[108] = 0.0;
   out_4279409851358741827[109] = 0.0;
   out_4279409851358741827[110] = 0.0;
   out_4279409851358741827[111] = 0.0;
   out_4279409851358741827[112] = 0.0;
   out_4279409851358741827[113] = 0.0;
   out_4279409851358741827[114] = 1.0;
   out_4279409851358741827[115] = 0.0;
   out_4279409851358741827[116] = 0.0;
   out_4279409851358741827[117] = 0.0;
   out_4279409851358741827[118] = 0.0;
   out_4279409851358741827[119] = 0.0;
   out_4279409851358741827[120] = 0.0;
   out_4279409851358741827[121] = 0.0;
   out_4279409851358741827[122] = 0.0;
   out_4279409851358741827[123] = 0.0;
   out_4279409851358741827[124] = 0.0;
   out_4279409851358741827[125] = 0.0;
   out_4279409851358741827[126] = 0.0;
   out_4279409851358741827[127] = 0.0;
   out_4279409851358741827[128] = 0.0;
   out_4279409851358741827[129] = 0.0;
   out_4279409851358741827[130] = 0.0;
   out_4279409851358741827[131] = 0.0;
   out_4279409851358741827[132] = 0.0;
   out_4279409851358741827[133] = 1.0;
   out_4279409851358741827[134] = 0.0;
   out_4279409851358741827[135] = 0.0;
   out_4279409851358741827[136] = 0.0;
   out_4279409851358741827[137] = 0.0;
   out_4279409851358741827[138] = 0.0;
   out_4279409851358741827[139] = 0.0;
   out_4279409851358741827[140] = 0.0;
   out_4279409851358741827[141] = 0.0;
   out_4279409851358741827[142] = 0.0;
   out_4279409851358741827[143] = 0.0;
   out_4279409851358741827[144] = 0.0;
   out_4279409851358741827[145] = 0.0;
   out_4279409851358741827[146] = 0.0;
   out_4279409851358741827[147] = 0.0;
   out_4279409851358741827[148] = 0.0;
   out_4279409851358741827[149] = 0.0;
   out_4279409851358741827[150] = 0.0;
   out_4279409851358741827[151] = 0.0;
   out_4279409851358741827[152] = 1.0;
   out_4279409851358741827[153] = 0.0;
   out_4279409851358741827[154] = 0.0;
   out_4279409851358741827[155] = 0.0;
   out_4279409851358741827[156] = 0.0;
   out_4279409851358741827[157] = 0.0;
   out_4279409851358741827[158] = 0.0;
   out_4279409851358741827[159] = 0.0;
   out_4279409851358741827[160] = 0.0;
   out_4279409851358741827[161] = 0.0;
   out_4279409851358741827[162] = 0.0;
   out_4279409851358741827[163] = 0.0;
   out_4279409851358741827[164] = 0.0;
   out_4279409851358741827[165] = 0.0;
   out_4279409851358741827[166] = 0.0;
   out_4279409851358741827[167] = 0.0;
   out_4279409851358741827[168] = 0.0;
   out_4279409851358741827[169] = 0.0;
   out_4279409851358741827[170] = 0.0;
   out_4279409851358741827[171] = 1.0;
   out_4279409851358741827[172] = 0.0;
   out_4279409851358741827[173] = 0.0;
   out_4279409851358741827[174] = 0.0;
   out_4279409851358741827[175] = 0.0;
   out_4279409851358741827[176] = 0.0;
   out_4279409851358741827[177] = 0.0;
   out_4279409851358741827[178] = 0.0;
   out_4279409851358741827[179] = 0.0;
   out_4279409851358741827[180] = 0.0;
   out_4279409851358741827[181] = 0.0;
   out_4279409851358741827[182] = 0.0;
   out_4279409851358741827[183] = 0.0;
   out_4279409851358741827[184] = 0.0;
   out_4279409851358741827[185] = 0.0;
   out_4279409851358741827[186] = 0.0;
   out_4279409851358741827[187] = 0.0;
   out_4279409851358741827[188] = 0.0;
   out_4279409851358741827[189] = 0.0;
   out_4279409851358741827[190] = 1.0;
   out_4279409851358741827[191] = 0.0;
   out_4279409851358741827[192] = 0.0;
   out_4279409851358741827[193] = 0.0;
   out_4279409851358741827[194] = 0.0;
   out_4279409851358741827[195] = 0.0;
   out_4279409851358741827[196] = 0.0;
   out_4279409851358741827[197] = 0.0;
   out_4279409851358741827[198] = 0.0;
   out_4279409851358741827[199] = 0.0;
   out_4279409851358741827[200] = 0.0;
   out_4279409851358741827[201] = 0.0;
   out_4279409851358741827[202] = 0.0;
   out_4279409851358741827[203] = 0.0;
   out_4279409851358741827[204] = 0.0;
   out_4279409851358741827[205] = 0.0;
   out_4279409851358741827[206] = 0.0;
   out_4279409851358741827[207] = 0.0;
   out_4279409851358741827[208] = 0.0;
   out_4279409851358741827[209] = 1.0;
   out_4279409851358741827[210] = 0.0;
   out_4279409851358741827[211] = 0.0;
   out_4279409851358741827[212] = 0.0;
   out_4279409851358741827[213] = 0.0;
   out_4279409851358741827[214] = 0.0;
   out_4279409851358741827[215] = 0.0;
   out_4279409851358741827[216] = 0.0;
   out_4279409851358741827[217] = 0.0;
   out_4279409851358741827[218] = 0.0;
   out_4279409851358741827[219] = 0.0;
   out_4279409851358741827[220] = 0.0;
   out_4279409851358741827[221] = 0.0;
   out_4279409851358741827[222] = 0.0;
   out_4279409851358741827[223] = 0.0;
   out_4279409851358741827[224] = 0.0;
   out_4279409851358741827[225] = 0.0;
   out_4279409851358741827[226] = 0.0;
   out_4279409851358741827[227] = 0.0;
   out_4279409851358741827[228] = 1.0;
   out_4279409851358741827[229] = 0.0;
   out_4279409851358741827[230] = 0.0;
   out_4279409851358741827[231] = 0.0;
   out_4279409851358741827[232] = 0.0;
   out_4279409851358741827[233] = 0.0;
   out_4279409851358741827[234] = 0.0;
   out_4279409851358741827[235] = 0.0;
   out_4279409851358741827[236] = 0.0;
   out_4279409851358741827[237] = 0.0;
   out_4279409851358741827[238] = 0.0;
   out_4279409851358741827[239] = 0.0;
   out_4279409851358741827[240] = 0.0;
   out_4279409851358741827[241] = 0.0;
   out_4279409851358741827[242] = 0.0;
   out_4279409851358741827[243] = 0.0;
   out_4279409851358741827[244] = 0.0;
   out_4279409851358741827[245] = 0.0;
   out_4279409851358741827[246] = 0.0;
   out_4279409851358741827[247] = 1.0;
   out_4279409851358741827[248] = 0.0;
   out_4279409851358741827[249] = 0.0;
   out_4279409851358741827[250] = 0.0;
   out_4279409851358741827[251] = 0.0;
   out_4279409851358741827[252] = 0.0;
   out_4279409851358741827[253] = 0.0;
   out_4279409851358741827[254] = 0.0;
   out_4279409851358741827[255] = 0.0;
   out_4279409851358741827[256] = 0.0;
   out_4279409851358741827[257] = 0.0;
   out_4279409851358741827[258] = 0.0;
   out_4279409851358741827[259] = 0.0;
   out_4279409851358741827[260] = 0.0;
   out_4279409851358741827[261] = 0.0;
   out_4279409851358741827[262] = 0.0;
   out_4279409851358741827[263] = 0.0;
   out_4279409851358741827[264] = 0.0;
   out_4279409851358741827[265] = 0.0;
   out_4279409851358741827[266] = 1.0;
   out_4279409851358741827[267] = 0.0;
   out_4279409851358741827[268] = 0.0;
   out_4279409851358741827[269] = 0.0;
   out_4279409851358741827[270] = 0.0;
   out_4279409851358741827[271] = 0.0;
   out_4279409851358741827[272] = 0.0;
   out_4279409851358741827[273] = 0.0;
   out_4279409851358741827[274] = 0.0;
   out_4279409851358741827[275] = 0.0;
   out_4279409851358741827[276] = 0.0;
   out_4279409851358741827[277] = 0.0;
   out_4279409851358741827[278] = 0.0;
   out_4279409851358741827[279] = 0.0;
   out_4279409851358741827[280] = 0.0;
   out_4279409851358741827[281] = 0.0;
   out_4279409851358741827[282] = 0.0;
   out_4279409851358741827[283] = 0.0;
   out_4279409851358741827[284] = 0.0;
   out_4279409851358741827[285] = 1.0;
   out_4279409851358741827[286] = 0.0;
   out_4279409851358741827[287] = 0.0;
   out_4279409851358741827[288] = 0.0;
   out_4279409851358741827[289] = 0.0;
   out_4279409851358741827[290] = 0.0;
   out_4279409851358741827[291] = 0.0;
   out_4279409851358741827[292] = 0.0;
   out_4279409851358741827[293] = 0.0;
   out_4279409851358741827[294] = 0.0;
   out_4279409851358741827[295] = 0.0;
   out_4279409851358741827[296] = 0.0;
   out_4279409851358741827[297] = 0.0;
   out_4279409851358741827[298] = 0.0;
   out_4279409851358741827[299] = 0.0;
   out_4279409851358741827[300] = 0.0;
   out_4279409851358741827[301] = 0.0;
   out_4279409851358741827[302] = 0.0;
   out_4279409851358741827[303] = 0.0;
   out_4279409851358741827[304] = 1.0;
   out_4279409851358741827[305] = 0.0;
   out_4279409851358741827[306] = 0.0;
   out_4279409851358741827[307] = 0.0;
   out_4279409851358741827[308] = 0.0;
   out_4279409851358741827[309] = 0.0;
   out_4279409851358741827[310] = 0.0;
   out_4279409851358741827[311] = 0.0;
   out_4279409851358741827[312] = 0.0;
   out_4279409851358741827[313] = 0.0;
   out_4279409851358741827[314] = 0.0;
   out_4279409851358741827[315] = 0.0;
   out_4279409851358741827[316] = 0.0;
   out_4279409851358741827[317] = 0.0;
   out_4279409851358741827[318] = 0.0;
   out_4279409851358741827[319] = 0.0;
   out_4279409851358741827[320] = 0.0;
   out_4279409851358741827[321] = 0.0;
   out_4279409851358741827[322] = 0.0;
   out_4279409851358741827[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2258497738805810057) {
   out_2258497738805810057[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2258497738805810057[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2258497738805810057[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2258497738805810057[3] = dt*state[12] + state[3];
   out_2258497738805810057[4] = dt*state[13] + state[4];
   out_2258497738805810057[5] = dt*state[14] + state[5];
   out_2258497738805810057[6] = state[6];
   out_2258497738805810057[7] = state[7];
   out_2258497738805810057[8] = state[8];
   out_2258497738805810057[9] = state[9];
   out_2258497738805810057[10] = state[10];
   out_2258497738805810057[11] = state[11];
   out_2258497738805810057[12] = state[12];
   out_2258497738805810057[13] = state[13];
   out_2258497738805810057[14] = state[14];
   out_2258497738805810057[15] = state[15];
   out_2258497738805810057[16] = state[16];
   out_2258497738805810057[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2761687256171107949) {
   out_2761687256171107949[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2761687256171107949[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2761687256171107949[2] = 0;
   out_2761687256171107949[3] = 0;
   out_2761687256171107949[4] = 0;
   out_2761687256171107949[5] = 0;
   out_2761687256171107949[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2761687256171107949[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2761687256171107949[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2761687256171107949[9] = 0;
   out_2761687256171107949[10] = 0;
   out_2761687256171107949[11] = 0;
   out_2761687256171107949[12] = 0;
   out_2761687256171107949[13] = 0;
   out_2761687256171107949[14] = 0;
   out_2761687256171107949[15] = 0;
   out_2761687256171107949[16] = 0;
   out_2761687256171107949[17] = 0;
   out_2761687256171107949[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2761687256171107949[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2761687256171107949[20] = 0;
   out_2761687256171107949[21] = 0;
   out_2761687256171107949[22] = 0;
   out_2761687256171107949[23] = 0;
   out_2761687256171107949[24] = 0;
   out_2761687256171107949[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2761687256171107949[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2761687256171107949[27] = 0;
   out_2761687256171107949[28] = 0;
   out_2761687256171107949[29] = 0;
   out_2761687256171107949[30] = 0;
   out_2761687256171107949[31] = 0;
   out_2761687256171107949[32] = 0;
   out_2761687256171107949[33] = 0;
   out_2761687256171107949[34] = 0;
   out_2761687256171107949[35] = 0;
   out_2761687256171107949[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2761687256171107949[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2761687256171107949[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2761687256171107949[39] = 0;
   out_2761687256171107949[40] = 0;
   out_2761687256171107949[41] = 0;
   out_2761687256171107949[42] = 0;
   out_2761687256171107949[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2761687256171107949[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2761687256171107949[45] = 0;
   out_2761687256171107949[46] = 0;
   out_2761687256171107949[47] = 0;
   out_2761687256171107949[48] = 0;
   out_2761687256171107949[49] = 0;
   out_2761687256171107949[50] = 0;
   out_2761687256171107949[51] = 0;
   out_2761687256171107949[52] = 0;
   out_2761687256171107949[53] = 0;
   out_2761687256171107949[54] = 0;
   out_2761687256171107949[55] = 0;
   out_2761687256171107949[56] = 0;
   out_2761687256171107949[57] = 1;
   out_2761687256171107949[58] = 0;
   out_2761687256171107949[59] = 0;
   out_2761687256171107949[60] = 0;
   out_2761687256171107949[61] = 0;
   out_2761687256171107949[62] = 0;
   out_2761687256171107949[63] = 0;
   out_2761687256171107949[64] = 0;
   out_2761687256171107949[65] = 0;
   out_2761687256171107949[66] = dt;
   out_2761687256171107949[67] = 0;
   out_2761687256171107949[68] = 0;
   out_2761687256171107949[69] = 0;
   out_2761687256171107949[70] = 0;
   out_2761687256171107949[71] = 0;
   out_2761687256171107949[72] = 0;
   out_2761687256171107949[73] = 0;
   out_2761687256171107949[74] = 0;
   out_2761687256171107949[75] = 0;
   out_2761687256171107949[76] = 1;
   out_2761687256171107949[77] = 0;
   out_2761687256171107949[78] = 0;
   out_2761687256171107949[79] = 0;
   out_2761687256171107949[80] = 0;
   out_2761687256171107949[81] = 0;
   out_2761687256171107949[82] = 0;
   out_2761687256171107949[83] = 0;
   out_2761687256171107949[84] = 0;
   out_2761687256171107949[85] = dt;
   out_2761687256171107949[86] = 0;
   out_2761687256171107949[87] = 0;
   out_2761687256171107949[88] = 0;
   out_2761687256171107949[89] = 0;
   out_2761687256171107949[90] = 0;
   out_2761687256171107949[91] = 0;
   out_2761687256171107949[92] = 0;
   out_2761687256171107949[93] = 0;
   out_2761687256171107949[94] = 0;
   out_2761687256171107949[95] = 1;
   out_2761687256171107949[96] = 0;
   out_2761687256171107949[97] = 0;
   out_2761687256171107949[98] = 0;
   out_2761687256171107949[99] = 0;
   out_2761687256171107949[100] = 0;
   out_2761687256171107949[101] = 0;
   out_2761687256171107949[102] = 0;
   out_2761687256171107949[103] = 0;
   out_2761687256171107949[104] = dt;
   out_2761687256171107949[105] = 0;
   out_2761687256171107949[106] = 0;
   out_2761687256171107949[107] = 0;
   out_2761687256171107949[108] = 0;
   out_2761687256171107949[109] = 0;
   out_2761687256171107949[110] = 0;
   out_2761687256171107949[111] = 0;
   out_2761687256171107949[112] = 0;
   out_2761687256171107949[113] = 0;
   out_2761687256171107949[114] = 1;
   out_2761687256171107949[115] = 0;
   out_2761687256171107949[116] = 0;
   out_2761687256171107949[117] = 0;
   out_2761687256171107949[118] = 0;
   out_2761687256171107949[119] = 0;
   out_2761687256171107949[120] = 0;
   out_2761687256171107949[121] = 0;
   out_2761687256171107949[122] = 0;
   out_2761687256171107949[123] = 0;
   out_2761687256171107949[124] = 0;
   out_2761687256171107949[125] = 0;
   out_2761687256171107949[126] = 0;
   out_2761687256171107949[127] = 0;
   out_2761687256171107949[128] = 0;
   out_2761687256171107949[129] = 0;
   out_2761687256171107949[130] = 0;
   out_2761687256171107949[131] = 0;
   out_2761687256171107949[132] = 0;
   out_2761687256171107949[133] = 1;
   out_2761687256171107949[134] = 0;
   out_2761687256171107949[135] = 0;
   out_2761687256171107949[136] = 0;
   out_2761687256171107949[137] = 0;
   out_2761687256171107949[138] = 0;
   out_2761687256171107949[139] = 0;
   out_2761687256171107949[140] = 0;
   out_2761687256171107949[141] = 0;
   out_2761687256171107949[142] = 0;
   out_2761687256171107949[143] = 0;
   out_2761687256171107949[144] = 0;
   out_2761687256171107949[145] = 0;
   out_2761687256171107949[146] = 0;
   out_2761687256171107949[147] = 0;
   out_2761687256171107949[148] = 0;
   out_2761687256171107949[149] = 0;
   out_2761687256171107949[150] = 0;
   out_2761687256171107949[151] = 0;
   out_2761687256171107949[152] = 1;
   out_2761687256171107949[153] = 0;
   out_2761687256171107949[154] = 0;
   out_2761687256171107949[155] = 0;
   out_2761687256171107949[156] = 0;
   out_2761687256171107949[157] = 0;
   out_2761687256171107949[158] = 0;
   out_2761687256171107949[159] = 0;
   out_2761687256171107949[160] = 0;
   out_2761687256171107949[161] = 0;
   out_2761687256171107949[162] = 0;
   out_2761687256171107949[163] = 0;
   out_2761687256171107949[164] = 0;
   out_2761687256171107949[165] = 0;
   out_2761687256171107949[166] = 0;
   out_2761687256171107949[167] = 0;
   out_2761687256171107949[168] = 0;
   out_2761687256171107949[169] = 0;
   out_2761687256171107949[170] = 0;
   out_2761687256171107949[171] = 1;
   out_2761687256171107949[172] = 0;
   out_2761687256171107949[173] = 0;
   out_2761687256171107949[174] = 0;
   out_2761687256171107949[175] = 0;
   out_2761687256171107949[176] = 0;
   out_2761687256171107949[177] = 0;
   out_2761687256171107949[178] = 0;
   out_2761687256171107949[179] = 0;
   out_2761687256171107949[180] = 0;
   out_2761687256171107949[181] = 0;
   out_2761687256171107949[182] = 0;
   out_2761687256171107949[183] = 0;
   out_2761687256171107949[184] = 0;
   out_2761687256171107949[185] = 0;
   out_2761687256171107949[186] = 0;
   out_2761687256171107949[187] = 0;
   out_2761687256171107949[188] = 0;
   out_2761687256171107949[189] = 0;
   out_2761687256171107949[190] = 1;
   out_2761687256171107949[191] = 0;
   out_2761687256171107949[192] = 0;
   out_2761687256171107949[193] = 0;
   out_2761687256171107949[194] = 0;
   out_2761687256171107949[195] = 0;
   out_2761687256171107949[196] = 0;
   out_2761687256171107949[197] = 0;
   out_2761687256171107949[198] = 0;
   out_2761687256171107949[199] = 0;
   out_2761687256171107949[200] = 0;
   out_2761687256171107949[201] = 0;
   out_2761687256171107949[202] = 0;
   out_2761687256171107949[203] = 0;
   out_2761687256171107949[204] = 0;
   out_2761687256171107949[205] = 0;
   out_2761687256171107949[206] = 0;
   out_2761687256171107949[207] = 0;
   out_2761687256171107949[208] = 0;
   out_2761687256171107949[209] = 1;
   out_2761687256171107949[210] = 0;
   out_2761687256171107949[211] = 0;
   out_2761687256171107949[212] = 0;
   out_2761687256171107949[213] = 0;
   out_2761687256171107949[214] = 0;
   out_2761687256171107949[215] = 0;
   out_2761687256171107949[216] = 0;
   out_2761687256171107949[217] = 0;
   out_2761687256171107949[218] = 0;
   out_2761687256171107949[219] = 0;
   out_2761687256171107949[220] = 0;
   out_2761687256171107949[221] = 0;
   out_2761687256171107949[222] = 0;
   out_2761687256171107949[223] = 0;
   out_2761687256171107949[224] = 0;
   out_2761687256171107949[225] = 0;
   out_2761687256171107949[226] = 0;
   out_2761687256171107949[227] = 0;
   out_2761687256171107949[228] = 1;
   out_2761687256171107949[229] = 0;
   out_2761687256171107949[230] = 0;
   out_2761687256171107949[231] = 0;
   out_2761687256171107949[232] = 0;
   out_2761687256171107949[233] = 0;
   out_2761687256171107949[234] = 0;
   out_2761687256171107949[235] = 0;
   out_2761687256171107949[236] = 0;
   out_2761687256171107949[237] = 0;
   out_2761687256171107949[238] = 0;
   out_2761687256171107949[239] = 0;
   out_2761687256171107949[240] = 0;
   out_2761687256171107949[241] = 0;
   out_2761687256171107949[242] = 0;
   out_2761687256171107949[243] = 0;
   out_2761687256171107949[244] = 0;
   out_2761687256171107949[245] = 0;
   out_2761687256171107949[246] = 0;
   out_2761687256171107949[247] = 1;
   out_2761687256171107949[248] = 0;
   out_2761687256171107949[249] = 0;
   out_2761687256171107949[250] = 0;
   out_2761687256171107949[251] = 0;
   out_2761687256171107949[252] = 0;
   out_2761687256171107949[253] = 0;
   out_2761687256171107949[254] = 0;
   out_2761687256171107949[255] = 0;
   out_2761687256171107949[256] = 0;
   out_2761687256171107949[257] = 0;
   out_2761687256171107949[258] = 0;
   out_2761687256171107949[259] = 0;
   out_2761687256171107949[260] = 0;
   out_2761687256171107949[261] = 0;
   out_2761687256171107949[262] = 0;
   out_2761687256171107949[263] = 0;
   out_2761687256171107949[264] = 0;
   out_2761687256171107949[265] = 0;
   out_2761687256171107949[266] = 1;
   out_2761687256171107949[267] = 0;
   out_2761687256171107949[268] = 0;
   out_2761687256171107949[269] = 0;
   out_2761687256171107949[270] = 0;
   out_2761687256171107949[271] = 0;
   out_2761687256171107949[272] = 0;
   out_2761687256171107949[273] = 0;
   out_2761687256171107949[274] = 0;
   out_2761687256171107949[275] = 0;
   out_2761687256171107949[276] = 0;
   out_2761687256171107949[277] = 0;
   out_2761687256171107949[278] = 0;
   out_2761687256171107949[279] = 0;
   out_2761687256171107949[280] = 0;
   out_2761687256171107949[281] = 0;
   out_2761687256171107949[282] = 0;
   out_2761687256171107949[283] = 0;
   out_2761687256171107949[284] = 0;
   out_2761687256171107949[285] = 1;
   out_2761687256171107949[286] = 0;
   out_2761687256171107949[287] = 0;
   out_2761687256171107949[288] = 0;
   out_2761687256171107949[289] = 0;
   out_2761687256171107949[290] = 0;
   out_2761687256171107949[291] = 0;
   out_2761687256171107949[292] = 0;
   out_2761687256171107949[293] = 0;
   out_2761687256171107949[294] = 0;
   out_2761687256171107949[295] = 0;
   out_2761687256171107949[296] = 0;
   out_2761687256171107949[297] = 0;
   out_2761687256171107949[298] = 0;
   out_2761687256171107949[299] = 0;
   out_2761687256171107949[300] = 0;
   out_2761687256171107949[301] = 0;
   out_2761687256171107949[302] = 0;
   out_2761687256171107949[303] = 0;
   out_2761687256171107949[304] = 1;
   out_2761687256171107949[305] = 0;
   out_2761687256171107949[306] = 0;
   out_2761687256171107949[307] = 0;
   out_2761687256171107949[308] = 0;
   out_2761687256171107949[309] = 0;
   out_2761687256171107949[310] = 0;
   out_2761687256171107949[311] = 0;
   out_2761687256171107949[312] = 0;
   out_2761687256171107949[313] = 0;
   out_2761687256171107949[314] = 0;
   out_2761687256171107949[315] = 0;
   out_2761687256171107949[316] = 0;
   out_2761687256171107949[317] = 0;
   out_2761687256171107949[318] = 0;
   out_2761687256171107949[319] = 0;
   out_2761687256171107949[320] = 0;
   out_2761687256171107949[321] = 0;
   out_2761687256171107949[322] = 0;
   out_2761687256171107949[323] = 1;
}
void h_4(double *state, double *unused, double *out_6883854925923645053) {
   out_6883854925923645053[0] = state[6] + state[9];
   out_6883854925923645053[1] = state[7] + state[10];
   out_6883854925923645053[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6941928404350447480) {
   out_6941928404350447480[0] = 0;
   out_6941928404350447480[1] = 0;
   out_6941928404350447480[2] = 0;
   out_6941928404350447480[3] = 0;
   out_6941928404350447480[4] = 0;
   out_6941928404350447480[5] = 0;
   out_6941928404350447480[6] = 1;
   out_6941928404350447480[7] = 0;
   out_6941928404350447480[8] = 0;
   out_6941928404350447480[9] = 1;
   out_6941928404350447480[10] = 0;
   out_6941928404350447480[11] = 0;
   out_6941928404350447480[12] = 0;
   out_6941928404350447480[13] = 0;
   out_6941928404350447480[14] = 0;
   out_6941928404350447480[15] = 0;
   out_6941928404350447480[16] = 0;
   out_6941928404350447480[17] = 0;
   out_6941928404350447480[18] = 0;
   out_6941928404350447480[19] = 0;
   out_6941928404350447480[20] = 0;
   out_6941928404350447480[21] = 0;
   out_6941928404350447480[22] = 0;
   out_6941928404350447480[23] = 0;
   out_6941928404350447480[24] = 0;
   out_6941928404350447480[25] = 1;
   out_6941928404350447480[26] = 0;
   out_6941928404350447480[27] = 0;
   out_6941928404350447480[28] = 1;
   out_6941928404350447480[29] = 0;
   out_6941928404350447480[30] = 0;
   out_6941928404350447480[31] = 0;
   out_6941928404350447480[32] = 0;
   out_6941928404350447480[33] = 0;
   out_6941928404350447480[34] = 0;
   out_6941928404350447480[35] = 0;
   out_6941928404350447480[36] = 0;
   out_6941928404350447480[37] = 0;
   out_6941928404350447480[38] = 0;
   out_6941928404350447480[39] = 0;
   out_6941928404350447480[40] = 0;
   out_6941928404350447480[41] = 0;
   out_6941928404350447480[42] = 0;
   out_6941928404350447480[43] = 0;
   out_6941928404350447480[44] = 1;
   out_6941928404350447480[45] = 0;
   out_6941928404350447480[46] = 0;
   out_6941928404350447480[47] = 1;
   out_6941928404350447480[48] = 0;
   out_6941928404350447480[49] = 0;
   out_6941928404350447480[50] = 0;
   out_6941928404350447480[51] = 0;
   out_6941928404350447480[52] = 0;
   out_6941928404350447480[53] = 0;
}
void h_10(double *state, double *unused, double *out_2421520088911358791) {
   out_2421520088911358791[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2421520088911358791[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2421520088911358791[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_767792537126218551) {
   out_767792537126218551[0] = 0;
   out_767792537126218551[1] = 9.8100000000000005*cos(state[1]);
   out_767792537126218551[2] = 0;
   out_767792537126218551[3] = 0;
   out_767792537126218551[4] = -state[8];
   out_767792537126218551[5] = state[7];
   out_767792537126218551[6] = 0;
   out_767792537126218551[7] = state[5];
   out_767792537126218551[8] = -state[4];
   out_767792537126218551[9] = 0;
   out_767792537126218551[10] = 0;
   out_767792537126218551[11] = 0;
   out_767792537126218551[12] = 1;
   out_767792537126218551[13] = 0;
   out_767792537126218551[14] = 0;
   out_767792537126218551[15] = 1;
   out_767792537126218551[16] = 0;
   out_767792537126218551[17] = 0;
   out_767792537126218551[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_767792537126218551[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_767792537126218551[20] = 0;
   out_767792537126218551[21] = state[8];
   out_767792537126218551[22] = 0;
   out_767792537126218551[23] = -state[6];
   out_767792537126218551[24] = -state[5];
   out_767792537126218551[25] = 0;
   out_767792537126218551[26] = state[3];
   out_767792537126218551[27] = 0;
   out_767792537126218551[28] = 0;
   out_767792537126218551[29] = 0;
   out_767792537126218551[30] = 0;
   out_767792537126218551[31] = 1;
   out_767792537126218551[32] = 0;
   out_767792537126218551[33] = 0;
   out_767792537126218551[34] = 1;
   out_767792537126218551[35] = 0;
   out_767792537126218551[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_767792537126218551[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_767792537126218551[38] = 0;
   out_767792537126218551[39] = -state[7];
   out_767792537126218551[40] = state[6];
   out_767792537126218551[41] = 0;
   out_767792537126218551[42] = state[4];
   out_767792537126218551[43] = -state[3];
   out_767792537126218551[44] = 0;
   out_767792537126218551[45] = 0;
   out_767792537126218551[46] = 0;
   out_767792537126218551[47] = 0;
   out_767792537126218551[48] = 0;
   out_767792537126218551[49] = 0;
   out_767792537126218551[50] = 1;
   out_767792537126218551[51] = 0;
   out_767792537126218551[52] = 0;
   out_767792537126218551[53] = 1;
}
void h_13(double *state, double *unused, double *out_4000631945198786439) {
   out_4000631945198786439[0] = state[3];
   out_4000631945198786439[1] = state[4];
   out_4000631945198786439[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7671060206056580112) {
   out_7671060206056580112[0] = 0;
   out_7671060206056580112[1] = 0;
   out_7671060206056580112[2] = 0;
   out_7671060206056580112[3] = 1;
   out_7671060206056580112[4] = 0;
   out_7671060206056580112[5] = 0;
   out_7671060206056580112[6] = 0;
   out_7671060206056580112[7] = 0;
   out_7671060206056580112[8] = 0;
   out_7671060206056580112[9] = 0;
   out_7671060206056580112[10] = 0;
   out_7671060206056580112[11] = 0;
   out_7671060206056580112[12] = 0;
   out_7671060206056580112[13] = 0;
   out_7671060206056580112[14] = 0;
   out_7671060206056580112[15] = 0;
   out_7671060206056580112[16] = 0;
   out_7671060206056580112[17] = 0;
   out_7671060206056580112[18] = 0;
   out_7671060206056580112[19] = 0;
   out_7671060206056580112[20] = 0;
   out_7671060206056580112[21] = 0;
   out_7671060206056580112[22] = 1;
   out_7671060206056580112[23] = 0;
   out_7671060206056580112[24] = 0;
   out_7671060206056580112[25] = 0;
   out_7671060206056580112[26] = 0;
   out_7671060206056580112[27] = 0;
   out_7671060206056580112[28] = 0;
   out_7671060206056580112[29] = 0;
   out_7671060206056580112[30] = 0;
   out_7671060206056580112[31] = 0;
   out_7671060206056580112[32] = 0;
   out_7671060206056580112[33] = 0;
   out_7671060206056580112[34] = 0;
   out_7671060206056580112[35] = 0;
   out_7671060206056580112[36] = 0;
   out_7671060206056580112[37] = 0;
   out_7671060206056580112[38] = 0;
   out_7671060206056580112[39] = 0;
   out_7671060206056580112[40] = 0;
   out_7671060206056580112[41] = 1;
   out_7671060206056580112[42] = 0;
   out_7671060206056580112[43] = 0;
   out_7671060206056580112[44] = 0;
   out_7671060206056580112[45] = 0;
   out_7671060206056580112[46] = 0;
   out_7671060206056580112[47] = 0;
   out_7671060206056580112[48] = 0;
   out_7671060206056580112[49] = 0;
   out_7671060206056580112[50] = 0;
   out_7671060206056580112[51] = 0;
   out_7671060206056580112[52] = 0;
   out_7671060206056580112[53] = 0;
}
void h_14(double *state, double *unused, double *out_1906502337268970664) {
   out_1906502337268970664[0] = state[6];
   out_1906502337268970664[1] = state[7];
   out_1906502337268970664[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4023669854079363712) {
   out_4023669854079363712[0] = 0;
   out_4023669854079363712[1] = 0;
   out_4023669854079363712[2] = 0;
   out_4023669854079363712[3] = 0;
   out_4023669854079363712[4] = 0;
   out_4023669854079363712[5] = 0;
   out_4023669854079363712[6] = 1;
   out_4023669854079363712[7] = 0;
   out_4023669854079363712[8] = 0;
   out_4023669854079363712[9] = 0;
   out_4023669854079363712[10] = 0;
   out_4023669854079363712[11] = 0;
   out_4023669854079363712[12] = 0;
   out_4023669854079363712[13] = 0;
   out_4023669854079363712[14] = 0;
   out_4023669854079363712[15] = 0;
   out_4023669854079363712[16] = 0;
   out_4023669854079363712[17] = 0;
   out_4023669854079363712[18] = 0;
   out_4023669854079363712[19] = 0;
   out_4023669854079363712[20] = 0;
   out_4023669854079363712[21] = 0;
   out_4023669854079363712[22] = 0;
   out_4023669854079363712[23] = 0;
   out_4023669854079363712[24] = 0;
   out_4023669854079363712[25] = 1;
   out_4023669854079363712[26] = 0;
   out_4023669854079363712[27] = 0;
   out_4023669854079363712[28] = 0;
   out_4023669854079363712[29] = 0;
   out_4023669854079363712[30] = 0;
   out_4023669854079363712[31] = 0;
   out_4023669854079363712[32] = 0;
   out_4023669854079363712[33] = 0;
   out_4023669854079363712[34] = 0;
   out_4023669854079363712[35] = 0;
   out_4023669854079363712[36] = 0;
   out_4023669854079363712[37] = 0;
   out_4023669854079363712[38] = 0;
   out_4023669854079363712[39] = 0;
   out_4023669854079363712[40] = 0;
   out_4023669854079363712[41] = 0;
   out_4023669854079363712[42] = 0;
   out_4023669854079363712[43] = 0;
   out_4023669854079363712[44] = 1;
   out_4023669854079363712[45] = 0;
   out_4023669854079363712[46] = 0;
   out_4023669854079363712[47] = 0;
   out_4023669854079363712[48] = 0;
   out_4023669854079363712[49] = 0;
   out_4023669854079363712[50] = 0;
   out_4023669854079363712[51] = 0;
   out_4023669854079363712[52] = 0;
   out_4023669854079363712[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_998230528870208424) {
  err_fun(nom_x, delta_x, out_998230528870208424);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3012158639090115677) {
  inv_err_fun(nom_x, true_x, out_3012158639090115677);
}
void pose_H_mod_fun(double *state, double *out_4279409851358741827) {
  H_mod_fun(state, out_4279409851358741827);
}
void pose_f_fun(double *state, double dt, double *out_2258497738805810057) {
  f_fun(state,  dt, out_2258497738805810057);
}
void pose_F_fun(double *state, double dt, double *out_2761687256171107949) {
  F_fun(state,  dt, out_2761687256171107949);
}
void pose_h_4(double *state, double *unused, double *out_6883854925923645053) {
  h_4(state, unused, out_6883854925923645053);
}
void pose_H_4(double *state, double *unused, double *out_6941928404350447480) {
  H_4(state, unused, out_6941928404350447480);
}
void pose_h_10(double *state, double *unused, double *out_2421520088911358791) {
  h_10(state, unused, out_2421520088911358791);
}
void pose_H_10(double *state, double *unused, double *out_767792537126218551) {
  H_10(state, unused, out_767792537126218551);
}
void pose_h_13(double *state, double *unused, double *out_4000631945198786439) {
  h_13(state, unused, out_4000631945198786439);
}
void pose_H_13(double *state, double *unused, double *out_7671060206056580112) {
  H_13(state, unused, out_7671060206056580112);
}
void pose_h_14(double *state, double *unused, double *out_1906502337268970664) {
  h_14(state, unused, out_1906502337268970664);
}
void pose_H_14(double *state, double *unused, double *out_4023669854079363712) {
  H_14(state, unused, out_4023669854079363712);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
