#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utils.h"

void close_file(FILE *file) {
    if (file) {
        fclose(file);
    }
}

int generate_unique_filename(const char *input_filename, const char *new_extension, char *output_filename, size_t max_length) {
    char base_name[PATH_MAX];
    char *dot = strrchr(input_filename, '.');
    if (dot) {
        size_t base_length = dot - input_filename;
        if (base_length >= sizeof(base_name)) {
            fprintf(stderr, "Base filename too long\n");
            return -1;
        }
        strncpy(base_name, input_filename, base_length);
        base_name[base_length] = '\0';
    } else {
        strncpy(base_name, input_filename, sizeof(base_name) - 1);
        base_name[sizeof(base_name) - 1] = '\0';
    }

    snprintf(output_filename, max_length, "%s%s", base_name, new_extension);
    FILE *file = fopen(output_filename, "r");
    int count = 1;
    while (file) {
        close_file(file);
        snprintf(output_filename, max_length, "%s_%d%s", base_name, count, new_extension);
        file = fopen(output_filename, "r");
        count++;
    }
    return 0;
}