#include "string_test.h"

START_TEST(memchr_1) {
  char str1[] = "abc";
  int c = 'n';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char str1[] = "abcaf af  af a";
  int c = 'f';
  size_t n = 14;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char str1[] = "abc ";
  int c = '-';
  size_t n = 4;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char str1[] = "";
  int c = 'd';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char str1[] = "ab";
  int c = '\0';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char str1[] = "abcdefgaga af  af";
  int c = 'b';
  size_t n = 17;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_7) {
  char str1[] = "abc\t";
  int c = '\t';
  size_t n = 4;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_8) {
  char str1[] = "\n\n\n\n\n";
  int c = 'n';
  size_t n = 5;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_9) {
  char str1[] = "\n\n\n\n\n";
  int c = '\n';
  size_t n = 5;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_10) {
  char str1[] = "\0\0\0\0\0\0\0\0";
  int c = 'c';
  size_t n = 9;
  ck_assert_ptr_eq(memchr(str1, c, n), my_memchr(str1, c, n));
}
END_TEST

Suite *suite_memchr() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_memchr");
  tc = tcase_create("case_memchr");

  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);
  tcase_add_test(tc, memchr_9);
  tcase_add_test(tc, memchr_10);

  suite_add_tcase(s, tc);

  return s;
}
