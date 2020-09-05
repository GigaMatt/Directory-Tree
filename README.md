# CS 4375 - Operating Systems

## Homework 7

### Overview

HW 7: Due 24 April 2020</br>
Write a program ```dirtree``` that prints out the names of each directory in the file system tree starting at the current working directory. The directories should be printed out in horizontal tree fashion, that is indented to show subdirectories.

For example:

```text
 ./homework
        /cs4311
        /cs4375
                /hw5
                /hw6
        /cs4387
 ./personal
        /letters_home
```

### Directory Structure

The directory structure used herein to manage documents and files is as follows:

At the top level, files describing the project meant for users to read: ```README.md```. The only other files that would be expected here is a ```.gitignore``` file, listing files and/or folders which Git should ignore and a ```.git``` file, containing git metadata. There is one subdirectory of this structure: ```/src```

### How To Compile & Run

1. Using a dependency listed below, navigate to the ```/src``` subdirectory via the terminal
2. Enter the following command to compile the program</br>
  ```sudo make```</br>
3. Enter the following command to execute the program</br>
  ```./homework7.o```

### Dependancies

1. A Linux-based virtual machine (preferably **Ubuntu 18.04 or later**) OR
2. A Linux-based machine (Note: This should be reserved for advanced users) OR
3. A macOS-based machine (preferably **macOS Catalina 10.15.4 or later**)

### Warnings

* Although the dependencies call for the use of a virual machine, you may use a local Linux OS to compile & execute this code. This should be reserved for advanced users.
