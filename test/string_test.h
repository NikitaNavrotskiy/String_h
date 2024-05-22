#ifndef _MY_STRING_TEST_H
#define _MY_STRING_TEST_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../my_string.h"

Suite *suite_strlen();
Suite *suite_memchr();
Suite *suite_memcpy();
Suite *suite_strncat();
Suite *suite_strncmp();
Suite *suite_strcspn();
Suite *suite_strrchr();
Suite *suite_strtok();

Suite *suite_memcmp();
Suite *suite_memset();
Suite *suite_strchr();
Suite *suite_strncpy();
Suite *suite_strpbrk();
Suite *suite_strstr();

Suite *suite_to_upper();
Suite *suite_to_lower();
Suite *suite_insert();
Suite *suite_trim();

Suite *suite_sprintf();
Suite *suite_strerror();

void run();
void run_one_test(Suite *test);

#endif