#include "string_test.h"

START_TEST(memcpy_1) {
  char str1[9] = "abc";
  char str2[] = "def";
  char str3[9] = "abc";
  my_size_t n = 1;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_2) {
  char str1[9] = "ab\nc";
  char str2[] = "def";
  char str3[9] = "ab\nc";
  int n = 1;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_3) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 1;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_4) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 1;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_5) {
  char str1[9] = "abc";
  char str2[] = "de\nf";
  char str3[9] = "abc";
  int n = 1;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_6) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 4;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_7) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 4;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_8) {
  char str1[9] = "";
  char str2[] = "def";
  char str3[9] = "";
  int n = 3;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_9) {
  char str1[9] = "abc";
  char str2[] = "";
  char str3[9] = "abc";
  int n = 1;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_10) {
  char str1[9] = "   ";
  char str2[] = "\0\0";
  char str3[9] = "   ";
  int n = 1;
  memcpy(str1, str2, n);
  my_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

Suite *suite_memcpy() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_memcpy");
  tc = tcase_create("case_memcpy");

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);
  tcase_add_test(tc, memcpy_7);
  tcase_add_test(tc, memcpy_8);
  tcase_add_test(tc, memcpy_9);
  tcase_add_test(tc, memcpy_10);

  suite_add_tcase(s, tc);

  return s;
}