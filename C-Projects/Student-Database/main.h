#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

void clear_input_buffer();
int get_integer_input0(const char* prompt);
int get_integer_input(const char* prompt);
char* get_string_input(const char* prompt);


#endif