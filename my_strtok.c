#include "my_string.h"

char *my_strtok(char *str, const char *delim) {
  char *res = my_NULL;
  static char *token;
  static char *next;
  unsigned int i;
  int flag = 0;
  if (str != my_NULL) next = str;
  token = next;
  if (token == my_NULL) {
    res = my_NULL;
    flag = 1;
  }
  if (!flag) {
    for (i = 0; next[i] != '\0'; i++) {
      if (!my_strchr(delim, next[i])) break;
    }
    if (next[i] == '\0') {
      next = my_NULL;
      res = my_NULL;
      flag = 1;
    }
    token = next + i;
    next = token;
    for (i = 0; next[i] != '\0' && !flag; i++) {
      if (my_strchr(delim, next[i])) break;
    }
    if (next[i] == '\0' && !flag)
      next = my_NULL;
    else {
      if (!flag) {
        next[i] = '\0';
        next = next + i + 1;
        if (*next == '\0') next = my_NULL;
      }
    }
    res = token;
  }
  return res;
}