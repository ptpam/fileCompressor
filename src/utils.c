/* utils.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void generate_output_filename(const char *input_filename, const char *extension, char *output_filename) {
    strcpy(output_filename, input_filename);
    char *dot = strrchr(output_filename, '.');
    if (dot) {
        *dot = '\0';
    }
    strcat(output_filename, extension);
    
    int count = 1;
    char temp_filename[256];
    while (file_exists(output_filename)) {
        sprintf(temp_filename, "%s_%d%s", output_filename, count, extension);
        strcpy(output_filename, temp_filename);
        count++;
    }
}