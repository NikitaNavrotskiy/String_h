#include "string_test.h"

START_TEST(strncmp_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_2) {
  char str1[] = "Abc";
  char str2[] = "abc";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_3) {
  char str1[] = "abc";
  char str2[] = "Abc";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_4) {
  char str1[] = "abC";
  char str2[] = "abc";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_5) {
  char str1[] = "abc";
  char str2[] = "abC";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_6) {
  char str1[] = "AB ";
  char str2[] = "abc";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_7) {
  char str1[] = "abc";
  char str2[] = "AB  ";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_8) {
  char str1[] = "a\nb c";
  char str2[] = "abc";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_9) {
  char str1[] = "abc";
  char str2[] = "a\tb c";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);

  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(strncmp_10) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 3;
  int my = my_strncmp(str1, str2, n);
  int s = strncmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

Suite *suite_strncmp() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strncmp");
  tc = tcase_create("case_strncmp");
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);

  suite_add_tcase(s, tc);

  return s;
}
