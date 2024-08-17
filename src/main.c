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
    char audios_path[MAX_PATH];
    char tar_path[MAX_PATH];
    char web_path[MAX_PATH];
    char spreadsheets_path[MAX_PATH];
    char documents_path[MAX_PATH];
    char icons_path[MAX_PATH];
    char giui_path[MAX_PATH];
    snprintf(images_path, sizeof(images_path), "%s\\Downloaded_Images", downloads_path);
    snprintf(videos_path, sizeof(videos_path), "%s\\Downloaded_Videos", downloads_path);
    snprintf(audios_path, sizeof(audios_path), "%s\\Downloaded_Audios", downloads_path);
    snprintf(tar_path, sizeof(tar_path), "%s\\Downloaded_CompressedFiles", downloads_path);
    snprintf(web_path, sizeof(web_path), "%s\\Downloaded_WebPages", downloads_path);
    snprintf(spreadsheets_path, sizeof(spreadsheets_path), "%s\\Downloaded_Spreadsheets", downloads_path);
    snprintf(documents_path, sizeof(documents_path), "%s\\Downloaded_Documents", downloads_path); 
    snprintf(icons_path, sizeof(icons_path), "%s\\Downloaded_Graphs&Icons", downloads_path);
    snprintf(giui_path, sizeof(giui_path), "%s\\Downloaded_GIUIApplications");
    check_create_directories(images_path);
    check_create_directories(videos_path);
    check_create_directories(audios_path);
    check_create_directories(tar_path);
    check_create_directories(web_path);
    check_create_directories(spreadsheets_path);
    check_create_directories(documents_path);
    check_create_directories(icons_path); 
    check_create_directories(giui_path);
    //3 Core logic 

    organize_downloads(downloads_path);

    //4 Exit
   return EXIT_SUCCESS;
}