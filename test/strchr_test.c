#include "string_test.h"

START_TEST(strchr_1) {
  char str1[] = "abc";
  int c = 'a';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_2) {
  char str1[] = "abc";
  int c = 'c';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_3) {
  char str1[] = "  abc";
  int c = 'b';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_4) {
  char str1[] = "\n\n\n\n\n";
  int c = 'n';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_5) {
  char str1[] = "\n\n\n\n\n";
  int c = '\n';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_6) {
  char str1[] = "\0\0\0\0\0";
  int c = '0';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_7) {
  char str1[] = "\t\t\t\r\r\r\t";
  int c = '\r';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_8) {
  char str1[] = "Hello world";
  int c = 'o';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_9) {
  char str1[] = "aaaaaaaa";
  int c = 'a';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

START_TEST(strchr_10) {
  char str1[] = "aaaaaaaaa";
  int c = 'A';
  ck_assert_ptr_eq(strchr(str1, c), my_strchr(str1, c));
}
END_TEST

Suite *suite_strchr() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strchr");
  tc = tcase_create("case_strtok");

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);

  suite_add_tcase(s, tc);

  return s;
}