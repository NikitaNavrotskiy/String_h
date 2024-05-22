#include "my_string.h"

int my_memcmp(const void *dest, const void *src, my_size_t n) {
  int res = 0;
  int brk = 0;
  unsigned char u1, u2;

  while (n-- > 0 && !brk) {
    u1 = (unsigned char)*(char *)dest++;
    u2 = (unsigned char)*(char *)src++;
    if (u1 != u2) {
      res = u1 - u2;
      brk = 1;
    }
    if (u1 == '\0') brk = 1;
  }

  return res;
}