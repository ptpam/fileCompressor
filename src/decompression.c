/* decompression.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decompression.h"

int decompress_file(const char *input_filename, const char *output_filename) {
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

    char character;
    int count;
    
    while (fscanf(input, "%c%d", &character, &count) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(character, output);
        }
    }
    
    fclose(input);
    fclose(output);
    printf("Successfully decompressed '%s' to '%s'\n", input_filename, output_filename);
    return 0;
}