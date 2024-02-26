#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check for valid arguments
  if (argc < 3) {
    printf("Usage: %s <pattern> <filename>\n", argv[0]);
    exit(1);
  }

  // Extract pattern and filename
  char *pattern = argv[1];
  char *filename = argv[2];

  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  // Read line by line
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Remove trailing newline if present
    strtok(line, "\n");

    // Check if line contains the pattern
    if (strstr(line, pattern) != NULL) {
      printf("%s\n", line);
    }
  }

  fclose(fp);
  return 0;
}

