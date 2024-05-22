#include "my_string.h"

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  void *res = dest;

  while (n--) *((char *)dest++) = *((char *)src++);

  return res;
}