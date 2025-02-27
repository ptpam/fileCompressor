#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compression.h"
#include "decompression.h"
#include "utils.h"

void print_usage() {
    printf("Usage: ./fileCompressor -c <input_file> for compression\n");
    printf("       ./fileCompressor -d <input_file> for decompression\n");
    printf("       ./fileCompressor -h to see this menu\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No arguments given\n");
        print_usage();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-h") == 0) {
        print_usage();
        return EXIT_SUCCESS;
    }

    if (argc != 3) {
        fprintf(stderr, "Error: Invalid argument(s)\n");
        print_usage();
        return EXIT_FAILURE;
    }

    char *input_file = argv[2];

    if (strcmp(argv[1], "-c") == 0) {
        printf("Initiated compressing \"%s\"...\n", input_file);
        if (compress_file(input_file) == 0) {
            printf("Successfully compressed \"%s\"\n", input_file);
        } else {
            fprintf(stderr, "Compression of \"%s\" failed\n", input_file);
            return EXIT_FAILURE;
        }
    } else if (strcmp(argv[1], "-d") == 0) {
        printf("Initiated decompressing \"%s\"...\n", input_file);
        if (decompress_file(input_file) == 0) {
            printf("Successfully decompressed \"%s\"\n", input_file);
        } else {
            fprintf(stderr, "Decompression of \"%s\" failed\n", input_file);
            return EXIT_FAILURE;
        }
    } else {
        fprintf(stderr, "Error: Invalid argument(s)\n");
        print_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}