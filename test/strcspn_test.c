#include "string_test.h"

START_TEST(strcspn_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  char str1[] = "Abc";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  char str1[] = "abc";
  char str2[] = "Abc";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  char str1[] = "abC";
  char str2[] = "\n\n";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  char str1[] = "    abc";
  char str2[] = "fa";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  char str1[] = "ABC";
  char str2[] = "ffffffffffffA";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  char str1[] = "\0\0\0";
  char str2[] = "ABC";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  char str1[] = "a b c";
  char str2[] = "cba";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9) {
  char str1[] = "\0\0\0";
  char str2[] = "\0\0\0";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_10) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), my_strcspn(str1, str2));
}
END_TEST

Suite *suite_strcspn() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strcspn");
  tc = tcase_create("case_strcspn");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);

  suite_add_tcase(s, tc);

  return s;
}