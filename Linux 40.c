#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

// Function to display file access permissions
void display_permissions(mode_t mode) {
    printf("File permissions: ");

    // Owner permissions
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");

    // Group permissions
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");

    // Others permissions
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");

    printf("\n");
}

int main() {
    struct stat file_stat;
    char *filename = "example.txt";

    // Get file status
    if (stat(filename, &file_stat) == -1) {
        perror("Error in getting file status");
        exit(EXIT_FAILURE);
    }

    // Display file permissions
    display_permissions(file_stat.st_mode);

    // Display user and group IDs
    printf("User ID: %d\n", file_stat.st_uid);
    printf("Group ID: %d\n", file_stat.st_gid);

    return 0;
}
