  // @file tle.cc
  // @brief TLE elements resolver.
  // @author Mamoru Kaminaga
  // @date 2017-09-07 12:52:18
  // Copyright 2017 Mamoru Kaminaga
#include <assert.h>
#include <wchar.h>
#include <string>
#include "./tle.h"
#define S_MAX  (32)
bool ReadTLE(const InputTLE& input, OutputTLE* output) {
  assert(output);
  wchar_t buf_1[13][S_MAX] = {0};
  wchar_t buf_2[9][S_MAX] = {0};
  wchar_t tmp[S_MAX] = {0};
  // The line 0 is processed.
  output->name = input.line_0;
  // The line 1 is expanded.
  input.line_1.copy(buf_1[0], 1, 0);  // The line number (Always 1).
  input.line_1.copy(buf_1[1], 5, 2);  // The catalog number.
  input.line_1.copy(buf_1[2], 1, 7);  // The military secret level.
  input.line_1.copy(buf_1[3], 2, 9);  // The international id 1.
  input.line_1.copy(buf_1[4], 3, 11);  // The international id 2.
  input.line_1.copy(buf_1[5], 3, 14);  // The international id 3.
  input.line_1.copy(buf_1[6], 2, 18);  // The epoch 1.
  input.line_1.copy(buf_1[7], 12, 20);  // The epoch 2.
  input.line_1.copy(buf_1[8], 10, 33);  // The mean motion differential 1.
  input.line_1.copy(buf_1[9], 8, 44);  // The mean motion differential 2.
  input.line_1.copy(buf_1[10], 8, 53);  // The drag coefficient.
  input.line_1.copy(buf_1[11], 1, 62);  // The simulation model.
  input.line_1.copy(buf_1[12], 4, 64);  // The TLE serial number.
  // The line 2 is expanded.
  input.line_2.copy(buf_2[0], 1, 0);  // The line number (Always 2).
  input.line_2.copy(buf_2[1], 5, 2);  // The catalog number (Same as buf_1[1]).
  input.line_2.copy(buf_2[2], 8, 8);  // The inclination.
  input.line_2.copy(buf_2[3], 8, 17);  // The right ascension of ascending node.
  input.line_2.copy(buf_2[4], 7, 26);  // The eccentricity.
  input.line_2.copy(buf_2[5], 8, 34);  // The argument of perigee.
  input.line_2.copy(buf_2[6], 8, 43);  // The mean anomaly.
  input.line_2.copy(buf_2[7], 11, 52);  // The mean motion.
  input.line_2.copy(buf_2[8], 5, 63);  // The rev count.
  // The catalog number.
  output->sat_num = _wtoi(buf_1[1]);
  // The military secret level.
  output->classification = buf_1[2][0];
  // The international id 1.
  output->id_1 = _wtoi(buf_1[3]);
  // The international id 2.
  output->id_2 = _wtoi(buf_1[4]);
  // The international id 3.
  output->id_3[0] = buf_1[5][0];
  output->id_3[1] = buf_1[5][1];
  output->id_3[2] = buf_1[5][2];
  output->id_3[3] = L'\0';
  // The epoch 1.
  output->epoch_year = _wtoi(buf_1[6]);
  // The epoch 2.
  output->epcoh_days = _wtof(buf_1[7]);
  // The mean motion differential level 1.
  output->ndot = _wtof(buf_1[8]);
  // The mean motion differential level 2.
  for (int i = 0; i < 6; ++i) tmp[i] = buf_1[9][i];
  if (buf_1[9][7] == L' ') {
    tmp[6] = L'\0';
  } else {
    tmp[6] = L'E';
    if (buf_1[9][6] == L'-') {
      tmp[7] = L'-';
    } else {
      tmp[7] = L'+';
    }
    tmp[8] = buf_1[9][7];
  }
  output->nddot = _wtof(tmp);
  // The drag.
  for (int i = 0; i < 6; ++i) tmp[i] = buf_1[10][i];
  if (buf_1[10][7] == L' ') {
    tmp[6] = L'\0';
  } else {
    tmp[6] = L'E';
    if (buf_1[10][6] == L'-') {
      tmp[7] = L'-';
    } else {
      tmp[7] = L'+';
    }
    tmp[8] = buf_1[10][7];
  }
  output->bstar = _wtof(tmp);
  // The simulation model.
  output->model = _wtoi(buf_1[11]);
  // The TLE serial number.
  output->s_num = _wtoi(buf_1[12]);

  // The inclination.
  output->inclo = _wtof(buf_2[2]);
  // The right ascension of ascending node.
  output->nodeo = _wtof(buf_2[3]);
  // The eccentricity.
  tmp[0] = L'0';
  tmp[1] = L'.';
  for (int i = 0; i < 7; ++i) tmp[2 + i] = buf_2[4][i];
  tmp[9] = L'\0';
  output->ecco = _wtof(tmp);
  // The argument of perigee.
  output->argpo = _wtof(buf_2[5]);
  // The mean anomaly.
  output->mo = _wtof(buf_2[6]);
  // The mean motion.
  output->no = _wtof(buf_2[7]);
  // The rev count.
  output->rev = _wtoi(buf_2[8]);
  return true;
}
