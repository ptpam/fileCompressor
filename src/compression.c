#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compression.h"
#include "utils.h"
#include "constants.h"

int compress_file(const char *input_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Error opening file: %s\n", input_filename);
        return -1;
    }

    char output_filename[MAX_FILENAME_LENGTH];
    if (generate_unique_filename(input_filename, ".rle", output_filename, sizeof(output_filename)) != 0) {
        fprintf(stderr, "Error generating output filename\n");
        fclose(input_file);
        return -1;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Error opening output file: %s\n", output_filename);
        fclose(input_file);
        return -1;
    }

    printf("Processing compression: %s -> %s\n", input_filename, output_filename);

    int current_char, prev_char = EOF, count = 0;
    while ((current_char = fgetc(input_file)) != EOF) {
        if (current_char == prev_char && current_char != '\n') {
            count++;
        } else {
            if (prev_char != EOF) {
                fprintf(output_file, "%c%d", prev_char, count);
            }
            prev_char = current_char;
            count = 1;
        }
        if (current_char == '\n') {
            fputc('\n', output_file);
            prev_char = EOF;
        }
    }
    if (prev_char != EOF) {
        fprintf(output_file, "%c%d", prev_char, count);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Successfully compressed file: %s\n", output_filename);
    return 0;
}