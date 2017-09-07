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
namespace {
  // The wtoi with range.
int wtoi2(const wchar_t* s, int curs, int len) {
  if ((curs < 0) || (len < 1) || (curs + len) > static_cast<int>(wcslen(s))) {
    return -1;
  }
  wchar_t buf[S_MAX] = {0};
  for (int i = 0; i < len; ++i) buf[i] = s[curs + i];
  buf[len + 1] = L'\0';
  return _wtoi(buf);
}
  // The wtof with range.
double wtof2(const wchar_t* s, int curs, int len) {
  if ((curs < 0) || (len < 1) || (curs + len) > static_cast<int>(wcslen(s))) {
    return -1;
  }
  wchar_t buf[S_MAX] = {0};
  for (int i = 0; i < len; ++i) buf[i] = s[curs + i];
  buf[len + 1] = L'\0';
  return _wtof(buf);
}
}  // namespace
bool ReadTLE(const InputTLE& input, OutputTLE* output) {
  assert(output);
  wchar_t buf_1[9][S_MAX] = {0};
  wchar_t buf_2[8][S_MAX] = {0};
  wchar_t tmp[S_MAX] = {0};
  // The line 0 is processed.
  output->name = input.line_0;
#if 1
  wprintf(L"Debug:\n");
  wprintf(L"line_0:%s\n", input.line_0.c_str());
#endif
  // The line 1 is processed.
  swscanf_s(input.line_1.c_str(), L"%s%s%s%s%s%s%s%s%s",
            buf_1[0], S_MAX, buf_1[1], S_MAX, buf_1[2], S_MAX, buf_1[3], S_MAX,
            buf_1[4], S_MAX, buf_1[5], S_MAX, buf_1[6], S_MAX, buf_1[7], S_MAX,
            buf_1[8], S_MAX);
#if 1
  wprintf(L"line_1:%s\n", input.line_1.c_str());
  for (int i = 0; i < 9; ++i) {
    wprintf(L"buf_1[%d]:%s\n", i, buf_1[i]);
  }
#endif
  // The catalog number.
  output->catalog_num = wtoi2(buf_1[1], 0, 5);
  // The military secret level.
  output->mil_level = buf_1[1][5];
  // Ids.
  output->id_1 = wtoi2(buf_1[2], 0, 2);
  output->id_2 = wtoi2(buf_1[2], 2, 3);
  output->id_3[0] = buf_1[2][5];
  output->id_3[1] = buf_1[2][6];
  output->id_3[2] = buf_1[2][7];
  // The epoch.
  output->epoch_1 = wtoi2(buf_1[3], 0, 2);
  output->epoch_2 = wtof2(buf_1[3], 2, 12);
  // The mean motion differential level 1.
  if ((buf_1[4][0] != L'+') && (buf_1[4][0] != L'-')) {
    tmp[0] = L'0';
    tmp[1] = L'.';
    for (int i = 0; i < 8; ++i) tmp[2 + i] = buf_1[4][1 + i];
    tmp[10] = L'\0';
  } else {
    tmp[0] = buf_1[4][0];  // L'+' or L'-'.
    tmp[1] = L'0';
    tmp[2] = L'.';
    for (int i = 0; i < 8; ++i) tmp[3 + i] = buf_1[4][2 + i];
    tmp[11] = L'\0';
  }
#if 1
  wprintf(L"mm_1 tmp:%s\n", tmp);
#endif
  output->mm_1 = _wtof(tmp);
  // The mean motion differential level 2.
  if ((buf_1[5][0] != L'+') && (buf_1[5][0] != L'-')) {
    tmp[0] = L'0';
    tmp[1] = L'.';
    for (int i = 0; i < 5; ++i) tmp[2 + i] = buf_1[5][i];
    tmp[7] = L'E';
    tmp[8] = buf_1[5][6];  // L'+' or L'-'.
    tmp[9] = buf_1[5][7];
    tmp[10] = L'\0';
  } else {
    tmp[0] = buf_1[5][0];  // L'+' or L'-'.
    tmp[1] = L'0';
    tmp[2] = L'.';
    for (int i = 0; i < 5; ++i) tmp[3 + i] = buf_1[5][1 + i];
    tmp[8] = L'E';
    tmp[9] = buf_1[5][6];  // L'+' or L'-' or L' '.
    tmp[10] = buf_1[5][7];  // numeric or L' '.
    tmp[11] = L'\0';
  }
#if 1
  wprintf(L"mm_2 tmp:%s\n", tmp);
#endif
  output->mm_2 = _wtof(tmp);
  // The drag.
  if ((buf_1[6][0] != L'+') && (buf_1[6][0] != L'-')) {
    tmp[0] = L'0';
    tmp[1] = L'.';
    for (int i = 0; i < 7; ++i) tmp[2 + i] = buf_1[6][i];
    tmp[9] = L'E';
    tmp[10] = buf_1[6][6];  // L'+' or L'-' or L' '.
    tmp[11] = buf_1[6][7];
    tmp[12] = L'\0';
  } else {
    tmp[0] = buf_1[6][0];  // L'+' or L'-'.
    tmp[1] = L'0';
    tmp[2] = L'.';
    for (int i = 0; i < 7; ++i) tmp[3 + i] = buf_1[6][1 + i];
    tmp[10] = L'E';
    tmp[11] = buf_1[6][6];  // L'+' or L'-' or L' '.
    tmp[12] = buf_1[6][7];  // numeric or L' '.
    tmp[13] = L'\0';
  }
#if 1
  wprintf(L"b_star tmp:%s\n", tmp);
#endif
  output->b_star = _wtof(tmp);
  // The simulation model.
  output->model = _wtoi(buf_1[7]);
  // The TLE serial number.
  output->s_num = wtoi2(buf_1[8], 0, 4);
  // The line 2 is processed.
#if 1
  wprintf(L"Debug:\n");
#endif
  swscanf_s(input.line_2.c_str(), L"%s%s%s%s%s%s%s%s",
            buf_2[0], S_MAX, buf_2[1], S_MAX, buf_2[2], S_MAX, buf_2[3], S_MAX,
            buf_2[4], S_MAX, buf_2[5], S_MAX, buf_2[6], S_MAX, buf_2[7], S_MAX);
#if 1
  wprintf(L"line_2:%s\n", input.line_2.c_str());
  for (int i = 0; i < 8; ++i) {
    wprintf(L"buf_2[%d]:%s\n", i, buf_2[i]);
  }
#endif
  // The inclination.
  output->incl = _wtof(buf_2[2]);
  // The right ascension of ascending node.
  output->raan = _wtof(buf_2[3]);
  // The eccentricity.
  tmp[0] = L'0';
  tmp[1] = L'.';
  for (int i = 0; i < 7; ++i) tmp[2 + i] = buf_2[4][i];
  tmp[9] = L'\0';
#if 1
  wprintf(L"eccn tmp:%s\n", tmp);
#endif
  output->eccn = _wtof(tmp);
  // The argument of perigee.
  output->argp = _wtof(buf_2[5]);
  // The mean anomaly.
  output->ma = _wtof(buf_2[6]);
  // The mean motion.
  output->mm = wtof2(buf_2[7], 0, 11);
  // The rev count.
  output->rev = wtoi2(buf_2[7], 11, 5);
  return true;
}
