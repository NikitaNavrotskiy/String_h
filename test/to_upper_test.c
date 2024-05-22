#include "string_test.h"

START_TEST(to_upper_1) {
  const char str[] = "hello";
  const char res[] = "HELLO";
  char *res_ = (char *)my_to_upper(str);
  ck_assert_str_eq(res_, res);
  if (res_) free(res_);
}
END_TEST

START_TEST(to_upper_2) {
  const char str[] = "244 24\n24 \roOOOOo";
  const char res[] = "244 24\n24 \rOOOOOO";
  char *res_ = (char *)my_to_upper(str);
  ck_assert_str_eq(res_, res);
  if (res_) free(res_);
}
END_TEST

START_TEST(to_upper_3) {
  const char str[] = "HELLO";
  const char res[] = "HELLO";
  char *res_ = (char *)my_to_upper(str);
  ck_assert_str_eq(res_, res);
  if (res_) free(res_);
}
END_TEST

START_TEST(to_upper_4) {
  const char str[] = "\0";
  const char res[] = "\0";
  char *res_ = (char *)my_to_upper(str);
  ck_assert_str_eq(res_, res);
  if (res_) free(res_);
}
END_TEST

Suite *suite_to_upper() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_to_upper");
  tc = tcase_create("case_to_upper");

  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_upper_3);
  tcase_add_test(tc, to_upper_4);

  suite_add_tcase(s, tc);

  return s;
}