# Overview

This is my attempt to standardise the script-running system for c/c++ here with lib support.

# Installation

Going straight to the point, you need the following to be able to develop with this workspace structure:

1. An installation of GNU auto tools. [How?](https://askubuntu.com/a/430722)
2. run `autoreconf --install` if you only have the base `**/Makefile.am` and `**/configure.ac` as you should thanks to gi
3. Run `./configure` in this dir after it has successfully completed, `config.h` should now be available.
4.  Next, use `cat ./src/c1/t.cpp | sh ./init.sh -` to copy the contents of the file to main for compilation (This is our only binary for now, could add more if you want to ship another app.).
5. Finally, run `make` to compile and run the bin `src/main`.
6. And `make clean` to rid the binaries.


# Thanks

To this stackoverflow for lib ans: https://stackoverflow.com/questions/30677198/automake-third-party-libraries
Also look up include dirs with that

# Hey there

