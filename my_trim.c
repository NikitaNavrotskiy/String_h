#include "my_string.h"

void *my_trim(const char *src, const char *trim_chars) {
  char *res = my_NULL;
  if (src != my_NULL) {
    if (trim_chars == NULL || trim_chars[0] == '\0') trim_chars = " ";
    my_size_t len = my_strlen(src);
    if (len > 0) {
      int start = -1, end = -1, flag_1 = 1, flag_2 = 1, stop = 0;
      for (my_size_t i = 0, j = len - 1; i < len && !stop; i++, j--) {
        if (my_strchr(trim_chars, src[i]) == my_NULL && flag_1) {
          start = i;
          flag_1 = 0;
        }
        if (my_strchr(trim_chars, src[j]) == my_NULL && flag_2) {
          end = j;
          flag_2 = 0;
        }
        if (!flag_1 && !flag_2) stop = 1;
      }
      res = calloc(end - start + 2, sizeof(char));
      if (res != my_NULL) {
        for (int i = start, j = 0; i <= end; i++, j++) res[j] = src[i];
      }
    } else
      res = calloc(2, sizeof(char));
  }
  return res;
}