/* main.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "compression.h"
#include "decompression.h"
#include "utils.h"

void print_usage() {
    printf("Usage:\n");
    printf("  ./fileCompressor -c <input_file> for compression\n");
    printf("  ./fileCompressor -d <input_file> for decompression\n");
    printf("  ./fileCompressor -h to see this menu\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No arguments given\n");
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0) {
        print_usage();
        return 0;
    }

    if (argc != 3) {
        printf("Error: Invalid argument(s)\n");
        print_usage();
        return 1;
    }

    char *input_file = argv[2];

    if (!file_exists(input_file)) {
        printf("Error: File '%s' not found\n", input_file);
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        char output_file[256];
        generate_output_filename(input_file, ".rle", output_file);
        return compress_file(input_file, output_file);
    } 
    else if (strcmp(argv[1], "-d") == 0) {
        char output_file[256];
        generate_output_filename(input_file, ".txt", output_file);
        return decompress_file(input_file, output_file);
    } 
    else {
        printf("Error: Invalid argument(s)\n");
        print_usage();
        return 1;
    }
}
