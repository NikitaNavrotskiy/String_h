#include "my_string.h"

char *my_strstr(const char *haystack, const char *needle) {
  char *str1 = (char *)haystack, *str2 = (char *)needle, *res = my_NULL;
  my_size_t i = 0;
  int stop_i = 0;
  for (; str1[i] != '\0' && !stop_i; i++) {
    int stop_j = 0;
    for (my_size_t j = 0; *(str2 + j) != '\0' && !stop_j; j++) {
      if (str1[i + j] != str2[j]) stop_j = 1;
    }
    if (!stop_j) {
      stop_i = 1;
      res = str1 + i;
    }
  }
  return res;
}