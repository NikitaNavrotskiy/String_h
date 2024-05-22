#include "string_test.h"

START_TEST(strncpy_1) {
  char str1[9] = "abc";
  char str2[] = "def";
  char str3[9] = "abc";
  my_size_t n = 1;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_2) {
  char str1[9] = "ab\nc";
  char str2[] = "def";
  char str3[9] = "ab\nc";
  int n = 1;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_3) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 1;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_4) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 1;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_5) {
  char str1[9] = "abc";
  char str2[] = "de\nf";
  char str3[9] = "abc";
  int n = 1;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_6) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 4;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_7) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 4;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_8) {
  char str1[9] = "";
  char str2[] = "def";
  char str3[9] = "";
  int n = 3;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_9) {
  char str1[9] = "abc";
  char str2[] = "";
  char str3[9] = "abc";
  int n = 1;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_10) {
  char str1[9] = "   ";
  char str2[] = "\0\0";
  char str3[9] = "   ";
  int n = 1;
  strncpy(str1, str2, n);
  my_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

Suite *suite_strncpy() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strncpy");
  tc = tcase_create("case_strncpy");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);
  tcase_add_test(tc, strncpy_8);
  tcase_add_test(tc, strncpy_9);
  tcase_add_test(tc, strncpy_10);

  suite_add_tcase(s, tc);

  return s;
}