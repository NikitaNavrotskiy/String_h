#include "my_string.h"

my_size_t my_strlen(const char *str) {
  my_size_t len = 0;

  while (*str != '\0') {
    len++;
    str++;
  }

  return len;
}