#include "my_string.h"

my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t count = 0;
  int brk = 0;

  while (*str1 != '\0' && !brk)
    if (my_strchr(str2, *str1++) == my_NULL)
      ++count;
    else
      brk = 1;

  return count;
}