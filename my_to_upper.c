#include "my_string.h"

void *my_to_upper(const char *str) {
  char *tmp = (char *)str;
  char *res = my_NULL;
  if (tmp) {
    res = calloc(my_strlen(str) + 1, sizeof(char));
    if (res) {
      for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] >= 97 && tmp[i] <= 122)
          res[i] = tmp[i] - 32;
        else
          res[i] = tmp[i];
      }
    }
  }
  return (void *)res;
}
