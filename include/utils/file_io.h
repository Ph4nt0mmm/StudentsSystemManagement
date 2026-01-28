#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

/* Binary IO */
int file_write(const char* filename, const void* data, size_t size);
int file_read(const char* filename, void* data, size_t size);

/* Text IO */
int file_exists(const char* filename);
long file_size(const char* filename);

#endif
