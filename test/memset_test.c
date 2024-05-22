#include "string_test.h"

START_TEST(test_my_memset_1) {
  char test[] = "abcdef";
  char test1[] = "abcdef";
  int c = 'z';
  my_size_t n = 3;
  ck_assert_str_eq((char *)my_memset(test, c, n), (char *)memset(test1, c, n));
}
END_TEST

START_TEST(test_my_memset_2) {
  char test[] = "abcdef";
  char test1[] = "abcdef";
  int c = '\0';
  my_size_t n = 3;
  ck_assert_str_eq((char *)my_memset(test, c, n), (char *)memset(test1, c, n));
}
END_TEST

START_TEST(test_my_memset_3) {
  char test[] = "abcdef";
  char test1[] = "abcdef";
  int c = '\n';
  my_size_t n = 3;
  ck_assert_str_eq((char *)my_memset(test, c, n), (char *)memset(test1, c, n));
}
END_TEST

START_TEST(test_my_memset_4) {
  char test[] = "abcdef";
  char test1[] = "abcdef";
  int c = '\r';
  my_size_t n = 3;
  ck_assert_str_eq((char *)my_memset(test, c, n), (char *)memset(test1, c, n));
}
END_TEST

START_TEST(test_my_memset_5) {
  char test[] = "abcdef";
  char test1[] = "abcdef";
  int c = '1';
  my_size_t n = 3;
  ck_assert_str_eq((char *)my_memset(test, c, n), (char *)memset(test1, c, n));
}
END_TEST

Suite *suite_memset() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_memset");
  tc = tcase_create("case_memset");

  tcase_add_test(tc, test_my_memset_1);
  tcase_add_test(tc, test_my_memset_2);
  tcase_add_test(tc, test_my_memset_3);
  tcase_add_test(tc, test_my_memset_4);
  tcase_add_test(tc, test_my_memset_5);

  suite_add_tcase(s, tc);

  return s;
}