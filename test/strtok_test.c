#include "string_test.h"

START_TEST(strtok_1) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "c";
  ck_assert_str_eq(strtok(str1, str2), my_strtok(str3, str2));
}
END_TEST

START_TEST(strtok_2) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "b";
  ck_assert_str_eq(strtok(str1, str2), my_strtok(str3, str2));
}
END_TEST

START_TEST(strtok_3) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "a";
  ck_assert_str_eq(strtok(str1, str2), my_strtok(str3, str2));
}
END_TEST

START_TEST(strtok_4) {
  char str1[] = "abb";
  char str3[] = "abb";
  char str2[] = "\n";
  ck_assert_str_eq(strtok(str1, str2), my_strtok(str3, str2));
}
END_TEST

START_TEST(strtok_5) {
  char str1[] = "aaabbcc";
  char str3[] = "aaabbcc";
  char str2[] = "a";
  ck_assert_str_eq(strtok(str1, str2), my_strtok(str3, str2));
}
END_TEST

START_TEST(strtok_6) {
  char str1[] = "aaabbcc";
  char str3[] = "aaabbcc";
  char str2[] = "b";
  strtok(str1, str2);
  my_strtok(str3, str2);

  ck_assert_str_eq(strtok(NULL, str2), my_strtok(my_NULL, str2));
}
END_TEST

START_TEST(strtok_7) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "d";
  ck_assert_str_eq(strtok(str1, str2), my_strtok(str3, str2));
}
END_TEST

START_TEST(strtok_8) {
  char str1[] = "123";
  char str3[] = "123";
  char str2[] = " 2";
  strtok(str1, str2);
  my_strtok(str3, str2);
  ck_assert_str_eq(strtok(NULL, str2), my_strtok(my_NULL, str2));
}
END_TEST

START_TEST(strtok_9) {
  char str1[] = "1\023";
  char str3[] = "1\023";
  char str2[] = "\0";
  ck_assert_str_eq(strtok(str1, str2), my_strtok(str3, str2));
}
END_TEST

Suite *suite_strtok() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strtok");
  tc = tcase_create("case_strtok");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);

  suite_add_tcase(s, tc);

  return s;
}
