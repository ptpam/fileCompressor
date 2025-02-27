#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"
#include "constants.h"

int decompress_file(const char *input_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Error opening file: %s\n", input_filename);
        return -1;
    }

    char output_filename[MAX_FILENAME_LENGTH];
    if (generate_unique_filename(input_filename, ".txt", output_filename, sizeof(output_filename)) != 0) {
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

    printf("Initiated decompressing \"%s\"...\n", input_filename);

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        if (isalpha(ch)) {
            int count = 0;
            int next_char;

            while ((next_char = fgetc(input_file)) != EOF && isdigit(next_char)) {
                count = count * 10 + (next_char - '0');
            }

            if (count == 0) {
                count = 1;  // Default case, should not happen with valid input
            }

            for (int i = 0; i < count; i++) {
                fputc(ch, output_file);
            }

            if (next_char == '\n') {
                fputc('\n', output_file);
            } else if (next_char != EOF) {
                ungetc(next_char, input_file);
            }
        } else if (ch == '\n') {
            fputc('\n', output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
    printf("Successfully decompressed \"%s\" -> \"%s\"\n", input_filename, output_filename);

    return 0;
}
