#include "my_string.h"

char *my_strncat(char *dest, const char *src, my_size_t n) {
  char *res = dest;

  while (*dest != '\0') dest++;

  while (n--) *dest++ = *src++;
  *dest = '\0';

  return res;
}