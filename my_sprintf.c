#include "my_sprintf.h"

#include "my_string.h"

int my_sprintf(char *str, const char *format, ...) {
  int is_frmt = 0;
  int str_offset = 0;
  int offset = 0;
  va_list list;
  va_start(list, format);
  int res = 0;

  if (str != my_NULL) {
    while (*format != '\0') {
      if (*format == '%') {
        is_frmt = 1;
        format++;
      } else
        is_frmt = 0;
      if (!is_frmt) {
        *str++ = *format++;
        res++;
      } else {
        spec sp = {0};
        sp.prec = EMPTY_PREC;
        offset = proc_format(&sp, str, format, &list, &str_offset, res);
        format += offset;
        str += str_offset;
        is_frmt = 0;
        res += str_offset;
      }
    }

    *str = '\0';
  } else
    res = -1;

  va_end(list);

  return res;
}

int get_flags(spec *sp, const char *format) {
  int stop = 0;
  int offset = 0;
  char *flags = "-+ #0";
  int i, j;
  for (i = 0; i < 5 && !stop; i++) {
    if (format[i] != '-' && format[i] != '+' && format[i] != ' ' &&
        format[i] != '#' && format[i] != '0')
      stop = 1;
    for (j = 0; j < 5 && !stop; j++) {
      if (format[i] == flags[j]) {
        sp->flags[i] = flags[j];
        offset += 1;
      }
    }
  }
  if (stop == 1 && i == 1) sp->flags[0] = EMPTY_FLAG;

  return offset;
}

int get_width(spec *sp, const char *format) {
  int offset = 0;
  if (*format == '*') {
    sp->width = FROM_ARG;
    offset = 1;
  } else {
    sp->width = atoi(format);
    if (sp->width > 0)
      while (*format <= '9' && *format >= '0') {
        offset += 1;
        format++;
      }
  }

  return offset;
}

int get_prec(spec *sp, const char *format) {
  int offset = 0;
  if (*format == '.') {
    format++;
    offset += 1;
    if (*format == '*') {
      sp->prec = FROM_ARG;
      offset++;
    } else {
      sp->prec = atoi(format);
      if (*format != '0' && sp->prec == 0) sp->prec = EMPTY_PREC;
      if (sp->prec > 0 || *format == '0')
        while (*format <= '9' && *format >= '0') {
          offset += 1;
          format++;
        }
    }
  }

  return offset;
}

int get_len(spec *sp, const char *format) {
  int offset = 0;

  if (*format == 'h' || *format == 'l' || *format == 'L') {
    sp->len = *format;
    offset++;
  }

  return offset;
}

int get_spec(spec *sp, const char *format) {
  int offset = 0;
  int global_offset = 0;

  offset = get_flags(sp, format);
  format += offset;
  global_offset += offset;

  offset = get_width(sp, format);
  format += offset;
  global_offset += offset;

  offset = get_prec(sp, format);
  format += offset;
  global_offset += offset;

  offset = get_len(sp, format);
  format += offset;
  global_offset += offset;

  sp->spec = *format;
  offset = 1;
  global_offset += offset;

  return global_offset;
}

int is_flag(char c, spec *sp) {
  int ret = 0;
  for (int i = 0; i < 5 && !ret; i++) {
    if (sp->flags[i] == c) ret = 1;
  }
  return ret;
}

int fill(char c, char *str, int len_for_format, int width) {
  int offset = 0;
  for (int i = 0; i < width - len_for_format; i++) {
    str[i] = c;
    offset++;
  }
  return offset;
}

// 1) для целых чисел
int number_len(__int128_t num, int base, char len_spec) {
  int len = 0;
  if (num == 0) {
    len = 1;
  } else {
    if (num < 0 && base == 10)
      num = -num;
    else if (num < 0 && base != 10) {
      if (len_spec == 'h')
        num = __UINT16_MAX__ + num + 1;
      else if (len_spec == 'l')
        num = __UINT64_MAX__ + num + 1;
      else
        num = __UINT32_MAX__ + num + 1;
    }
    while (num) {
      len++;
      num /= base;
    }
  }
  return len;
}

int num_print(__int128_t num, char *str, int base, int is_up, char len_spec) {
  int res = 0;

  if (num == 0) {
    *str = '0';
    res = 1;
  } else {
    if (base != 10 && num < 0) {
      if (len_spec == 'l')
        num = __UINT64_MAX__ + num + 1;
      else if (len_spec == 'h')
        num = __UINT16_MAX__ + num + 1;
      else
        num = __UINT32_MAX__ + num + 1;
    }
    int len = number_len(num, base, len_spec);

    for (int i = len - 1; i >= 0; i--) {
      __int128_t remain = num % base;
      if (remain < 10)
        *(str + i) = remain + '0';
      else if (is_up)
        *(str + i) = remain - 10 + 'A';
      else
        *(str + i) = remain - 10 + 'a';
      num /= base;
    }
    res = len;
  }
  return res;
}

int num_format1(__int128_t num, char *str, spec *sp, int base, int is_up,
                int num_len) {
  int offset = 0, loc_offset = 0;
  if (num < 0 && base == 10 && sp->prec == 0) {
    loc_offset = fill('-', str, 0, 1);
    offset += 1;
    str += 1;
  } else if (is_flag('+', sp) && base == 10 && sp->spec != 'u' && num > 0 &&
             sp->prec == 0) {
    loc_offset = fill('+', str, 0, 1);
    offset += 1;
    str += 1;
  }
  if ((base == 8 || base == 16) && is_flag('#', sp) && sp->prec == 0) {
    fill('0', str, 0, 1);
    offset += 1;
    str += 1;
  }
  if (base == 16 && is_flag('#', sp) && sp->prec == 0) {
    if (is_up)
      fill('X', str, 0, 1);
    else
      fill('x', str, 0, 1);
    str++;
    offset++;
  }
  if (is_flag('0', sp) && sp->prec == 0) {
    loc_offset = fill('0', str, num_len, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }

  return offset;
}

int num_format2(__int128_t num, char *str, spec *sp, int base, int is_up,
                int orig_width, int count_zeroes_for_prec, int num_len) {
  int offset = 0, loc_offset = 0;
  if (!is_flag('-', sp)) {
    loc_offset =
        fill(' ', str, 0, orig_width - count_zeroes_for_prec - num_len);
    offset += loc_offset;
    str += loc_offset;
  }
  if ((base == 8 || base == 16) && is_flag('#', sp)) {
    fill('0', str, 0, 1);
    offset += 1;
    str += 1;
    if (orig_width < sp->prec && base == 8) count_zeroes_for_prec--;
  }
  if (base == 16 && is_flag('#', sp)) {
    if (is_up)
      fill('X', str, 0, 1);
    else
      fill('x', str, 0, 1);
    str++;
    offset++;
  }
  if (num < 0 && base == 10) {
    loc_offset = fill('-', str, 0, 1);
    offset += 1;
    str += 1;
  } else if (is_flag('+', sp) && base == 10 && sp->spec != 'u' && num >= 0 &&
             sp->prec != 0) {
    loc_offset = fill('+', str, 0, 1);
    offset += 1;
    str += 1;
  }
  loc_offset = fill('0', str, 0, count_zeroes_for_prec);
  offset += loc_offset;
  str += loc_offset;

  return offset;
}

int num_format(__int128_t num, char *str, spec *sp, int base, int is_up) {
  int offset = 0;
  int loc_offset = 0;
  int num_len = number_len(num, base, sp->len);
  int orig_width = sp->width;
  if (sp->prec == EMPTY_PREC) sp->prec = 0;
  int count_zeroes_for_prec = sp->prec > num_len ? sp->prec - num_len : 0;
  sp->width -= count_zeroes_for_prec;

  if ((num < 0 || is_flag('+', sp)) && base == 10 && sp->spec != 'u') num_len++;
  if (base != 10 && is_flag('#', sp)) {
    if (base == 8)
      num_len++;
    else
      num_len += 2;
  }
  if (is_flag(' ', sp) || is_flag('+', sp) || is_flag(EMPTY_FLAG, sp) ||
      (is_flag('#', sp))) {
    if (sp->width <= num_len && is_flag(' ', sp) && base == 10 &&
        sp->spec != 'u' && num > 0)
      loc_offset = fill(' ', str, 0, 1);
    else if (sp->prec != 0)
      loc_offset =
          fill(' ', str, 0,
               orig_width - count_zeroes_for_prec - num_len - sp->width);
    else
      loc_offset = fill(' ', str, num_len, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }
  loc_offset = num_format1(num, str, sp, base, is_up, num_len);
  offset += loc_offset;
  str += loc_offset;
  if (sp->prec != 0) {
    loc_offset = num_format2(num, str, sp, base, is_up, orig_width,
                             count_zeroes_for_prec, num_len);
    str += loc_offset;
    offset += loc_offset;
  }
  if (num < 0 && base == 10) num = -num;
  loc_offset = num_print(num, str, base, is_up, sp->len);
  str += loc_offset;
  offset += loc_offset;
  if (is_flag('-', sp) && !is_flag('0', sp)) {
    loc_offset = fill(' ', str, num_len, sp->width);
    offset += loc_offset;
  }

  return offset;
}

int char_format(char sym, char *str, spec *sp) {
  int offset = 0;
  int loc_offset = 0;

  if (!is_flag('-', sp)) {
    loc_offset = fill(' ', str, 1, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }

  *str = sym;
  str++;
  offset++;

  if (is_flag('-', sp)) {
    loc_offset = fill(' ', str, 1, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }

  return offset;
}

int str_format(const char *arg_str, char *str, spec *sp) {
  int offset = 0;
  int loc_offset = 0;
  size_t str_len = my_strlen(arg_str);

  if (!is_flag('-', sp)) {
    loc_offset = fill(' ', str, str_len, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }

  my_strncpy(str, arg_str, str_len);
  str += str_len;
  offset += str_len;

  if (is_flag('-', sp)) {
    loc_offset = fill(' ', str, str_len, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }

  return offset;
}

int print_num_without_first_dig(__int128_t num, char *str)  // for floats
{
  int len = number_len(num, 10, 'l') - 1;
  for (int i = len - 1; i >= 0; i--) {
    *(str + i) = num % 10 + '0';
    num /= 10;
  }
  return len;
}

int pointer_format(long long num, char *str, spec *sp) {
  int offset = 0;
  int loc_offset = 0;
  int num_len = number_len(num, 16, sp->len);

  if ((is_flag('+', sp))) num_len++;
  num_len += 2;  // for 0x
  if (is_flag(' ', sp) || is_flag('+', sp) || is_flag(EMPTY_FLAG, sp) ||
      is_flag('#', sp)) {
    loc_offset = fill(' ', str, num_len, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }
  if (is_flag('+', sp)) {
    loc_offset = fill('+', str, 0, 1);
    offset += 1;
    str += 1;
  }
  fill('0', str, 0, 1);
  offset += 1;
  str += 1;
  fill('x', str, 0, 1);
  offset += 1;
  str += 1;
  if (is_flag('0', sp)) {
    loc_offset = fill('0', str, num_len, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }
  loc_offset = num_print(num, str, 16, 0, sp->len);
  str += loc_offset;
  offset += loc_offset;
  if (is_flag('-', sp) && !is_flag('0', sp)) {
    loc_offset = fill(' ', str, num_len, sp->width);
    offset += loc_offset;
  }

  return offset;
}

int inf_print(char *str, int is_up) {
  int res = 0;
  char *inf = "inf";
  char *InF = "INF";
  if (is_up)
    for (int i = 0; i < 3; i++) *str++ = *InF++;
  else
    for (int i = 0; i < 3; i++) *str++ = *inf++;
  res += 3;
  return res;
}

int nan_print(char *str, int is_up) {
  char *nan = "-nan";
  char *NaN = "-NAN";
  if (is_up)
    for (int i = 0; i < 4; i++) *str++ = *NaN++;
  else
    for (int i = 0; i < 4; i++) *str++ = *nan++;
  return 4;
}

int fraction_len(long double num, int prec) {
  int len = 0;
  if (isinf(num))
    len = 3;
  else if (isnan(num))
    len = 4;
  else {
    if (num < 0) num = -num;
    if (prec == EMPTY_FLAG) prec = 6;
    __uint128_t integ = (__uint128_t)num;
    len += number_len(integ, 10, 'l');

    len += prec;
    if (prec > 0) len++;  // floating point
  }
  return len;
}

int frac_print(long double num, int prec, char *str) {
  int offset = 0;
  if (isnan(num))
    offset = nan_print(str, 0);
  else if (isinf(num) && num < 0)
    offset = inf_print(str, 0);
  else if (isinf(num) && num >= 0)
    offset = inf_print(str, 0);
  else {
    int loc_offset = 0;
    if (prec == EMPTY_PREC) prec = 6;

    if (num < 0) num = -num;

    __int128_t integ = (__int128_t)num;
    if (prec == 0 && (__int128_t)(num * 10) % 10 >= 5) integ++;
    loc_offset = num_print(integ, str, 10, 0, 'l');
    str += loc_offset;
    offset += loc_offset;
    if (prec > 0) {
      *str = '.';
      str++;
      offset++;
      __int128_t tmp = 1;
      num -= integ;
      while (prec) {
        num *= 10;
        prec--;
        tmp *= 10;
      }
      integ = (__int128_t)num;
      if ((__int128_t)(num * 10) % 10 >= 5) integ += 1;
      loc_offset = print_num_without_first_dig(integ + tmp, str);
      offset += loc_offset;
    }
  }
  return offset;
}

int count_zeroes_end(long double frac, spec *sp) {
  if (frac < 0) frac = -frac;
  int res = 0;
  __int128_t num;
  frac -= (long long)frac;
  for (int i = 0; i < sp->prec; i++) frac *= 10;

  num = (__int128_t)frac;

  while (num % 10 == 0 && num) {
    res++;
    num /= 10;
  }

  return res;
}

int count_non_zeroes(long double frac, spec *sp) {
  if (frac < 0) frac = -frac;
  int res = 0;
  __int128_t num;
  frac -= (long long)frac;
  if (sp->prec < 8) sp->prec = 8;
  for (int i = 0; i < sp->prec; i++) frac *= 10;

  num = (__int128_t)frac;

  while (num) {
    if (num % 10 == 0) res++;
    num /= 10;
  }

  return sp->prec - res;
}

int frac_format(long double frac, char *str, spec *sp) {
  int offset = 0;
  int loc_offset = 0;
  if (sp->prec == EMPTY_PREC) sp->prec = 6;
  int length = fraction_len(frac, sp->prec);
  if ((sp->spec == 'g' || sp->spec == 'G') && !isinf(frac) && !isnan(frac))
    length -= count_zeroes_end(frac, sp);
  if (((frac < 0 || is_flag('+', sp)) && !isnan(frac)) ||
      (frac > 0 && isinf(frac)))
    length++;
  if ((is_flag(' ', sp) || is_flag('+', sp) || is_flag(EMPTY_FLAG, sp) ||
       is_flag('#', sp)) &&
      sp->width > length)
    loc_offset = fill(' ', str, length, sp->width);
  else if (is_flag(' ', sp) && frac >= 0)
    loc_offset = fill(' ', str, 0, 1);
  offset += loc_offset;
  str += loc_offset;
  if (frac < 0 && !isinf(frac) && !isnan(frac)) {
    loc_offset = fill('-', str, 0, 1);
    offset += 1;
    str += 1;
  } else if (is_flag('+', sp) && frac >= 0) {
    loc_offset = fill('+', str, 0, 1);
    offset += 1;
    str += 1;
  }
  if (is_flag('0', sp)) {
    if (isnan(frac) || isinf(frac))
      loc_offset = fill(' ', str, length, sp->width);
    else
      loc_offset = fill('0', str, length, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }
  if (isinf(frac) && frac < 0) {
    loc_offset = fill('-', str, 0, 1);
    offset += 1;
    str += 1;
  }
  if (frac < 0) frac = -frac;
  loc_offset = frac_print(frac, sp->prec, str);
  str += loc_offset;
  offset += loc_offset;
  if (is_flag('-', sp) && !is_flag('0', sp)) {
    loc_offset = fill(' ', str, length, sp->width);
    offset += loc_offset;
  }
  return offset;
}

int exp_len(long double frac, spec *sp) {
  int prec = sp->prec;
  int res = 6;  // e + sign + 2 digits + poing
  if (sp->prec == 0)
    res = 5;
  else {
    if (prec == EMPTY_PREC) prec = 6;
    if (isnan(frac) || isinf(frac))
      res = fraction_len(frac, prec);
    else {
      if (prec == 0 && sp->spec != 'g' && sp->spec != 'G') prec = 6;

      __int128_t integ = (__int128_t)frac;

      /*         if(integ == 0)
                  prec++; */

      while (prec) {
        integ *= 10;
        integ += (__int128_t)(frac *= 10);
        prec--;
        res++;
      }
    }
  }
  return res;
}

int get_exp_prec(long double frac, long double *new_frac) {
  int exp = 0;
  if ((long)frac >= 10)
    while (frac >= 10) {
      frac /= 10;
      exp--;
    }
  else if ((long)frac == 0)
    while ((long)(frac) == 0) {
      frac *= 10;
      exp++;
    }
  *new_frac = frac;
  return exp;
}

int exp_print(long double frac, char *str, spec *sp, int is_up) {
  int offset = exp_len(frac, sp);
  int exp = 0;
  if (isnan(frac))
    offset = nan_print(str, is_up);
  else if (isinf(frac) && frac < 0)
    offset = inf_print(str, is_up);
  else if (isinf(frac) && frac >= 0)
    offset = inf_print(str, is_up);
  else {
    exp = get_exp_prec(frac, &frac);
    if ((sp->prec == 0 || sp->prec == 1) &&
        (sp->spec == 'g' || sp->spec == 'G'))
      sp->prec = 0;
    str += frac_print(frac, sp->prec, str);
    if (sp->spec == 'g' || sp->spec == 'G') {
      int loc_offset = rm_zeroes_from_end(str - 1);
      str += loc_offset;
      offset += loc_offset;
    }
    if (is_up)
      *str = 'E';
    else
      *str = 'e';
    str++;
    if (exp < 0) {
      exp = -exp;
      *str = '+';
    } else
      *str = '-';
    str++;
    str += print_num_without_first_dig(exp + 100, str);
  }

  return offset;
}

int exp_format(long double frac, char *str, spec *sp, int is_up) {
  int offset = 0;
  int loc_offset = 0;
  if (sp->prec == EMPTY_PREC) sp->prec = 6;
  int length = exp_len(frac, sp);
  if (((frac < 0 || is_flag('+', sp)) && !isnan(frac)) ||
      (frac > 0 && isinf(frac)))
    length++;
  if ((is_flag(' ', sp) || is_flag('+', sp) || is_flag(EMPTY_FLAG, sp) ||
       is_flag('#', sp)) &&
      sp->width > length)
    loc_offset = fill(' ', str, length, sp->width);
  else if (is_flag(' ', sp) && frac >= 0)
    loc_offset = fill(' ', str, 0, 1);
  offset += loc_offset;
  str += loc_offset;

  if (frac < 0 && !isinf(frac) && !isnan(frac)) {
    loc_offset = fill('-', str, 0, 1);
    offset += 1;
    str += 1;
  } else if (is_flag('+', sp) && frac >= 0) {
    loc_offset = fill('+', str, 0, 1);
    offset += 1;
    str += 1;
  }
  if (is_flag('0', sp)) {
    if (isnan(frac) || isinf(frac))
      loc_offset = fill(' ', str, length, sp->width);
    else
      loc_offset = fill('0', str, length, sp->width);
    offset += loc_offset;
    str += loc_offset;
  }
  if (isinf(frac) && frac < 0) {
    loc_offset = fill('-', str, 0, 1);
    offset += 1;
    str += 1;
  }
  if (frac < 0) frac = -frac;
  loc_offset = exp_print(frac, str, sp, is_up);
  str += loc_offset;
  offset += loc_offset;
  if (is_flag('-', sp) && !is_flag('0', sp)) {
    loc_offset = fill(' ', str, length, sp->width);
    offset += loc_offset;
  }
  return offset;
}

int rm_zeroes_from_end(char *str)  // points to last 0
{
  int offset = 0;
  while (*str == '0') {
    *str = ' ';
    str--;
    offset--;
  }

  return offset;
}

int count_prec_for_fg(long double frac, int prec, int much, int prec_set) {
  if (prec == EMPTY_PREC) prec = 6;
  int integ_len = 0;
  int res = 0;
  integ_len = number_len((__int128_t)frac, 10, 'l');
  if ((__int128_t)frac == 0) integ_len = 0;
  if (integ_len) much -= integ_len;
  long double num =
      ((frac - (__int128_t)frac));  // to maximum after floating point
  int zer_count = 0;
  int non_zer = 0;
  int i = 0;
  if ((__int128_t)frac == 0) i = -3;
  if (!prec_set) {
    while (num && non_zer < much && i < 6) {
      num *= 10;
      if ((__int128_t)num % 10 == 0)
        zer_count++;
      else
        non_zer++;
      i++;
    }
    res = non_zer + zer_count;
  } else {
    int start_non_z = 0;
    while (num && non_zer < much && i < 6) {
      num *= 10;
      if ((__int128_t)num % 10 == 0) {
        if (start_non_z) start_non_z++;
        zer_count++;
        much--;
      } else {
        non_zer++;
        start_non_z++;
      }
      i++;
    }
    if (!much && integ_len)
      res = 0;
    else
      res = non_zer + zer_count;
  }
  return res;
}

int g_format(long double frac, char *str, spec *sp, int is_up) {
  int offset = 0;
  int exp = 0;
  long double copy;

  if (isinf(frac) || isnan(frac))
    offset = exp_format(frac, str, sp, is_up);
  else {
    if (sp->prec == EMPTY_PREC)
      sp->prec = 6;
    else if (sp->prec == 0)
      sp->prec = 1;
    exp = get_exp_prec(frac, &copy);
    exp = -exp;
    if (exp >= -4) {
      if (sp->width != 0)
        sp->prec = count_prec_for_fg(frac, sp->prec, 5, 0);  // 5 - default
      else if (sp->prec == 6)
        sp->prec = 6 - number_len((__int128_t)frac, 10, 'l');
      else
        sp->prec = count_prec_for_fg(frac, sp->prec, sp->prec, 1);
      offset = frac_format(frac, str, sp);
      str += offset - 1;
      offset += rm_zeroes_from_end(str);
    } else {
      if (sp->prec == 0 || sp->prec == 1)
        sp->prec = 0;
      else {
        int non_zero = count_non_zeroes(frac, sp);
        sp->prec = non_zero > 5 ? 5 : non_zero;
      }
      offset = exp_format(frac, str, sp, is_up);
    }
  }
  return offset;
}

int proc_format(spec *sp, char *str, const char *format, va_list *list,
                int *str_offset, int cur_printed_chars) {
  int offset = get_spec(sp, format);
  if (sp->width == FROM_ARG) sp->width = va_arg(*list, int);
  if (sp->prec == FROM_ARG) sp->prec = va_arg(*list, int);
  switch (sp->spec) {
    case 'd':
    case 'i':
    case 'x':
    case 'X':
    case 'o':
    case 'O':
    case 'u':
      proc_format_nums(sp, str, list, str_offset);
      break;
    case 'c':
    case 's':
    case 'n':
    case '%':
    case 'p':
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      proc_format_others(sp, str, list, str_offset, cur_printed_chars);
    default:
      break;
  }

  return offset;
}

void proc_format_nums(spec *sp, char *str, va_list *list, int *str_offset) {
  switch (sp->spec) {
    case 'd':
    case 'i':
      if (sp->len == 'l')
        *str_offset = num_format(va_arg(*list, long), str, sp, 10, 0);
      else
        *str_offset = num_format(va_arg(*list, int), str, sp, 10, 0);
      break;
    case 'x':
      if (sp->len == 'l')
        *str_offset = num_format((long)va_arg(*list, long), str, sp, 16, 0);
      else
        *str_offset = num_format((long)va_arg(*list, int), str, sp, 16, 0);
      break;
    case 'X':
      if (sp->len == 'l')
        *str_offset = num_format((long)va_arg(*list, long), str, sp, 16, 1);
      else
        *str_offset = num_format((long)va_arg(*list, int), str, sp, 16, 1);
      break;
    case 'o':
    case 'O':
      if (sp->len == 'l')
        *str_offset = num_format((long)va_arg(*list, long), str, sp, 8, 0);
      else
        *str_offset = num_format((long)va_arg(*list, int), str, sp, 8, 0);
      break;
    case 'u':
      if (sp->len == 'l')
        *str_offset = num_format(va_arg(*list, unsigned long), str, sp, 10, 0);
      else
        *str_offset = num_format(va_arg(*list, unsigned int), str, sp, 10, 0);
      break;
  }
}

void proc_format_others(spec *sp, char *str, va_list *list, int *str_offset,
                        int cur_printed_chars) {
  switch (sp->spec) {
    case 'c':
      *str_offset = char_format(va_arg(*list, int), str, sp);
      break;
    case 's':
      *str_offset = str_format(va_arg(*list, const char *), str, sp);
      break;
    case 'n':
      *va_arg(*list, int *) = cur_printed_chars;
      *str_offset = 0;
      break;
    case '%':
      *str = '%';
      *str_offset = 1;
      break;
    case 'p':
      *str_offset = pointer_format(va_arg(*list, long), str, sp);
      break;
    case 'f':
      if (sp->len == 'L')
        *str_offset =
            frac_format((long double)va_arg(*list, long double), str, sp);
      else
        *str_offset = frac_format((long double)va_arg(*list, double), str, sp);
      break;
    case 'e':
      *str_offset = exp_format((long double)va_arg(*list, double), str, sp, 0);
      break;
    case 'E':
      *str_offset = exp_format((long double)va_arg(*list, double), str, sp, 1);
      break;
    case 'g':
      *str_offset = g_format((long double)va_arg(*list, double), str, sp, 0);
      break;
    case 'G':
      *str_offset = g_format((long double)va_arg(*list, double), str, sp, 1);
      break;
    default:
      break;
  }
}
