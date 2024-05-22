#include "my_string.h"

char *my_strrchr(const char *str, int c) {
  const char *res = my_NULL;

  if (c) {
    while ((str = my_strchr(str, c))) {
      res = str;
      str++;
    }
  } else if (c == 0)
    res = str + my_strlen(str);
  else {
    res = my_strchr(str, c);
  }

  return (char *)res;
}