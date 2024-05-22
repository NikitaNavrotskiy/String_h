#include "string_test.h"

int main() {
  run();
  return 0;
}

void run() {
  Suite *list[] = {
      suite_sprintf(),  suite_strlen(),   suite_memchr(),
      suite_memcpy(),   suite_strncat(),  suite_strncmp(),
      suite_strcspn(),  suite_strrchr(),  suite_strtok(),
      suite_memcmp(),   suite_memset(),   suite_strchr(),
      suite_strncpy(),  suite_strpbrk(),  suite_strstr(),
      suite_to_upper(), suite_to_lower(), suite_insert(),
      suite_trim(),     suite_strerror(), NULL,
  };

  for (Suite **cur = list; *cur; cur++) run_one_test(*cur);
}

void run_one_test(Suite *test) {
  SRunner *sr = srunner_create(test);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}