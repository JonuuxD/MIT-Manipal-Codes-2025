#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void listFilesRecursively(const char *basePath) {
    struct dirent *entry;
    struct stat fileStat;
    
    DIR *dir = opendir(basePath);
    if (dir == NULL) {
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);
        
        if (stat(path, &fileStat) < 0) {
            perror("Error getting file stats");
            continue;
        }
        
        if (S_ISDIR(fileStat.st_mode)) {
            // Skip "." and ".." directories
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                printf("Directory: %s\n", path);
                listFilesRecursively(path); // Recursively list files in subdirectories
            }
        } else {
            printf("File: %s\n", path);
        }
    }
    
    closedir(dir);
}

int main() {
    listFilesRecursively(".");
    return 0;
}
