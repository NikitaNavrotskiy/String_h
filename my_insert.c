#include "my_string.h"

void *my_insert(const char *src, const char *str, my_size_t start_index) {
  my_size_t src_len = (src != my_NULL) ? my_strlen(src) : 0;
  my_size_t str_len = (str != my_NULL) ? my_strlen(str) : 0;
  char *tmp_1 = (char *)src;
  char *tmp_2 = (char *)str;
  char *res = my_NULL;
  if (tmp_1 && tmp_2 && start_index <= my_strlen(src)) {
    res = calloc(src_len + str_len + 1, sizeof(char));
    if (res) {
      for (my_size_t i = 0; i < start_index; i++) res[i] = tmp_1[i];
      for (my_size_t i = start_index; i < start_index + str_len; i++)
        res[i] = tmp_2[i - start_index];
      for (my_size_t i = start_index + str_len; i < src_len + str_len; i++)
        res[i] = tmp_1[i - str_len];
    }
  }
  return (void *)res;
}