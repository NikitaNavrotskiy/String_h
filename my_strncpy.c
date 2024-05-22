#include "my_string.h"

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  char *res = dest;

  while (n--) *dest++ = *src++;
  return res;
}