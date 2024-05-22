#ifndef SRC_MY_SPRINTF_H_
#define SRC_MY_SPRINTF_H_

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "my_string.h"

// %[flags][width][.prec][lengh]spec

#define FROM_ARG -1
#define EMPTY_FLAG -2
#define EMPTY_PREC -3

typedef struct {
  char flags[5];
  int width;
  int prec;
  char len;
  char spec;
} spec;

int get_flags(spec *sp, const char *format);
int get_width(spec *sp, const char *format);
int get_prec(spec *sp, const char *format);
int get_len(spec *sp, const char *format);
int get_spec(spec *sp, const char *format);
int is_flag(char c, spec *sp);

int rm_zeroes_from_end(char *str);

int fill(char c, char *str, int len_for_format, int width);

int number_len(__int128_t num, int base, char len_spec);

int proc_format(spec *sp, char *str, const char *format, va_list *list,
                int *str_offset, int cur_printed_chars);

void proc_format_nums(spec *sp, char *str, va_list *list, int *str_offset);

void proc_format_others(spec *sp, char *str, va_list *list, int *str_offset,
                        int cur_printed_chars);

#endif