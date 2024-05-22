#include "my_string.h"

void *my_to_lower(const char *str) {
  char *tmp = (char *)str;
  char *res = my_NULL;
  if (tmp) {
    res = calloc(my_strlen(str) + 1, sizeof(char));
    if (res) {
      for (int i = 0; tmp[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
          res[i] = tmp[i] + 32;
        else
          res[i] = tmp[i];
      }
    }
  }
  return (void *)res;
}