#include "string_test.h"

START_TEST(strlen_test_1) {
  char *str = "Hello, world!";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_2) {
  char *str = "Hello, \0world!";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_3) {
  char *str = "";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_4) {
  char *str = "\0";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_5) {
  char *str = ",,,,!";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_6) {
  char *str = "            ";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_7) {
  char *str = "afaff sfaf fs afaffaffd f affffsa ggag egegws g ";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_8) {
  char *str = "........... ";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_9) {
  char *str = "\t\t\t\t\t";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_10) {
  char *str = "\t\r";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_11) {
  char *str = "\n\n\n\n\n\n\n\n";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_12) {
  char *str = "\\\\\\\\";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_13) {
  char *str = "faffgfafa fff af af afa a";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_14) {
  char *str = "Hello, world!\0";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_15) {
  char *str = " ";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

Suite *suite_strlen() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strlen");
  tc = tcase_create("case_strlen");

  tcase_add_test(tc, strlen_test_1);
  tcase_add_test(tc, strlen_test_2);
  tcase_add_test(tc, strlen_test_3);
  tcase_add_test(tc, strlen_test_4);
  tcase_add_test(tc, strlen_test_5);
  tcase_add_test(tc, strlen_test_6);
  tcase_add_test(tc, strlen_test_7);
  tcase_add_test(tc, strlen_test_8);
  tcase_add_test(tc, strlen_test_9);
  tcase_add_test(tc, strlen_test_10);
  tcase_add_test(tc, strlen_test_11);
  tcase_add_test(tc, strlen_test_12);
  tcase_add_test(tc, strlen_test_13);
  tcase_add_test(tc, strlen_test_14);
  tcase_add_test(tc, strlen_test_15);

  suite_add_tcase(s, tc);

  return s;
}