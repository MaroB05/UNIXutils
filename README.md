# myUNIX Utilities

A collection of simple UNIX utilities implemented in C.
The goal of this series of mini projects is to explore the C Programming Language, hence we may explore multiple approaches to the same task.

## Utilities

### mcat

A minimal implementation of the `cat` command, which reads and displays the contents of one or more files.
Multiple implementations presented with performance enhancemenets.

### mgrep

A simple implementation of the `grep` command, which searches for a pattern in one or more files and displays the matching lines.

### mzip & munzip
A simple implementation of `zip` and `unzip` compression utilities, using the [Run-length Encoding](https://en.wikipedia.org/wiki/Run-length_encoding) Algorithm.

### mcp
Implementing Unix's cp allowing you to copy files.

### pwd
Implementation of pwd for printing the current directory.

### helperFunctions

A library of helper functions which we develop as we go on, which is used by the above utilities, providing functionality for file I/O, string manipulation, and more.

## Usage

### mcat

* Compile: `gcc ../helperFunctions/functions.c mcat.c -o mcat`
* Run: `./mcat file1 file2 ...`
* Multiple implementations are presented, with the best of them mcat4 which performs around 13% faster than standard unix cat.

### mgrep

* Compile: `gcc ../helperFunctions/functions.c grep.c -o mgrep`
* Run: `./mgrep pattern file1 file2 ...`

### mzip
* Implemented Run-Length encoding compression
* Advanced algorithms are to be implemented

### munzip
* Implemented Run-Length encoding decompression
* Advanced algorithms are to be implemented

### mcp
* Multiple implementations are presented:
  - standard read() and write()
  - sendfile system call.


## Contributing

Contributions are welcome! If you'd like to add a new utility or improve an existing one, please submit a pull request.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
