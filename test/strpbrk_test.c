#include "string_test.h"

START_TEST(strpbrk_1) {
  const char str[] = "Hello, world!";
  const char chars1[] = "whzo";
  ck_assert_str_eq(my_strpbrk(str, chars1), strpbrk(str, chars1));
}
END_TEST

START_TEST(strpbrk_2) {
  const char str[] = "Hello, world!";
  const char chars1[] = "OL?";
  ck_assert_ptr_eq(my_strpbrk(str, chars1), strpbrk(str, chars1));
}
END_TEST

START_TEST(strpbrk_3) {
  const char str[] = "Hello, world!";
  const char chars1[] = "\0\r";
  ck_assert_ptr_eq(my_strpbrk(str, chars1), strpbrk(str, chars1));
}
END_TEST

START_TEST(strpbrk_4) {
  const char str[] = "Hello, world!\n\r";
  const char chars1[] = "\0\r";
  ck_assert_ptr_eq(my_strpbrk(str, chars1), strpbrk(str, chars1));
}
END_TEST

START_TEST(strpbrk_5) {
  const char str[] = "\0";
  const char chars1[] = "\0\r";
  ck_assert_ptr_eq(my_strpbrk(str, chars1), strpbrk(str, chars1));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strpbrk");
  tc = tcase_create("case_strpbrk");

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);

  suite_add_tcase(s, tc);

  return s;
}