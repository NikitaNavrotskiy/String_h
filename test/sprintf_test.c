#include "../my_string.h"
#include "string_test.h"

START_TEST(sprintf_1) {
  char res[300];
  char my[300];
  char *format = "some %d %4d %-4d %05d %+6d %#7d % *d some";

  int num = -5;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_2) {
  char res[300];
  char my[300];
  char *format = "some %d %6d %-6d %06d %+8d %#7d % *d some";

  int num = 353;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_3) {
  char res[300];
  char my[300];
  char *format = "some %d %2d %-2d %02d %+2d %#2d % *d some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_4) {
  char res[300];
  char my[300];
  char *format = "some %x %2x %-2x %02x %+2x %#2x % *x some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_5) {
  char res[300];
  char my[300];
  char *format = "some %X %2X %-2X %02X %+2X %#2X % *x some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_6) {
  char res[300];
  char my[300];
  char *format = "some %x %4x %-4x %05x %+6x %#7x % *x some";

  int num = -5;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_7) {
  char res[300];
  char my[300];
  char *format = "some %x %4x %-4x %05x %+6x %#7x % *x some";

  int num = 3451234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_8) {
  char res[300];
  char my[300];
  char *format = "some %o %14o %-14o %015o %+16o %#17o % *o some";

  int num = -1234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_9) {
  char res[300];
  char my[300];
  char *format = "some %o %15o %-15o %015o %+16o %#17o % *d some";

  int num = 3451234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_10) {
  char res[300];
  char my[300];
  char *format = "some %o %2o %-2o %02o %+2o %#2o % *d some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_11) {
  char res[300];
  char my[300];
  char *format = "some %u %6u %-6u %06u %+8u %#7u % *d some";

  int num = 353;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_12) {
  char res[300];
  char my[300];
  char *format = "some %u %2u %-2u %02u %+2u %#2u % *d some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_13) {
  char res[300];
  char my[300];
  char *format = "some %ld %15ld %-15ld %015ld %+15ld %#15ld % *ld some";

  long num = -52545565335;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_14) {
  char res[300];
  char my[300];
  char *format = "some %ld %15ld %-15ld %015ld %+15ld %#15ld % *ld some";

  long num = 224556535300;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_15) {
  char res[300];
  char my[300];
  char *format = "some %ld %2ld %-2ld %02ld %+2ld %#2ld % *ld some";

  long num = 22587356590;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_16) {
  char res[300];
  char my[300];
  char *format = "some %ho %10ho %-10ho %010ho %+10ho %#10ho % *ho some";

  short int num = -3532;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_17) {
  char res[300];
  char my[300];
  char *format = "some %ho %2ho %-2ho %02ho %+2ho %#2ho % *ho some";

  unsigned short int num = 13000;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_18) {
  char res[300];
  char my[300];
  char *format = "some %hu %6hu %-6hu %06hu %+8hu %#7hu % *hu some";

  unsigned short int num = 65000;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_19) {
  char res[300];
  char my[300];
  char *format = "some %hu %2hu %-2hu %02hu %+2hu %#2hu % *hu some";

  unsigned short int num = 65000;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_20) {
  char res[300];
  char my[300];
  char *format = "some %hd %15hd %-15hd %015hd %+15hd %#15hd % *hd some";

  short int num = -2343;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_21) {
  char res[300];
  char my[300];
  char *format = "some %hd %15hd %-15hd %015hd %+15hd %#15hd % *hd some";

  short int num = 13341;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_22) {
  char res[300];
  char my[300];
  char *format = "some %hd %2hd %-2hd %02hd %+2hd %#2hd % *hd some";

  short int num = 12346;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_23) {
  char res[300];
  char my[300];
  char *format = "some %lx %4lx %-4lx %05lx %+6lx %#7lx % *lx some";

  long num = 52645644;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_24) {
  char res[300];
  char my[300];
  char *format = "some %hx %4hx %-4hx %05hx %+6hx %#7hx % *hx some";

  short int num = 1234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_25) {
  char res[100];
  char my[100];
  char sym = '#';
  char *format = "some %c % 4c %-4c %+4c %04c %#4c % *c some";

  int res1 = my_sprintf(my, format, sym, sym, sym, sym, sym, sym, 4, sym);
  int res2 = sprintf(res, format, sym, sym, sym, sym, sym, sym, 4, sym);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_26) {
  char res[100];
  char my[100];
  char sym = '\0';
  char *format = "some %c % 4c %-4c %+4c %04c %#4c % *c some";

  int res1 = my_sprintf(my, format, sym, sym, sym, sym, sym, sym, 4, sym);
  int res2 = sprintf(res, format, sym, sym, sym, sym, sym, sym, 4, sym);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_27) {
  char res[400];
  char my[400];
  char *format = "some %20s % 20s %-20s %+20s %020s %#20s % *s some";
  char *word = "Hello World!";

  int res1 =
      my_sprintf(my, format, word, word, word, word, word, word, 20, word);
  int res2 = sprintf(res, format, word, word, word, word, word, word, 20, word);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_28) {
  char res[400];
  char my[400];
  char *format = "some %s % 4s %-4s %+4s %04s %#4s % *s some";
  char *word = "Hello World!";
  int res1 =
      my_sprintf(my, format, word, word, word, word, word, word, 4, word);
  int res2 = sprintf(res, format, word, word, word, word, word, word, 4, word);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_29) {
  char res[400];
  char my[400];
  char *format = "some affafafafaffafafaff %s %n some";
  char *word = "Hello World!";
  int n1;
  int n2;
  int res1 = my_sprintf(my, format, word, &n1);
  int res2 = sprintf(res, format, word, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(sprintf_31) {
  char res[400];
  char my[400];
  char *format = "some %p % 20p %-20p %+20p %020p %#20p some";
  int n;

  int res1 = my_sprintf(my, format, &n, &n, &n, &n, &n, &n);
  int res2 = sprintf(res, format, &n, &n, &n, &n, &n, &n);
  ck_assert_int_eq(res1, res2);
}

// precision numbers tests

START_TEST(sprintf_32) {
  char res[300];
  char my[300];
  char *format = "some %.3d %4.3d %-4.3d %05.3d %+6.3d %#7.3d % *.*d some";

  int num = -5;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_33) {
  char res[300];
  char my[300];
  char *format = "some %.3d %4.3d %-4.3d %05.3d %+6.3d %#7.3d % *.*d some";

  int num = 353;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_34) {
  char res[300];
  char my[300];
  char *format =
      "some %.20d %2.20d %-2.20d %02.20d %+2.20d %#2.20d % *.*d some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_35) {
  char res[300];
  char my[300];
  char *format =
      "some %.20x %2.20x %-2.20x %02.20x %+2.20x %#2.20x % *.*x some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_36) {
  char res[300];
  char my[300];
  char *format =
      "some %.20X %2.20X %-2.20X %02.20X %+2.20X %#2.20X % *.*x some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_37) {
  char res[300];
  char my[300];
  char *format = "some %.3x %4.3x %-4.3x %05.3x %+6.3x %#7.3x % *.*x some";

  int num = -5;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_38) {
  char res[300];
  char my[300];
  char *format = "some %.3x %4.3x %-4.3x %05.3x %+6.3x %#7.3x % *.*x some";

  int num = 3451234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_39) {
  char res[300];
  char my[300];
  char *format = "some %.3o %14.3o %-14.3o %015.3o %+16.3o %#17.3o % *.*o some";

  int num = -1234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_40) {
  char res[300];
  char my[300];
  char *format = "some %.3o %15.3o %-15.3o %015.3o %+16.3o %#17.3o % *.*d some";

  int num = 3451234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_41) {
  char res[300];
  char my[300];
  char *format =
      "some %.20o %2.20o %-2.20o %02.20o %+2.20o %#2.20o % *.*d some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_42) {
  char res[300];
  char my[300];
  char *format = "some %.3u %6.3u %-6.3u %06.3u %+8.3u %#7.3u % *.*d some";

  int num = 353;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_43) {
  char res[300];
  char my[300];
  char *format =
      "some % 2.20u %2.20u %-2.20u %02.20u %+2.20u %#2.20u % *.*d some";

  int num = 353342;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_44) {
  char res[300];
  char my[300];
  char *format =
      "some %0.3ld %15.3ld %-15.3ld %015.3ld %+15.3ld %#15.3ld % *.*ld some";

  long num = -52545565335;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_45) {
  char res[300];
  char my[300];
  char *format =
      "some %0.3ld %15.3ld %-15.3ld %015.3ld %+15.3ld %#15.3ld % *.*ld some";

  long num = 224556535300;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_46) {
  char res[300];
  char my[300];
  char *format =
      "some %.20ld %2.20ld %-2.20ld %02.20ld %+2.20ld %#2.20ld % *.*ld some";

  long num = 22587356590;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_47) {
  char res[300];
  char my[300];
  char *format =
      "some %.3ho %10.3ho %-10.3ho %010.3ho %+10.3ho %#10.3ho % *.*ho some";

  short int num = -3532;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_48) {
  char res[300];
  char my[300];
  char *format =
      "some %.20ho %2.20ho %-2.20ho %02.20ho %+2.20ho %#2.20ho % *.*ho some";

  unsigned short int num = 13000;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_49) {
  char res[300];
  char my[300];
  char *format =
      "some %.3hu %6.3hu %-6.3hu %06.3hu %+8.3hu %#7.3hu % *.*hu some";

  unsigned short int num = 65000;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_50) {
  char res[300];
  char my[300];
  char *format =
      "some %.20hu %2.20hu %-2.20hu %02.20hu %+2.20hu %#2.20hu % *.*hu some";

  unsigned short int num = 65000;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_51) {
  char res[300];
  char my[300];
  char *format =
      "some %.3hd %15.3hd %-15.3hd %015.3hd %+15.3hd %#15.3hd % *.*hd some";

  short int num = -2343;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_52) {
  char res[300];
  char my[300];
  char *format =
      "some %.3hd %15.3hd %-15.3hd %015.3hd %+15.3hd %#15.3hd % *.*hd some";

  short int num = 13341;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_53) {
  char res[300];
  char my[300];
  char *format =
      "some %.20hd %2.20hd %-2.20hd %02.20hd %+2.20hd %#2.20hd % *.*hd some";

  short int num = 12346;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 2, 20, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 2, 20, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_54) {
  char res[300];
  char my[300];
  char *format =
      "some %.3lx %4.3lx %-4.3lx %05.3lx %+6.3lx %#7.3lx % *.*lx some";

  long num = 52645644344;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_55) {
  char res[300];
  char my[300];
  char *format =
      "some %.3hx %4.3hx %-4.3hx %05.3hx %+6.3hx %#7.3hx % *.*hx some";

  short int num = 1234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 15, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 15, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

// only precision, without width

START_TEST(sprintf_56) {
  char res[300];
  char my[300];
  char *format = "some %.3hx % .3hx %-.3hx %0.3hx %+.3hx %#.3hx % .*hx some";

  short int num = 1234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_57) {
  char res[300];
  char my[300];
  char *format = "some %.3hx % .3hx %-.3hx %0.3hx %+.3hx %#.3hx % .*hx some";

  short int num = -45;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_58) {
  char res[300];
  char my[300];
  char *format = "some %.3x %.3x %-.3x %0.3x %+.3x %#.3x % .*x some";

  int num = -5;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_59) {
  char res[300];
  char my[300];
  char *format = "some %.3x %.3x %-.3x %0.3x %+.3x %#.3x % .*x some";

  int num = 13245;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_60) {
  char res[300];
  char my[300];
  char *format = "some %.3lx %.3lx %-.3lx %0.3lx %+.3lx %#.3lx % .*lx some";

  long num = 52645644234;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_61) {
  char res[300];
  char my[300];
  char *format = "some %.3lx %.3lx %-.3lx %0.3lx %+.3lx %#.3lx % .*lx some";

  long num = -52645644242;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_62) {
  char res[300];
  char my[300];
  char *format = "some %.3hd %.3hd %-.3hd %0.3hd %+.3hd %#.3hd % .*hd some";

  short int num = 13341;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_63) {
  char res[300];
  char my[300];
  char *format = "some %.3hd %.3hd %-.3hd %0.3hd %+.3hd %#.3hd % .*hd some";

  short int num = -13341;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_64) {
  char res[300];
  char my[300];
  char *format = "some %.3d %.3d %-.3d %0.3d %+.3d %#.3d % .*d some";

  int num = 13343421;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_65) {
  char res[300];
  char my[300];
  char *format = "some %.3d %.3d %-.3d %0.3d %+.3d %#.3d % .*d some";

  int num = -13324241;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_66) {
  char res[300];
  char my[300];
  char *format = "some %.3ld %.3ld %-.3ld %0.3ld %+.3ld %#.3ld % .*ld some";

  long num = 13343234421;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_67) {
  char res[300];
  char my[300];
  char *format = "some %.3ld %.3ld %-.3ld %0.3ld %+.3ld %#.3ld % .*ld some";

  long num = -13342244241;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_68) {
  char res[300];
  char my[300];
  char *format = "some %.3hu %.3hu %-.3hu %0.3hu %+.3hu %#.3hu % .*hu some";

  unsigned short int num = 13341;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_69) {
  char res[300];
  char my[300];
  char *format = "some %.3u %.3u %-.3u %0.3u %+.3u %#.3u % .*u some";

  unsigned int num = 13343421;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_70) {
  char res[300];
  char my[300];
  char *format = "some %.3lu %.3lu %-.3lu %0.3lu %+.3lu %#.3lu % .*lu some";

  unsigned long num = 13343234421;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}

START_TEST(sprintf_71) {
  char res[300];
  char my[300];
  char *format = "some %.3ho %.3ho %-.3ho %0.3ho %+.3ho %#.3ho % .*ho some";

  short int num = -3532;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_72) {
  char res[300];
  char my[300];
  char *format = "some %.3ho %.3ho %-.3ho %0.3ho %+.3ho %#.3ho % .*ho some";

  short int num = 3532;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_73) {
  char res[300];
  char my[300];
  char *format = "some %.3o %.3o %-.3o %0.3o %+.3o %#.3o % .*o some";

  int num = -35234232;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_74) {
  char res[300];
  char my[300];
  char *format = "some %.3o %.3o %-.3o %0.3o %+.3o %#.3o % .*o some";

  int num = 24233532;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_75) {
  char res[300];
  char my[300];
  char *format = "some %.3lo %.3lo %-.3lo %0.3lo %+.3lo %#.3lo % .*lo some";

  long int num = -3525224532;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_76) {
  char res[300];
  char my[300];
  char *format = "some %.3lo %.3lo %-.3lo %0.3lo %+.3lo %#.3lo % .*lo some";

  long int num = 3532525222;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_77) {
  char res[300];
  char my[300];
  char *format = "some %f % f %0f %-f %+f %#f %*f some";

  float num = 123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_78) {
  char res[300];
  char my[300];
  char *format = "some %f % f %0f %-f %+f %#f %*f some";

  float num = 123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 8, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 8, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_79) {
  char res[300];
  char my[300];
  char *format = "some %f % f %0f %-f %+f %#f %*f some";

  float num = -123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 8, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 8, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_80) {
  char res[300];
  char my[300];
  char *format = "some %lf % lf %0lf %-lf %+lf %#lf %*lf some";

  double num = 123242.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_81) {
  char res[300];
  char my[300];
  char *format = "some %lf % lf %0lf %-lf %+lf %#lf %*lf some";

  double num = 4532123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_82) {
  char res[300];
  char my[300];
  char *format = "some %lf % lf %0lf %-lf %+lf %#lf %*lf some";

  double num = -1642223.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_83) {
  char res[300];
  char my[300];
  char *format = "some %Lf % Lf %0Lf %-Lf %+Lf %#Lf %*Lf some";

  long double num = 524423242.3425522122L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_84) {
  char res[300];
  char my[300];
  char *format = "some %Lf % Lf %0Lf %-Lf %+Lf %#Lf %*Lf some";

  long double num = 4532123.345646425L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_85) {
  char res[300];
  char my[300];
  char *format = "some %Lf % Lf %0Lf %-Lf %+Lf %#Lf %*Lf some";

  long double num = -1642245623.335335425L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_86) {
  char res[300];
  char my[300];
  char *format = "some %3f % 3f %03f %-3f %+3f %#3f %*f some";

  float num = 123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_87) {
  char res[300];
  char my[300];
  char *format = "some %20f % 20f %020f %-20f %+20f %#20f %*f some";

  float num = 123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 8, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 8, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_88) {
  char res[300];
  char my[300];
  char *format = "some %20f % 20f %020f %-20f %+20f %#20f %*f some";

  float num = -123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 8, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 8, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_89) {
  char res[300];
  char my[300];
  char *format = "some %3lf % 3lf %03lf %-3lf %+3lf %#3lf %*lf some";

  double num = 123242.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_90) {
  char res[300];
  char my[300];
  char *format = "some %20lf % 20lf %020lf %-20lf %+20lf %#20lf %*lf some";

  double num = 4532123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_91) {
  char res[300];
  char my[300];
  char *format = "some %20lf % 20lf %020lf %-20lf %+20lf %#20lf %*lf some";

  double num = -1642223.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_92) {
  char res[300];
  char my[300];
  char *format = "some %3Lf % 3Lf %03Lf %-3Lf %+3Lf %#3Lf %*Lf some";

  long double num = 524423242.3425522122L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_93) {
  char res[300];
  char my[300];
  char *format = "some %20Lf % 20Lf %020Lf %-20Lf %+20Lf %#20Lf %*Lf some";

  long double num = 4532123.345646425L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_94) {
  char res[300];
  char my[300];
  char *format = "some %20Lf % 20Lf %020Lf %-20Lf %+20Lf %#20Lf %*Lf some";

  long double num = -1642245623.335335425L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_95) {
  char res[300];
  char my[300];
  char *format = "some %3.6f % 3.5f %03.4f %-3.5f %+3.5f %#3.5f %*.*f some";

  float num = 123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, 5, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, 5, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_96) {
  char res[300];
  char my[300];
  char *format =
      "some %20.6f % 20.6f %020.5f %-20.4f %+20.5f %#20.4f %*.*f some";

  float num = 123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 8, 2, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 8, 2, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_97) {
  char res[300];
  char my[300];
  char *format =
      "some %20.6f % 20.6f %020.5f %-20.4f %+20.5f %#20.4f %*.*f some";

  float num = -123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 8, 4, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 8, 4, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_98) {
  char res[300];
  char my[300];
  char *format =
      "some %3.5lf % 3.6lf %03.7lf %-3.8lf %+3.9lf %#3.3lf %*.*lf some";

  double num = 123242.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, 4, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, 4, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_99) {
  char res[300];
  char my[300];
  char *format =
      "some %20.5lf % 20.6lf %020.3lf %-20.2lf %+20.1lf %#20.7lf %*.*lf some";

  double num = 4532123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 7, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 7, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_100) {
  char res[300];
  char my[300];
  char *format =
      "some %20.5lf % 20.6lf %020.3lf %-20.2lf %+20.1lf %#20.7lf %*.*lf some";

  double num = -1642223.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 6, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 6, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_101) {
  char res[300];
  char my[300];
  char *format =
      "some %3.5Lf % 3.6Lf %03.7Lf %-3.4Lf %+3.2Lf %#.3Lf %*.*Lf some";

  long double num = 524423242.3425522122L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_102) {
  char res[300];
  char my[300];
  char *format =
      "some %20.4Lf % 20.4Lf %020.3Lf %-20.2Lf %+20.5Lf %#20.7Lf %*.*Lf some";

  long double num = 4532123.345646425L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 1, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 1, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_103) {
  char res[300];
  char my[300];
  char *format =
      "some %20.4Lf % 20.4Lf %020.3Lf %-20.2Lf %+20.5Lf %#20.7Lf %*.*Lf some";

  long double num = -1642245623.335335425L;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_104) {
  char res[300];
  char my[300];
  char *format =
      "some %3.5lf % 3.6lf %03.7lf %-3.8lf %+3.9lf %#3.3lf %*.*lf some";

  double num = 5.0 / 0.0;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, 4, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, 4, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_105) {
  char res[300];
  char my[300];
  char *format =
      "some %20.5lf % 20.6lf %020.3lf %-20.2lf %+20.1lf %#20.7lf %*.*lf some";

  double num = -5.0 / 0.0;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 7, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 7, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_106) {
  char res[300];
  char my[300];
  char *format =
      "some %20.5lf % 20.6lf %020.3lf %-20.2lf %+20.1lf %#20.7lf %*.*lf some";

  double num = 0.0 / 0.0;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 6, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 6, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

//////////////////////////////////

START_TEST(sprintf_107) {
  char res[300];
  char my[300];
  char *format = "some %e % e %0e %-e %+e %#e %*e some";

  double num = 123242.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_108) {
  char res[300];
  char my[300];
  char *format = "some %E % E %0E %-E %+E %#E %*E some";

  double num = 4532123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_109) {
  char res[300];
  char my[300];
  char *format = "some %E % E %0E %-E %+E %#E %*E some";

  double num = -1642223.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_110) {
  char res[300];
  char my[300];
  char *format = "some %3e % 3e %03e %-3e %+3e %#3e %*e some";

  double num = 123242.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_111) {
  char res[300];
  char my[300];
  char *format = "some %20e % 20e %020e %-20e %+20e %#20e %*e some";

  double num = 4532123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_112) {
  char res[300];
  char my[300];
  char *format = "some %20e % 20e %020e %-20e %+20e %#20e %*e some";

  double num = -1642223.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_113) {
  char res[300];
  char my[300];
  char *format = "some %3.5e % 3.6e %03.7e %-3.8e %+3.9e %#3.3e %*.*e some";

  double num = 123242.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, 4, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, 4, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_114) {
  char res[300];
  char my[300];
  char *format =
      "some %20.5e % 20.6e %020.3e %-20.2e %+20.1e %#20.7e %*.*e some";

  double num = 4532123.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 7, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 7, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_115) {
  char res[300];
  char my[300];
  char *format =
      "some %20.5e % 20.6e %020.3e %-20.2e %+20.1e %#20.7e %*.*e some";

  double num = -1642223.3425;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 6, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 6, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_116) {
  char res[300];
  char my[300];
  char *format = "some %3.5e % 3.6e %03.7e %-3.8e %+3.9e %#3.3e %*.*e some";

  double num = 5.0 / 0.0;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 3, 4, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 3, 4, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_117) {
  char res[300];
  char my[300];
  char *format =
      "some %20.5e % 20.6e %020.3e %-20.2e %+20.1e %#20.7e %*.*e some";

  double num = -5.0 / 0.0;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 7, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 7, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_118) {
  char res[300];
  char my[300];
  char *format =
      "some %20.5e % 20.6e %020.3e %-20.2e %+20.1e %#20.7e %*.*e some";

  double num = 0.0 / 0.0;

  int res1 = my_sprintf(my, format, num, num, num, num, num, num, 16, 6, num);
  int res2 = sprintf(res, format, num, num, num, num, num, num, 16, 6, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_119) {
  char res[300];
  char my[300];
  char *format = "some %G % G %0G %-G %+G  some";

  double num = 0.00003240567;

  int res1 = my_sprintf(my, format, num, num, num, num, num);
  int res2 = sprintf(res, format, num, num, num, num, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_120) {
  char res[300];
  char my[300];
  char *format = "some %g % g %0g %-g %+g some";

  double num = 324.22440;

  int res1 = my_sprintf(my, format, num, num, num, num, num);
  int res2 = sprintf(res, format, num, num, num, num, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_121) {
  char res[300];
  char my[300];
  char *format = "some %G % G %0G %-G %+G  some";

  double num = 5.0 / 0.0;

  int res1 = my_sprintf(my, format, num, num, num, num, num);
  int res2 = sprintf(res, format, num, num, num, num, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_122) {
  char res[300];
  char my[300];
  char *format = "some %g % g %0g %-g %+g some";

  double num = 0.0 / 0.0;

  int res1 = my_sprintf(my, format, num, num, num, num, num);
  int res2 = sprintf(res, format, num, num, num, num, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_123) {
  char res[300];
  char my[300];
  char *format = "some %15G % 15G %015G %-15G %+15G  some";

  double num = 0.000324045;

  int res1 = my_sprintf(my, format, num, num, num, num, num);
  int res2 = sprintf(res, format, num, num, num, num, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

START_TEST(sprintf_124) {
  char res[300];
  char my[300];
  char *format = "some %15g % 15g %015g %-15g %+15g some";

  double num = 3.243040;

  int res1 = my_sprintf(my, format, num, num, num, num, num);
  int res2 = sprintf(res, format, num, num, num, num, num);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(res, my);
}
END_TEST

/* START_TEST(sprintf_125) {
    char res[300];
    char my[300];
    char *format = "some %.1G % .2G %0.3G %-.4G %+.5G  some";

    double num = 0.000324045;

    int res1 = my_sprintf(my, format, num, num, num, num, num);
    int res2 = sprintf(res, format, num, num, num, num, num);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(res, my);
}
END_TEST


START_TEST(sprintf_126) {
    char res[300];
    char my[300];
    char *format = "some %.5g % .4g %0.7g %-.2g %+.5g some";

    double num = 324.20440;

    int res1 = my_sprintf(my, format, num, num, num, num, num);
    int res2 = sprintf(res, format, num, num, num, num, num);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(res, my);
}
END_TEST  */

Suite *suite_sprintf() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_sprintf");
  tc = tcase_create("case_sprintf");

  // different number tests without precision
  tcase_add_test(tc, sprintf_1);
  tcase_add_test(tc, sprintf_2);
  tcase_add_test(tc, sprintf_3);
  tcase_add_test(tc, sprintf_4);
  tcase_add_test(tc, sprintf_5);
  tcase_add_test(tc, sprintf_6);
  tcase_add_test(tc, sprintf_7);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_10);
  tcase_add_test(tc, sprintf_11);
  tcase_add_test(tc, sprintf_12);
  tcase_add_test(tc, sprintf_13);
  tcase_add_test(tc, sprintf_14);
  tcase_add_test(tc, sprintf_15);
  tcase_add_test(tc, sprintf_16);
  tcase_add_test(tc, sprintf_17);
  tcase_add_test(tc, sprintf_18);
  tcase_add_test(tc, sprintf_19);
  tcase_add_test(tc, sprintf_20);
  tcase_add_test(tc, sprintf_21);
  tcase_add_test(tc, sprintf_22);
  tcase_add_test(tc, sprintf_23);
  tcase_add_test(tc, sprintf_24);

  tcase_add_test(tc, sprintf_25);
  tcase_add_test(tc, sprintf_26);
  tcase_add_test(tc, sprintf_27);
  tcase_add_test(tc, sprintf_28);
  tcase_add_test(tc, sprintf_29);

  tcase_add_test(tc, sprintf_31);

  // number tests with precision

  tcase_add_test(tc, sprintf_32);
  tcase_add_test(tc, sprintf_33);
  tcase_add_test(tc, sprintf_34);
  tcase_add_test(tc, sprintf_35);
  tcase_add_test(tc, sprintf_36);
  tcase_add_test(tc, sprintf_37);
  tcase_add_test(tc, sprintf_38);
  tcase_add_test(tc, sprintf_39);
  tcase_add_test(tc, sprintf_40);
  tcase_add_test(tc, sprintf_41);
  tcase_add_test(tc, sprintf_42);
  tcase_add_test(tc, sprintf_43);
  tcase_add_test(tc, sprintf_44);
  tcase_add_test(tc, sprintf_45);
  tcase_add_test(tc, sprintf_46);
  tcase_add_test(tc, sprintf_47);
  tcase_add_test(tc, sprintf_48);
  tcase_add_test(tc, sprintf_49);
  tcase_add_test(tc, sprintf_50);
  tcase_add_test(tc, sprintf_51);
  tcase_add_test(tc, sprintf_52);
  tcase_add_test(tc, sprintf_53);
  tcase_add_test(tc, sprintf_54);
  tcase_add_test(tc, sprintf_55);
  tcase_add_test(tc, sprintf_56);
  tcase_add_test(tc, sprintf_57);
  tcase_add_test(tc, sprintf_58);
  tcase_add_test(tc, sprintf_59);
  tcase_add_test(tc, sprintf_60);
  tcase_add_test(tc, sprintf_61);
  tcase_add_test(tc, sprintf_62);
  tcase_add_test(tc, sprintf_63);
  tcase_add_test(tc, sprintf_64);
  tcase_add_test(tc, sprintf_65);
  tcase_add_test(tc, sprintf_66);
  tcase_add_test(tc, sprintf_67);
  tcase_add_test(tc, sprintf_68);
  tcase_add_test(tc, sprintf_69);
  tcase_add_test(tc, sprintf_70);
  tcase_add_test(tc, sprintf_71);
  tcase_add_test(tc, sprintf_72);
  tcase_add_test(tc, sprintf_73);
  tcase_add_test(tc, sprintf_74);
  tcase_add_test(tc, sprintf_75);
  tcase_add_test(tc, sprintf_76);

  // floats

  tcase_add_test(tc, sprintf_77);
  tcase_add_test(tc, sprintf_78);
  tcase_add_test(tc, sprintf_79);
  tcase_add_test(tc, sprintf_80);
  tcase_add_test(tc, sprintf_81);
  tcase_add_test(tc, sprintf_82);
  tcase_add_test(tc, sprintf_83);
  tcase_add_test(tc, sprintf_84);
  tcase_add_test(tc, sprintf_85);
  tcase_add_test(tc, sprintf_86);
  tcase_add_test(tc, sprintf_87);
  tcase_add_test(tc, sprintf_88);
  tcase_add_test(tc, sprintf_89);
  tcase_add_test(tc, sprintf_90);
  tcase_add_test(tc, sprintf_91);
  tcase_add_test(tc, sprintf_92);
  tcase_add_test(tc, sprintf_93);
  tcase_add_test(tc, sprintf_94);
  tcase_add_test(tc, sprintf_95);
  tcase_add_test(tc, sprintf_96);
  tcase_add_test(tc, sprintf_97);
  tcase_add_test(tc, sprintf_98);
  tcase_add_test(tc, sprintf_99);
  tcase_add_test(tc, sprintf_100);
  tcase_add_test(tc, sprintf_101);
  tcase_add_test(tc, sprintf_102);
  tcase_add_test(tc, sprintf_103);
  tcase_add_test(tc, sprintf_104);
  tcase_add_test(tc, sprintf_105);
  tcase_add_test(tc, sprintf_106);
  tcase_add_test(tc, sprintf_107);
  tcase_add_test(tc, sprintf_108);
  tcase_add_test(tc, sprintf_109);
  tcase_add_test(tc, sprintf_110);
  tcase_add_test(tc, sprintf_111);
  tcase_add_test(tc, sprintf_112);
  tcase_add_test(tc, sprintf_113);
  tcase_add_test(tc, sprintf_114);
  tcase_add_test(tc, sprintf_115);
  tcase_add_test(tc, sprintf_116);
  tcase_add_test(tc, sprintf_117);
  tcase_add_test(tc, sprintf_118);

  tcase_add_test(tc, sprintf_119);
  tcase_add_test(tc, sprintf_120);
  tcase_add_test(tc, sprintf_121);
  tcase_add_test(tc, sprintf_122);
  tcase_add_test(tc, sprintf_123);
  tcase_add_test(tc, sprintf_124);
  /*     tcase_add_test(tc, sprintf_125);
      tcase_add_test(tc, sprintf_126); */

  suite_add_tcase(s, tc);

  return s;
}
