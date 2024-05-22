#include "string_test.h"

START_TEST(trim_1) {
  char src[] = "  hello  ";
  const char chars[] = " !";
  ck_assert_str_eq((char *)my_trim(src, chars), "hello");
  ck_assert_ptr_null(my_trim(my_NULL, my_NULL));
  char *res_ = (char *)my_trim(src, chars);
  if (res_) free(res_);
}
END_TEST

START_TEST(trim_2) {
  char str[] = "!!world!!!";
  const char chars[] = " !";
  ck_assert_str_eq((char *)my_trim(str, chars), "world");
  char *res_ = (char *)my_trim(str, chars);
  if (res_) free(res_);
}
END_TEST

START_TEST(trim_3) {
  char src[] = "  hello  \n";
  const char chars[] = " \n";
  ck_assert_str_eq((char *)my_trim(src, chars), "hello");
  char *res_ = (char *)my_trim(src, chars);
  if (res_) free(res_);
}
END_TEST

START_TEST(trim_4) {
  char str[] = "!!world!!!";
  const char chars[] = "";
  char *res_ = (char *)my_trim(str, chars);
  ck_assert_str_eq((char *)my_trim(str, chars), "!!world!!!");
  if (res_) free(res_);
}
END_TEST

START_TEST(trim_5) {
  char str[] = "!!world!!!";
  const char chars[] = "\0";
  char *res_ = (char *)my_trim(str, chars);
  ck_assert_str_eq(res_, "!!world!!!");
  if (res_) free(res_);
}
END_TEST

Suite *suite_trim() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_trim");
  tc = tcase_create("case_trim");

  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);

  suite_add_tcase(s, tc);

  return s;
}