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
namespace sat {
bool ReadTLE(const TLEDesc& desc, TLEData* tle) {
  assert(tle);
  wchar_t buf_1[13][S_MAX] = {0};
  wchar_t buf_2[9][S_MAX] = {0};
  wchar_t tmp[S_MAX] = {0};
  // The line 0 is processed.
  tle->name = desc.line_0;
  // The line 1 is expanded.
  desc.line_1.copy(buf_1[0], 1, 0);  // The line number (Always 1).
  desc.line_1.copy(buf_1[1], 5, 2);  // The catalog number.
  desc.line_1.copy(buf_1[2], 1, 7);  // The military secret level.
  desc.line_1.copy(buf_1[3], 2, 9);  // The international id 1.
  desc.line_1.copy(buf_1[4], 3, 11);  // The international id 2.
  desc.line_1.copy(buf_1[5], 3, 14);  // The international id 3.
  desc.line_1.copy(buf_1[6], 2, 18);  // The epoch 1.
  desc.line_1.copy(buf_1[7], 12, 20);  // The epoch 2.
  desc.line_1.copy(buf_1[8], 10, 33);  // The mean motion differential 1.
  desc.line_1.copy(buf_1[9], 8, 44);  // The mean motion differential 2.
  desc.line_1.copy(buf_1[10], 8, 53);  // The drag coefficient.
  desc.line_1.copy(buf_1[11], 1, 62);  // The simulation model.
  desc.line_1.copy(buf_1[12], 4, 64);  // The TLE serial number.
  // The line 2 is expanded.
  desc.line_2.copy(buf_2[0], 1, 0);  // The line number (Always 2).
  desc.line_2.copy(buf_2[1], 5, 2);  // The catalog number (Same as buf_1[1]).
  desc.line_2.copy(buf_2[2], 8, 8);  // The inclination.
  desc.line_2.copy(buf_2[3], 8, 17);  // The right ascension of ascending node.
  desc.line_2.copy(buf_2[4], 7, 26);  // The eccentricity.
  desc.line_2.copy(buf_2[5], 8, 34);  // The argument of perigee.
  desc.line_2.copy(buf_2[6], 8, 43);  // The mean anomaly.
  desc.line_2.copy(buf_2[7], 11, 52);  // The mean motion.
  desc.line_2.copy(buf_2[8], 5, 63);  // The rev count.
  // The catalog number.
  tle->sat_num = _wtoi(buf_1[1]);
  // The military secret level.
  tle->classification = buf_1[2][0];
  // The international id 1.
  tle->id_1 = _wtoi(buf_1[3]);
  // The international id 2.
  tle->id_2 = _wtoi(buf_1[4]);
  // The international id 3.
  tle->id_3[0] = buf_1[5][0];
  tle->id_3[1] = buf_1[5][1];
  tle->id_3[2] = buf_1[5][2];
  tle->id_3[3] = L'\0';
  // The epoch 1.
  tle->epoch_year = _wtoi(buf_1[6]);
  // The epoch 2.
  tle->epoch_days = _wtof(buf_1[7]);
  // The mean motion differential level 1.
  tle->ndot = _wtof(buf_1[8]);
  // The mean motion differential level 2.
  if (buf_1[9][0] == L'-') {
    tmp[0] = L'-';
  } else {
    tmp[0] = L'+';
  }
  tmp[1] = L'.';
  for (int i = 0; i < 5; ++i) tmp[2 + i] = buf_1[9][1 + i];
  if (buf_1[9][7] == L' ') {
    tmp[7] = L'\0';
  } else {
    tmp[7] = L'E';
    if (buf_1[9][6] == L'-') {
      tmp[8] = L'-';
    } else {
      tmp[8] = L'+';
    }
    tmp[9] = buf_1[9][7];
    tmp[10] = L'\0';
  }
  tle->nddot = _wtof(tmp);
  // The drag.
  if (buf_1[10][0] == L'-') {
    tmp[0] = L'-';
  } else {
    tmp[0] = L'+';
  }
  tmp[1] = L'.';
  for (int i = 0; i < 5; ++i) tmp[2 + i] = buf_1[10][1 + i];
  if (buf_1[10][7] == L' ') {
    tmp[7] = L'\0';
  } else {
    tmp[7] = L'E';
    if (buf_1[10][6] == L'-') {
      tmp[8] = L'-';
    } else {
      tmp[8] = L'+';
    }
    tmp[9] = buf_1[10][7];
    tmp[10] = L'\0';
  }
  tle->bstar = _wtof(tmp);
  // The simulation model.
  tle->model = _wtoi(buf_1[11]);
  // The TLE serial number.
  tle->s_num = _wtoi(buf_1[12]);

  // The inclination.
  tle->inclo = _wtof(buf_2[2]);
  // The right ascension of ascending node.
  tle->nodeo = _wtof(buf_2[3]);
  // The eccentricity.
  tmp[0] = L'0';
  tmp[1] = L'.';
  for (int i = 0; i < 7; ++i) tmp[2 + i] = buf_2[4][i];
  tmp[9] = L'\0';
  tle->ecco = _wtof(tmp);
  // The argument of perigee.
  tle->argpo = _wtof(buf_2[5]);
  // The mean anomaly.
  tle->mo = _wtof(buf_2[6]);
  // The mean motion.
  tle->no = _wtof(buf_2[7]);
  // The rev count.
  tle->rev = _wtoi(buf_2[8]);
  return true;
}
}  // namespace sat
