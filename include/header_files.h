#ifndef HEADER_FILES_H
#define HEADER_FILES_H

//standart library headers to be used
#include <stdlib.h>
//#include <assert.h>
#include <stdio.h>
#include <string.h>

//file directory operations
//#include <types.h>
//#include <stat.h>
//#include <unistd.h>

//file system monitoring (Windows only)
#include <windows.h>
//#include <fileapi.h>
//#include <handleapi.h>

//error handling
#include <errno.h>

// Function declarations
void get_downloads_path(char *downloads_path, size_t size);
void check_create_directories(const char *path);
void move_file(const char *filename, const char *downloads_path);
void organize_downloads(const char *downloads_path);

#endif // HEADER_FILES_H
