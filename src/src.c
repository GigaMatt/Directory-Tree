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
}