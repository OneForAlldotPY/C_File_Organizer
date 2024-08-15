#include "header_files.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    char downloads_path[MAX_PATH];
    get_downloads_path(downloads_path, sizeof(downloads_path));

    printf("Using downloads path: %s\n", downloads_path);


    //2 Configuration &OR Setup
    char images_path[MAX_PATH];
    char videos_path[MAX_PATH];
    snprintf(images_path, sizeof(images_path), "%s\\Downloaded_Images", downloads_path);
    snprintf(videos_path, sizeof(videos_path), "%s\\Downloaded_Videos", downloads_path);

    check_create_directories(images_path);
    check_create_directories(videos_path);

    //3 Core logic 

    organize_downloads(downloads_path);

    //4 Exit
   return EXIT_SUCCESS;
}
