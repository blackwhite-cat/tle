  // @file main.cc
  // @brief TLE elements resolver test.
  // @author Mamoru Kaminaga
  // @date 2017-09-07 12:52:18
  // Copyright 2017 Mamoru Kaminaga
  // Note: Save this file with BOM.
#include <assert.h>
#include <stdio.h>
#include "./tle.h"
void Test(const wchar_t* line_0, const wchar_t* line_1, const wchar_t* line_2){
  assert(line_0);
  assert(line_1);
  assert(line_2);
  wprintf(L"\n");
  wprintf(L"%ls\n", line_0);
  wprintf(L"%ls\n", line_1);
  wprintf(L"%ls\n", line_2);
  // The TLE description structure is set.
  sat::TLEDesc desc;
  desc.line_0 = line_0;
  desc.line_1 = line_1;
  desc.line_2 = line_2;
  // The TLE is read.
  sat::TLEData tle;
  sat::ReadTLE(desc, &tle);
  // The line 0 information is shown.
  wprintf(L"line 0\n");
  wprintf(L"name:%ls\n", tle.name.c_str());
  // The line 1 information is shown.
  wprintf(L"\n");
  wprintf(L"line 1\n");
  wprintf(L"sat_num:%d\n", tle.sat_num);
  wprintf(L"classification:%c\n", tle.classification);
  wprintf(L"id_1:%d\n", tle.id_1);
  wprintf(L"id_2:%d\n", tle.id_2);
  wprintf(L"id_3:%ls\n", tle.id_3);
  wprintf(L"epoch year:%d\n", tle.epoch_year);
  wprintf(L"epoch days:%.8lf\n", tle.epoch_days);
  wprintf(L"ndot:%.8lf\n", tle.ndot);
  wprintf(L"nddot:%.8lf\n", tle.nddot);
  wprintf(L"bstar:%.8lf\n", tle.bstar);
  wprintf(L"model:%d\n", tle.model);
  wprintf(L"s_num:%d\n", tle.s_num);
  // The line 2 information is shown.
  wprintf(L"\n");
  wprintf(L"line 2\n");
  wprintf(L"inclo:%.8lf\n", tle.inclo);
  wprintf(L"nodeo:%.8lf\n", tle.nodeo);
  wprintf(L"ecco:%.8lf\n", tle.ecco);
  wprintf(L"argpo:%.8lf\n", tle.argpo);
  wprintf(L"mo:%.8lf\n", tle.mo);
  wprintf(L"no:%.8lf\n", tle.no);
  wprintf(L"rev:%d\n", tle.rev);
}
int main(int argc, char* argv[]) {
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
