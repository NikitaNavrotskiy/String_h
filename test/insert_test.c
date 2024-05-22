#include "string_test.h"

START_TEST(test_my_insert_1) {
  const char src[] = "Hello, hello!";
  const char str[] = "world";
  char *res_ = (char *)my_insert(src, str, 7);
  ck_assert_str_eq(res_, "Hello, worldhello!");
  if (res_) free(res_);
}
END_TEST

START_TEST(test_my_insert_2) {
  const char src[] = "Hello, hello!";
  const char str[] = "world";
  char *res_ = (char *)my_insert(src, str, 0);
  ck_assert_str_eq(res_, "worldHello, hello!");
  if (res_) free(res_);
}
END_TEST

START_TEST(test_my_insert_3) {
  const char src[] = "Hello, hello!";
  const char str[] = "world";
  char *res_ = (char *)my_insert(src, str, 13);
  ck_assert_str_eq(res_, "Hello, hello!world");
  if (res_) free(res_);
}
END_TEST

Suite *suite_insert() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_insert");
  tc = tcase_create("case_insert");

  tcase_add_test(tc, test_my_insert_1);
  tcase_add_test(tc, test_my_insert_2);
  tcase_add_test(tc, test_my_insert_3);

  suite_add_tcase(s, tc);

  return s;
}
