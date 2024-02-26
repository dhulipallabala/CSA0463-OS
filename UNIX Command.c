#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void print_entry_info(const struct dirent *entry, const char *path) {
  char full_path[PATH_MAX];
  snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

  struct stat statbuf;
  if (stat(full_path, &statbuf) == -1) {
    perror("stat");
    return;
  }

  char type;
  if (S_ISDIR(statbuf.st_mode)) {
    type = 'd';
  } else if (S_ISREG(statbuf.st_mode)) {
    type = '-';
  } else {
    type = '?';
  }
  printf("%c %s\n", type, entry->d_name);
}

int main(int argc, char *argv[]) {
  char path[PATH_MAX] = ".";  // Default to current directory

  // Handle optional argument for specific directory
  if (argc > 1) {
    strncpy(path, argv[1], sizeof(path) - 1);
    path[sizeof(path) - 1] = '\0';
  }

  DIR *dirp = opendir(path);
  if (dirp == NULL) {
    perror("opendir");
    exit(1);
  }

  struct dirent *entry;
  while ((entry = readdir(dirp)) != NULL) {
    // Skip entries for current and parent directories
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    print_entry_info(entry, path);
  }

  closedir(dirp);
  return 0;
}

