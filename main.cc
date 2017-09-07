  // @file main.cc
  // @brief TLE elements resolver test.
  // @author Mamoru Kaminaga
  // @date 2017-09-07 12:52:18
  // Copyright 2017 Mamoru Kaminaga
  // Note: Save this file with BOM.
#include <stdio.h>
#include <locale.h>
#include "./tle.h"
int wmain(int argc, char* argv[]) {
  InputTLE input;
  OutputTLE output;
  // The Japanese is used for output.
  setlocale(LC_ALL, "Japanese");
  // The test data is set.
  // TLE data from NORAD, acquired at 2017/9/7 14:00:00 (JST).
  // http://celestrak.com/NORAD/elements/cubesat.txt
  input.line_0 = L"ITF-2                   ";
  input.line_1 =
    L"1 41932U 98067KU  17249.55458570  .00023584  00000-0  27558-3 0  9993";
  input.line_2 =
    L"2 41932  51.6416 345.8089 0004200 218.6727 141.3966 15.61468125 36244";
  // The TLE in read.
  ReadTLE(input, &output);
  // The line 0 information is shown.
  wprintf(L"Line 0:\n");
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
  return 0;
}
