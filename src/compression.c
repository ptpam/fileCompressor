/* compression.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compression.h"

int compress_file(const char *input_filename, const char *output_filename) {
    FILE *input = fopen(input_filename, "r");
    if (!input) {
        printf("Error opening file: %s\n", input_filename);
        return 1;
    }

    FILE *output = fopen(output_filename, "w");
    if (!output) {
        printf("Error creating file: %s\n", output_filename);
        fclose(input);
        return 1;
    }

    char current_char, previous_char;
    int count = 1;
    previous_char = fgetc(input);
    
    while ((current_char = fgetc(input)) != EOF) {
        if (current_char == previous_char) {
            count++;
        } else {
            fprintf(output, "%c%d", previous_char, count);
            previous_char = current_char;
            count = 1;
        }
    }
    
    if (previous_char != EOF) {
        fprintf(output, "%c%d", previous_char, count);
    }

    fclose(input);
    fclose(output);
    printf("Successfully compressed '%s' to '%s'\n", input_filename, output_filename);
    return 0;
}
