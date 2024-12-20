# myUNIX Utilities

A collection of simple UNIX utilities implemented in C.
The goal of this series of mini projects is to explore the C Programming Language, hence we may explore multiple approaches to the same task.

## Utilities

### mcat

A minimal implementation of the `cat` command, which reads and displays the contents of one or more files.

### mgrep

A simple implementation of the `grep` command, which searches for a pattern in one or more files and displays the matching lines.

### mzip & munzip
A simple implementation of `zip` and `unzip` compression utilities, using the [Run-length Encoding](https://en.wikipedia.org/wiki/Run-length_encoding) Algorithm.

### helperFunctions

A library of helper functions which we develop as we go on, which is used by the above utilities, providing functionality for file I/O, string manipulation, and more.

## Usage

### mcat

* Compile: `gcc ../helperFunctions/functions.c mcat.c -o mcat`
* Run: `./mcat file1 file2 ...`

### mgrep

* Compile: `gcc m../helperFunctions/functions.c grep.c -o mgrep`
* Run: `./mgrep pattern file1 file2 ...`

### mzip
* Under development
* Multiple approaches will be presented

### munzip
* Under development
* Multiple approaches will be presented

## Contributing

Contributions are welcome! If you'd like to add a new utility or improve an existing one, please submit a pull request.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
