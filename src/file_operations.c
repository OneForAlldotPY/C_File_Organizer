#include "header_files.h"


//Function to move files to the subdirectories logic
void move_file(const char *filename, const char *downloads_path){
    char source_path[MAX_PATH];
    snprintf(source_path, sizeof(source_path), "%s\\%s", downloads_path, filename);

    const char *destination_subdir = NULL;
    if (strstr(filename, ".jpg") || strstr(filename, ".gif") || strstr(filename, ".jpeg")) 
    {
        destination_subdir = "Downloaded_Images";
    } else if (strstr(filename, ".mp4") || strstr(filename, ".mkv") || strstr(filename, ".avi"))
    {
        destination_subdir = "Downloaded_Videos";
    } 

    if (destination_subdir) {
        char destination_path[MAX_PATH];

        snprintf(destination_path, sizeof(destination_path), "%s\\%s\\%s", downloads_path, destination_subdir, filename);

        if (!MoveFile(source_path, destination_path)) 
        {
            fprintf(stderr, "Error: Unable to move file %s to %s\n", filename, destination_subdir);
        } else {
            printf("File moved: %s -> %s\n", filename, destination_subdir);
        }
    }

}

//Function to monitor the downloads folder and call the move file function 
void organize_downloads(const char *downloads_path) {
    WIN32_FIND_DATA find_data; 
    char search_path[MAX_PATH];

    snprintf(search_path, sizeof(search_path), "%s\\*.*", downloads_path);

    HANDLE hFind = FindFirstFile(search_path, &find_data);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "Error: Unable to open the directory for scanning.\n");
        return;
    }

    do {
        const char *filename = find_data.cFileName;

        if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY));
        {
            move_file(filename, downloads_path);
        }
    } while (FindNextFile(hFind, &find_data) != 0);

    FindClose(hFind);
}