**README.md**

**mcat**
================

A minimal implementation of the `cat` command, which reads and displays the contents of one or more files.

**Overview**
------------

`mcat` is a simple utility that takes one or more file names as arguments, and prints their contents to the standard output. there are multiple implementations of `cat`. Each version offers higher performance than the one before while keeping the program quite simple.

**Usage**
---------

Compile using `make`:
```bash
make compile
```

Compile the code using `gcc`:
```bash
gcc mcat4.c -o mcat4
```

Run the version you prefer of the program with one or more file names as arguments:
```bash
./build/mcat1.out file1.txt file2.txt #or mcat2.out or 3 or 4
```
This will print the contents of `file1.txt` and `file2.txt` to the standard output.

**License**
-------

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).

**Contributing**
------------

Contributions are welcome! If you'd like to add a new feature or improve an existing one, please submit a pull request.

**Acknowledgments**
----------------

* The `getchars` function was implemented with the help of the `helperFunctions` library.
