#include "string_test.h"

START_TEST(to_lower_1) {
  const char str[] = "HELLO";
  const char res[] = "hello";
  char *res_ = (char *)my_to_lower(str);
  ck_assert_str_eq(res_, res);
  if (res_) free(res_);
}
END_TEST

START_TEST(to_lower_2) {
  const char str[] = "HElLO";
  const char res[] = "hello";
  char *res_ = (char *)my_to_lower(str);
  ck_assert_str_eq(res_, res);
  if (res_) free(res_);
}
END_TEST

START_TEST(to_lower_3) {
  const char str[] = "144224OoHhHl\r\n";
  const char res[] = "144224oohhhl\r\n";
  char *res_ = (char *)my_to_lower(str);
  ck_assert_str_eq(res_, res);
  if (res_) free(res_);
}
END_TEST

START_TEST(to_lower_4) {
  const char str[] = "\0";
  const char res[] = "\0";
  char *res_ = (char *)my_to_lower(str);
  ck_assert_str_eq(res_, res);
  if (res_) free(res_);
}
END_TEST

Suite *suite_to_lower() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_to_lower");
  tc = tcase_create("case_to_lower");

  tcase_add_test(tc, to_lower_1);
  tcase_add_test(tc, to_lower_2);
  tcase_add_test(tc, to_lower_3);
  tcase_add_test(tc, to_lower_4);

  suite_add_tcase(s, tc);

  return s;
}