#include "my_string.h"

void *my_memchr(const void *str, int c, my_size_t n) {
  int flag = 0;
  char *res = my_NULL;

  for (my_size_t i = 0; i < n && !flag; i++) {
    if (((char *)str)[i] == c) {
      res = (char *)(str + i);
      flag = 1;
    }
  }

  return (void *)res;
}