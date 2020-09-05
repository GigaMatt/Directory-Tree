# CS 4375 - Operating Systems

## Homework 7

Listed in this subdirectry is the ```src.c``` file for this assignment. Both the code and it's output from execution are listed below:

```c
/**
 * CS 170 - Theory of Operating Systems
 * By: Matthew S Montoya
 * Purpose: To Practice Navigating the Linux Filesystem using C
 * Last Modified: 24 April 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>     // Addresses issue with implicit declaration of 'getcwd' 

#define MAX_PATH_SIZE 3000

/* Print the contents of the CWD and subdirectories */
void dir_tree(char* current_dir_path, int path_level){
    DIR *current_directory = opendir(current_dir_path);
    struct dirent *item_set;    // Holds all items

    /* BASE CASE (Empty Directory): Bottom of Tree Reached*/
    if(current_directory == NULL){
        return;
    }

    /* Traverse CWD and Indent at Each Subdirectory Level */
    char tree_depth[50];
    char indent = '\t';
    int position = 0;

    while(position < path_level){
        tree_depth[position] = indent;
        position++;
    }

    /* RECURSIVE CASE (No Empty Directory) */
    while((item_set = readdir(current_directory)) != NULL){
        /* Check for '.' & '..' */
        if(item_set->d_type == DT_DIR && (strcmp(item_set -> d_name, ".") != 0) && (strcmp(item_set -> d_name,"..") !=0)){
                    printf("%s/%s\n",tree_depth, item_set->d_name);
                    dir_tree(item_set->d_name, path_level+1);
        }
    }
    closedir(current_directory);
}

int main(){
    /* Retrieve CWD */
    char dir_path[MAX_PATH_SIZE];
    dir_tree(getcwd(dir_path,MAX_PATH_SIZE),1);
    return 0;
```

```
The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
Leviathan:~ montoms1$ cd "/Users/montoms1/Desktop/" && gcc src.c -o src && "/Users/montoms1/Desktop/"src
        /.dist
        /relocation_information
                /covid19-essential-worker-forms
                /flight_receipts
                /travel-docs
        /travel
                /catalina-island-march-2020
                /new-york-march-2020
                /santa-barbara-march-2020
Leviathan:Desktop montoms1$
```
