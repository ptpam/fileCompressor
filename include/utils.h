#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stddef.h>

void close_file(FILE *file);
int generate_unique_filename(const char *input_filename, const char *new_extension, char *output_filename, size_t max_length);

#endif // UTILS_H
