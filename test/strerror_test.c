#include "string_test.h"
#if defined(__APPLE__) || defined(__MACH__)
const char *RES = "Undefined error: 0";
#elif defined(__linux__)
const char *RES = "Success";
#endif

START_TEST(strerror_1) {
  for (int i = MIN_ERR; i <= MAX_ERR; i++)
    ck_assert_str_eq(my_strerror(i), strerror(i));
}
END_TEST

START_TEST(strerror_2) {
  char *err = my_strerror(444);
  ck_assert_str_eq(err, "Unknown error: 444");
}
END_TEST

Suite *suite_strerror() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_strerror");
  tc = tcase_create("case_strerror");

  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);

  suite_add_tcase(s, tc);

  return s;
}
