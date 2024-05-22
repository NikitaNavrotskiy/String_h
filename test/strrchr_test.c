#include "string_test.h"

START_TEST(strrchr_1) {
  char str1[] = "abc";
  int c = 'a';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_2) {
  char str1[] = "abc";
  int c = 'c';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_3) {
  char str1[] = "  abc";
  int c = 'b';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_4) {
  char str1[] = "\n\n\n\n\n";
  int c = 'n';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_5) {
  char str1[] = "\n\n\n\n\n";
  int c = '\n';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_6) {
  char str1[] = "\0\0\0\0\0";
  int c = '\0';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_7) {
  char str1[] = "\t\t\t\r\r\r\t";
  int c = '\r';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_8) {
  char str1[] = "Hello world";
  int c = 'o';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_9) {
  char str1[] = "aaaaaaaa";
  int c = 'a';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

START_TEST(strrchr_10) {
  char str1[] = "aaaaaaaaa";
  int c = 'A';
  ck_assert_ptr_eq(strrchr(str1, c), my_strrchr(str1, c));
}
END_TEST

Suite *suite_strrchr() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strtok");
  tc = tcase_create("case_strtok");

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);

  suite_add_tcase(s, tc);

  return s;
}