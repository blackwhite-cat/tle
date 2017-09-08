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
  // The TLE description structure is set.
  sat::TLEDesc desc;
  desc.line_0 = line_0;
  desc.line_1 = line_1;
  desc.line_2 = line_2;
  // The TLE is read.
  sat::TLEData tle;
  sat::ReadTLE(desc, &tle);
  // The line 0 information is shown.
  wprintf(L"\n%s\n", line_0);
  wprintf(L"衛星名:%s\n", tle.name.c_str());
  // The line 1 information is shown.
  wprintf(L"\n%s\n", line_1);
  wprintf(L"衛星カタログ番号:%d\n", tle.sat_num);
  wprintf(L"軍事機密種別:%c\n", tle.classification);
  wprintf(L"国際識別番号（打ち上げ年下二桁）:%d\n", tle.id_1);
  wprintf(L"国際識別番号（打ち上げ通番）:%d\n", tle.id_2);
  wprintf(L"国際識別番号（飛翔体通番）:%s\n", tle.id_3);
  wprintf(L"元期（年下二桁）:%d\n", tle.epoch_year);
  wprintf(L"元期（通日）:%.8lf\n", tle.epoch_days);
  wprintf(L"平均運動一次微分値の1/2倍:%.8lf\n", tle.ndot);
  wprintf(L"平均運動二次微分値の1/6倍:%.8lf\n", tle.nddot);
  wprintf(L"抗力項:%.8lf\n", tle.bstar);
  wprintf(L"軌道モデル:%d\n", tle.model);
  wprintf(L"軌道要素通番:%d\n", tle.s_num);
  // The line 2 information is shown.
  wprintf(L"\n%s\n", line_2);
  wprintf(L"軌道傾斜角:%.8lf\n", tle.inclo);
  wprintf(L"昇交点赤経:%.8lf\n", tle.nodeo);
  wprintf(L"離心率:%.8lf\n", tle.ecco);
  wprintf(L"近地点引数:%.8lf\n", tle.argpo);
  wprintf(L"平均近点角:%.8lf\n", tle.mo);
  wprintf(L"平均運動:%.8lf\n", tle.no);
  wprintf(L"元期における通算周回数:%d\n", tle.rev);
}
int wmain(int argc, char* argv[]) {
  // The Japanese local is used for console output.
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
