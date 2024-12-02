# myUNIX Utilities

A collection of simple UNIX utilities implemented in C.

## Utilities

### mcat

A minimal implementation of the `cat` command, which reads and displays the contents of one or more files.

### mgrep

A simple implementation of the `grep` command, which searches for a pattern in one or more files and displays the matching lines.

### helperFunctions

A library of helper functions used by the above utilities, providing functionality for file I/O, string manipulation, and more.

## Usage

### mcat

* Compile: `gcc ../helperFunctions/functions.c mcat.c -o mcat`
* Run: `./mcat file1 file2 ...`

### mgrep

* Compile: `gcc m../helperFunctions/functions.c grep.c -o mgrep`
* Run: `./mgrep pattern file1 file2 ...`

## Contributing

Contributions are welcome! If you'd like to add a new utility or improve an existing one, please submit a pull request.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
