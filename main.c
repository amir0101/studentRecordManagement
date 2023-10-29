/*
name: mohamed aboubaker hassan
sNumber: 2010213542

lab assignment due to sunday 00:00
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaring struct of students to store student information
struct Student {
    char sName[25];
    int sNumber;
    int sAge;
    struct Student* next;
};

// function that creates student new student record
struct Student* createStudent(char name[], int number, int age) {
    // creating struct pointer to store the address of the memory allocated in the heap
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    // copiying the given argument name, age number to the pointed name, age number
    strcpy(newStudent->sName, name);
    newStudent->sNumber = number;
    newStudent->sAge = age;
    newStudent->next = NULL;
    
    return newStudent;
}

// record printing and counting functn
int print_StuInfo(struct Student* head) {
    int count = 0;
    while (head != NULL) {
        printf("%s %d %d\n", head->sName, head->sNumber, head->sAge);
        head = head->next;
        count++;
    }
    return count;
}

// Function to search for a student by name in the list
struct Student* searchingSName(struct Student* head, char name[]) {
    while (head != NULL) {
            //by using strcmp function we comper given name with the exisiting
        if (strcmp(head->sName, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;  // Return NULL if not found
}

// Function to delete the next node from the node with the searched student name
void deleteNextStudent(struct Student* head, char name[]) {
    while (head != NULL) {
        if (head->next != NULL && strcmp(head->next->sName, name) == 0) {
            struct Student* toDelete = head->next;
            head->next = head->next->next;
            free(toDelete);
            break;
        }
        head = head->next;
    }
}

// Function to find and print the record with the longest name in the list
void printLongestName(struct Student* head) {
    char longestName[50];
    int maxLen = 0;
    while (head != NULL) {
        int currentLen = strlen(head->sName);
        if (currentLen > maxLen) {
            maxLen = currentLen;
            strcpy(longestName, head->sName);
        }
        head = head->next;
    }
    printf("the longest name in the list: %s\nLength: %d\n", longestName, maxLen);
}


int main() {
    struct Student* head = NULL;
    int studentCount = 0;
    int choice;

    do {
        printf("/*******************Choose an option:*******************/\n");
        printf("1. Add student record\n");
        printf("2. Print + count student record\n");
        printf("3. Search for a student by name\n");
        printf("4. Delete the next student from the searched student\n");
        printf("5. Print the record with the longest name\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char name[25];
                    int number, age;
                    printf("Enter student name: ");
                    scanf("%s", name);
                    printf("Enter student number: ");
                    scanf("%d", &number);
                    printf("Enter student age: ");
                    scanf("%d", &age);
                    struct Student* newStudent = createStudent(name, number, age);
                    newStudent->next = head;
                    head = newStudent;
                    break;
                }
            case 2:
                studentCount = print_StuInfo(head);
                printf("nymber total of students are: %d\n", studentCount);
                break;
            case 3:
                {
                    char searchName[50];
                    printf("Enter the name to search: ");
                    scanf("%s", searchName);
                    struct Student* searchedStudent = searchingSName(head, searchName);
                    if (searchedStudent != NULL) {
                        printf("Student found: %s %d %d\n", searchedStudent->sName, searchedStudent->sNumber, searchedStudent->sAge);
                    } else {
                        printf("Student not found.\n");
                    }
                    break;
                }
            case 4:
                {
                    char searchName[50];
                    printf("Enter the name to search for deletion: ");
                    scanf("%s", searchName);
                    deleteNextStudent(head, searchName);
                    printf("Deleted the next student with the name: %s\n", searchName);
                    break;
                }
            case 5:
                printLongestName(head);
                break;
            case 6:
                // Free memory
                while (head != NULL) {
                    struct Student* temp = head;
                    head = head->next;
                    free(temp);
                }
                break;
            default:
                printf("wrong choice!!!!!!!!!!!!!! please enter the choices given above.\n");
        }
    } while (choice != 6);

    return 0;
}

