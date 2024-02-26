#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
  char filename[MAX_SIZE];
  int choice, size;
  char buffer[MAX_SIZE];

  while (1) {
    printf("\nFile Management System\n");
    printf("1. Create a new file\n");
    printf("2. Open an existing file\n");
    printf("3. Write to a file\n");
    printf("4. Read from a file\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter filename: ");
        scanf("%s", filename);

        FILE *fp = fopen(filename, "w"); // Open in write mode
        if (fp == NULL) {
          printf("Error creating file!\n");
        } else {
          printf("File created successfully!\n");
          fclose(fp);
        }
        break;

      case 2:
        printf("Enter filename: ");
        scanf("%s", filename);

        fp = fopen(filename, "r"); // Open in read mode
        if (fp == NULL) {
          printf("Error opening file!\n");
        } else {
          printf("File opened successfully!\n");
          fclose(fp);
        }
        break;

      case 3:
        printf("Enter filename: ");
        scanf("%s", filename);

        fp = fopen(filename, "a"); // Open in append mode
        if (fp == NULL) {
          printf("Error opening file!\n");
        } else {
          printf("Enter data to write: ");
          scanf("%s", buffer);

          size = fprintf(fp, "%s\n", buffer); // Write with newline
          if (size > 0) {
            printf("Data written successfully!\n");
          } else {
            printf("Error writing data!\n");
          }

          fclose(fp);
        }
        break;

      case 4:
        printf("Enter filename: ");
        scanf("%s", filename);

        fp = fopen(filename, "r"); // Open in read mode
        if (fp == NULL) {
          printf("Error opening file!\n");
        } else {
          printf("File content:\n");
          while (fgets(buffer, MAX_SIZE, fp) != NULL) {
            printf("%s", buffer);
          }
          fclose(fp);
        }
        break;

      case 5:
        printf("Exiting...\n");
        exit(0);

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}

