#include "my_string.h"

char *my_strchr(const char *str, int c) {
  char *tmp = (char *)str;
  char *res = (c == '\0') ? "\0" : my_NULL;
  my_size_t i = 0;
  while (tmp[i] != '\0' && tmp[i] != c) i++;
  if (*(tmp + i) != '\0') res = tmp + i;
  return res;
}