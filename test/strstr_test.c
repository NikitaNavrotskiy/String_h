#include "string_test.h"

START_TEST(strstr_1) {
  const char str[] = "Hello, world!";
  const char subStr1[] = "world";
  const char subStr2[] = " ";
  ck_assert_str_eq(my_strstr(str, subStr1), strstr(str, subStr1));
  ck_assert_str_eq(my_strstr(str, subStr2), strstr(str, subStr2));
}
END_TEST

START_TEST(strstr_2) {
  const char str[] = "Hello, world!";
  const char subStr1[] = "wo";
  const char subStr2[] = "aa";
  ck_assert_str_eq(my_strstr(str, subStr1), strstr(str, subStr1));
  ck_assert_ptr_eq(my_strstr(str, subStr2), strstr(str, subStr2));
}
END_TEST

START_TEST(strstr_3) {
  const char str[] = "Hello, world!";
  const char subStr1[] = "H";
  const char subStr2[] = "4";
  ck_assert_str_eq(my_strstr(str, subStr1), strstr(str, subStr1));
  ck_assert_ptr_eq(my_strstr(str, subStr2), strstr(str, subStr2));
}
END_TEST

START_TEST(strstr_4) {
  const char str[] = "Hello, world!";
  const char subStr1[] = "ow";
  const char subStr2[] = "3";
  ck_assert_ptr_eq(my_strstr(str, subStr1), strstr(str, subStr1));
  ck_assert_ptr_eq(my_strstr(str, subStr2), strstr(str, subStr2));
}
END_TEST

START_TEST(strstr_5) {
  const char str[] = "Hello, world!";
  const char subStr1[] = "d!";
  const char subStr2[] = "\r";
  ck_assert_str_eq(my_strstr(str, subStr1), strstr(str, subStr1));
  ck_assert_ptr_eq(my_strstr(str, subStr2), strstr(str, subStr2));
}
END_TEST

Suite *suite_strstr() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strstr");
  tc = tcase_create("case_strstr");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);

  suite_add_tcase(s, tc);

  return s;
}