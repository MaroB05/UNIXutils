**README.md**

**mcat**
================

A minimal implementation of the `cat` command, which reads and displays the contents of one or more files.

**Overview**
------------

`mcat` is a simple utility that takes one or more file names as arguments, and prints their contents to the standard output. It uses a custom `getchars` function to read characters from each file, and the `printf` function to print the contents to the standard output.

**Implementation Details**
-------------------------

The `main` function in `mcat/mcat.c` takes an array of file names as arguments, and iterates over each file to open, read, and print its contents. The `getchars` function is used to read characters from each file, and is implemented in `helperFunctions/functions.c`.

**getchars Function**
--------------------

The `getchars` function reads characters from a file and writes them to a buffer. It takes three arguments:

* `buffer`: the buffer to write the characters to
* `n`: the size of the buffer
* `f`: the file to read from

The function reads characters from the file using `fread`, and writes them to the buffer until it reaches the end of the file or the buffer is full, which allows it to make full use of the buffer. It returns the number of characters read and returns 0 once it reaches the end of file.

**Usage**
---------

Compile the code using `gcc`:
```bash
gcc mcat.c -o mcat
```
Run the program with one or more file names as arguments:
```bash
./mcat file1.txt file2.txt
```
This will print the contents of `file1.txt` and `file2.txt` to the standard output.

**Dependencies**
---------------

* `helperFunctions/functions.c`: provides the `getchars` function used by `mcat`

**License**
-------

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).

**Contributing**
------------

Contributions are welcome! If you'd like to add a new feature or improve an existing one, please submit a pull request.

**Acknowledgments**
----------------

* The `getchars` function was implemented with the help of the `helperFunctions` library.
