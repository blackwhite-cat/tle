  // @file tle.cc
  // @brief TLE elements resolver.
  // @author Mamoru Kaminaga
  // @date 2017-09-07 12:52:18
  // Copyright 2017 Mamoru Kaminaga
#ifndef TLE_H_
#define TLE_H_
#include <wchar.h>
#include <string>
struct InputTLE {
  std::wstring line_0;
  std::wstring line_1;
  std::wstring line_2;
};
struct OutputTLE {
  int num;  // line 1, column 1-2.
  int catalog_num;  // line 1, column 3-7.
  int id_1;  // line 1, column 10-11.
  int id_2;  // line 1, column 12-14.
  int model;  // line 1, column 63.
  int s_num;  // line 1, column 65-68.
  int epoch_1;  // line 1, column 19-21.
  int rev;  // line 2, column 64-68.
  wchar_t mil_level;  // line 1, column 8-9.
  wchar_t id_3[4];  // line 1, column 15-18.
  double epoch_2;  // line 1, column 21-33.
  double mm_1;  // line 1, column 34-44.
  double mm_2;  // line 1, column 45-53.
  double b_star;  // line 1, column 54-62.
  double incl;  // line 2, column 9-17.
  double raan;  // line 2, column 9-26.
  double eccn;  // line 2, column 27-34.
  double argp;  // line 2, column 35-43.
  double ma;  // line 2, column 44-52.
  double mm;  // line 2, column 53-63.
  std::wstring name;  // line 0, column 1-24.
};
bool ReadTLE(const InputTLE& input, OutputTLE* output);
#endif  // TLE_H_
