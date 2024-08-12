#include "header_files.h"

//Function to dinamically get/find the Downloads path on a drive
void get_downloads_path(char *downloads_path, size_t size)
    {
        char *user_profile = getenv("USERPROFILE");
        if (user_profile != NULL)
        {
            snprintf(downloads_path, size, "%s\\Downloads", user_profile);
        }
        else 
        {
            fprintf(stderr, "Unable to get user profile.\n");   
            exit(EXIT_FAILURE);
        }
    }

//Function to create directories if they do not exist already

void check_create_directories(const char *path) 
    {
    DWORD attributes = GetFileAttributes(path);

    if (attributes == INVALID_FILE_ATTRIBUTES) {
        // Path does not exist, try to create the directory
        if (CreateDirectory(path, NULL)) {
            printf("Directory created: %s\n", path);
        } else {
            // Failed to create directory
            printf("Failed to create directory: %s, Error: %ld\n", path, GetLastError());
        }
    } else if (attributes & FILE_ATTRIBUTE_DIRECTORY) {
        // Directory exists
        printf("Directory already exists: %s\n", path);
    } else {
        // Path exists but is not a directory
        printf("The path exists but is not a directory: %s\n", path);
    }
}