#ifndef HELPERS_H
#define HELPERS_H

#include <time.h>

/* String */
void str_trim(char* str);
void str_to_upper(char* str);
void str_to_lower(char* str);

/* Date & time */
time_t get_current_time();
int compare_date(const char* d1, const char* d2);

/* Console */
void print_line(char ch, int length);

#endif
