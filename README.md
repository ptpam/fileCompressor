# fileCompressor# File Compression Tool

## Overview

This project is a simple file compression and decompression tool using **Run-Length Encoding (RLE)**. It compresses text files into a compact format and can restore them back to their original state.

## Features

- **Compression**: Converts `.txt` files to `.rle` using RLE algorithm.
- **Decompression**: Converts `.rle` files back to `.txt`.
- **Error Handling**: Handles file access errors and invalid arguments.
- **Command-line Interface**: Simple and intuitive usage.

## File Structure

```
FileCompressionTool/
│── src/
│   ├── main.c
│   ├── compression.c
│   ├── decompression.c
│   ├── utils.c
│── include/
│   ├── compression.h
│   ├── decompression.h
│   ├── utils.h
│── test_files/
│   ├── sample.txt
│   ├── expected_output.rle
│── build/
│── constants.h
│── Makefile
│── README.md
```

## Usage

### Compile the project

Run the following command in the project root directory:

```sh
make
```

### Run the program

#### Compression

```sh
./fileCompressor -c test_files/sample.txt
```

This creates `test_files/sample.rle`.

#### Decompression

```sh
./fileCompressor -d test_files/sample.rle
```

This restores `test_files/sample.txt`.

#### Help

```sh
./fileCompressor -h
```

Displays the usage guide.

### Clean up

To remove compiled files, run:

```sh
make clean
```

## Example

### Input (`sample.txt`)

```
aabbcc
ffffjkjk
abc
```

### Output (`sample.rle`)

```
a2b2c2
f4j1k1j1k1
a1b1c1
```
