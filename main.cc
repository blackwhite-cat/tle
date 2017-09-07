  // @file main.cc
  // @brief TLE elements resolver test.
  // @author Mamoru Kaminaga
  // @date 2017-09-07 12:52:18
  // Copyright 2017 Mamoru Kaminaga
  // Note: Save this file with BOM.
#include <assert.h>
#include <stdio.h>
#include <locale.h>
#include "./tle.h"
void Test(const wchar_t* line_0, const wchar_t* line_1, const wchar_t* line_2){
  assert(line_0);
  assert(line_1);
  assert(line_2);
  InputTLE input;
  OutputTLE output;
  input.line_0 = line_0;
  input.line_1 = line_1;
  input.line_2 = line_2;
  // The TLE in read.
  ReadTLE(input, &output);
  // The line 0 information is shown.
  wprintf(L"\nLine 0:\n");
  wprintf(L"衛星名:%s\n", output.name.c_str());
  // The line 1 information is shown.
  wprintf(L"\nLine 1:\n");
  wprintf(L"衛星カタログ番号:%d\n", output.catalog_num);
  wprintf(L"軍事機密種別:%c\n", output.mil_level);
  wprintf(L"国際識別番号（打ち上げ年下二桁）:%d\n", output.id_1);
  wprintf(L"国際識別番号（打ち上げ通番）:%d\n", output.id_2);
  wprintf(L"国際識別番号（飛翔体通番）:%s\n", output.id_3);
  wprintf(L"元期（年下二桁）:%d\n", output.epoch_1);
  wprintf(L"元期（通日）:%.8lf\n", output.epoch_2);
  wprintf(L"平均運動一次微分値の1/2倍:%.8lf\n", output.mm_1);
  wprintf(L"平均運動二次微分値の1/6倍:%.8lf\n", output.mm_2);
  wprintf(L"抗力項:%.8lf\n", output.b_star);
  wprintf(L"軌道モデル:%d\n", output.model);
  wprintf(L"軌道要素通番:%d\n", output.s_num);
  // The line 2 information is shown.
  wprintf(L"\nLine 2:\n");
  wprintf(L"軌道傾斜角:%.8lf\n", output.incl);
  wprintf(L"昇交点赤経:%.8lf\n", output.raan);
  wprintf(L"離心率:%.8lf\n", output.eccn);
  wprintf(L"近地点引数:%.8lf\n", output.argp);
  wprintf(L"平均近点角:%.8lf\n", output.ma);
  wprintf(L"平均運動:%.8lf\n", output.mm);
  wprintf(L"元期における通算周回数:%d\n", output.rev);
}
int wmain(int argc, char* argv[]) {
  // The Japanese is used for output.
  setlocale(LC_ALL, "Japanese");
  // The test data is set.
  // TLE data from NORAD, acquired at 2017/9/7 14:00:00 (JST).
  // http://celestrak.com/NORAD/elements/cubesat.txt
  Test(
      L"ISS (ZARYA)             ",
      L"1 25544U 98067A   17249.78765650  .00006095  00000-0  99372-4 0  9991",
      L"2 25544  51.6444 351.5411 0004084 234.7486 264.1180 15.54087690 74442");
  Test(
      L"CUBESAT XI-IV (CO-57)   ",
      L"1 27848U 03031J   17249.92680291  .00000064  00000-0  49201-4 0  9996",
      L"2 27848  98.6996 258.0390 0010708 117.5695 242.6571 14.21669304735812");
  Test(
      L"CUTE-1 (CO-55)          ",
      L"1 27844U 03031E   17249.97520071  .00000092  00000-0  61369-4 0  9996",
      L"2 27844  98.6903 257.7937 0010881 108.6420 251.5939 14.22057092735945");
  Test(
      L"ITF-2                   ",
      L"1 41932U 98067KU  17249.55458570  .00023584  00000-0  27558-3 0  9993",
      L"2 41932  51.6416 345.8089 0004200 218.6727 141.3966 15.61468125 36244");
  return 0;
}
