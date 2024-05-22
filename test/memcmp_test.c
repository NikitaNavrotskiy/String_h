#include "string_test.h"

START_TEST(memcmp_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "Abc";
  char str2[] = "abc";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "abc";
  char str2[] = "Abc";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "abC";
  char str2[] = "abc";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "abc";
  char str2[] = "abC";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_6) {
  char str1[] = "AB ";
  char str2[] = "abc";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "abc";
  char str2[] = "AB  ";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_8) {
  char str1[] = "a\nb c";
  char str2[] = "abc";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_9) {
  char str1[] = "abc";
  char str2[] = "a\tb c";
  int n = 3;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);

  ck_assert_int_eq(my, s);
}
END_TEST

START_TEST(memcmp_10) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 1;
  int my = my_memcmp(str1, str2, n);
  int s = memcmp(str1, str2, n);
  ck_assert_int_eq(my, s);
}
END_TEST

Suite *suite_memcmp() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_memcmp");
  tc = tcase_create("case_memcmp");
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);

  suite_add_tcase(s, tc);

  return s;
}
