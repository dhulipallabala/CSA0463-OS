#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_LENGTH 100
#define MAX_RECORDS 100

// Structure to represent a record in the file
typedef struct {
    int record_number;
    char data[MAX_RECORD_LENGTH];
} Record;

// Function to add a record to the file
void addRecord(Record file[], int *num_records, char data[]) {
    if (*num_records >= MAX_RECORDS) {
        printf("File is full. Cannot add more records.\n");
        return;
    }
    strcpy(file[*num_records].data, data);
    file[*num_records].record_number = *num_records + 1;
    (*num_records)++;
    printf("Record added successfully.\n");
}

// Function to read all records in the file
void readRecords(Record file[], int num_records) {
    if (num_records == 0) {
        printf("File is empty. No records to read.\n");
        return;
    }
    printf("Reading all records in the file:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d: %s\n", file[i].record_number, file[i].data);
    }
}

int main() {
    Record file[MAX_RECORDS]; // Array to store records
    int num_records = 0;      // Number of records in the file
    int choice;
    char data[MAX_RECORD_LENGTH];

    printf("File Allocation Strategy Simulation\n");
    printf("------------------------------------\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a record\n");
        printf("2. Read all records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the record: ");
                getchar(); // Clear input buffer
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0'; // Remove trailing newline character
                addRecord(file, &num_records, data);
                break;
            case 2:
                readRecords(file, num_records);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

