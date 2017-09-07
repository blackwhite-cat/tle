  // @file main.cc
  // @brief TLE elements resolver test.
  // @author Mamoru Kaminaga
  // @date 2017-09-07 12:52:18
  // Copyright 2017 Mamoru Kaminaga
  // Note: Save this file with BOM.
#include "./tle.h"
#include <stdio.h>
#include <locale.h>
int wmain(int argc, char* argv[]) {
  InputTLE input;
  OutputTLE output;
  ReadTLE(input, &output);
  // The Japanese is used for output.
  setlocale(LC_ALL, "Japanese");
  // The test dat is set.
  // 2017/9/7 14:00:00
  // TLE data from NORAD
  // http://celestrak.com/NORAD/elements/cubesat.txt
  input.line_0 = L"ITF-2                   ";
  input.line_1 =
    L"1 41932U 98067KU  17249.55458570  .00023584  00000-0  27558-3 0  9993";
  input.line_2 =
    L"2 41932  51.6416 345.8089 0004200 218.6727 141.3966 15.61468125 36244";
  // The line 0 information is shown.
  wprintf(L"Line 0:\n");
  wprintf(L"衛星名:%s\n", output.name.c_str());
  // The line 1 information is shown.
  wprintf(L"\nLine 1:\n");
  wprintf(L"衛星カタログ番号:%d\n", output.catalog_num);
  wprintf(L"軍事機密種別:%d\n", output.mil_level);
  wprintf(L"国際識別番号（打ち上げ年下二桁）:%d\n", output.id_1);
  wprintf(L"国際識別番号（打ち上げ通番）:%d\n", output.id_2);
  wprintf(L"国際識別番号（飛翔体通番）:%d\n", output.id_3);
  wprintf(L"元期（年下二桁）:%d\n", output.epoch_1);
  wprintf(L"元期（通日）:%lf\n", output.epoch_2);
  wprintf(L"平均運動一次微分値の1/2倍:%lf\n", output.mm_1);
  wprintf(L"平均運動二次微分値の1/6倍:%lf\n", output.mm_2);
  wprintf(L"抗力項:%lf\n", output.b_star);
  wprintf(L"軌道モデル:%d\n", output.model);
  wprintf(L"軌道要素通番:%d\n", output.s_num);
  wprintf(L"Line1チェックサム:%d\n", output.check_sum_1);
  // The line 2 information is shown.
  wprintf(L"\nLine 2:\n");
  return 0;
}
