#include "string_test.h"

START_TEST(strncat_1) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "def";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_2) {
  char str1[9] = "ab\nc";
  char str2[9] = "ab\nc";
  char str3[] = "def";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_3) {
  char str1[9] = "ab\0c";
  char str2[9] = "ab\0c";
  char str3[] = "def";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_4) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "de\0f";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_5) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "de\nf";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_6) {
  char str1[9] = "ab\0c";
  char str2[9] = "ab\0c";
  char str3[] = "def";
  int n = 4;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_7) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "de\0f";
  int n = 4;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_8) {
  char str1[9] = "";
  char str2[9] = "";
  char str3[] = "def";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_9) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

START_TEST(strncat_10) {
  char str1[9] = "abc";
  char str2[9] = "abc";
  char str3[] = "def";
  int n = 3;
  ck_assert_str_eq(strncat(str1, str3, n), my_strncat(str2, str3, n));
}
END_TEST

Suite *suite_strncat() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strncat");
  tc = tcase_create("case_strncat");

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);

  suite_add_tcase(s, tc);

  return s;
}
