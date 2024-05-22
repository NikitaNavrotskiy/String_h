#include "my_string.h"

char *my_strpbrk(const char *str1, const char *str2) {
  int stop = 0;
  char *res = my_NULL;
  for (int i = 0; str1[i] != '\0' && !stop; i++) {
    if (my_strchr(str2, str1[i])) {
      res = (char *)str1 + i;
      stop = 1;
    }
  }
  return res;
}