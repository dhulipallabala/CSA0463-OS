#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

void demonstrate_fcntl(int fd) {
  // Set non-blocking flag
  if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1) {
    perror("fcntl");
    exit(1);
  }
  printf("Non-blocking flag set successfully.\n");
}

void demonstrate_seek(int fd, off_t offset, int whence) {
  if (lseek(fd, offset, whence) == -1) {
    perror("lseek");
    exit(1);
  }
  printf("File pointer moved successfully.\n");
}

void demonstrate_stat(char *filename) {
  struct stat file_stat;
  if (stat(filename, &file_stat) == -1) {
    perror("stat");
    exit(1);
  }

  printf("File information:\n");
  printf("  - Size: %ld bytes\n", file_stat.st_size);
  printf("  - Permissions: %o\n", file_stat.st_mode);
  printf("  - Last access time: %ld\n", file_stat.st_atime);
}

void demonstrate_opendir(char *dirname) {
  DIR *dirp;
  if ((dirp = opendir(dirname)) == NULL) {
    perror("opendir");
    exit(1);
  }

  struct dirent *entry;
  while ((entry = readdir(dirp)) != NULL) {
    printf("File name: %s\n", entry->d_name);
  }

  closedir(dirp);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename> [<directory_name>]\n", argv[0]);
    exit(1);
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    exit(1);
  }

  printf("\n*** Demonstrating fcntl ***\n");
  demonstrate_fcntl(fd);

  printf("\n*** Demonstrating seek (seek to beginning) ***\n");
  demonstrate_seek(fd, 0, SEEK_SET);

  printf("\n*** Demonstrating stat ***\n");
  demonstrate_stat(argv[1]);

  if (argc == 3) {
    printf("\n*** Demonstrating opendir and readdir ***\n");
    demonstrate_opendir(argv[2]);
  }

  close(fd);
  return 0;
}

