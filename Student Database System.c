#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Student {
    char name[20];
    int rollNumber;
    float marks;
    struct Student* next;
} Student;


typedef struct StudentDatabase {
    Student* head;
    int numStudents;
} StudentDatabase;

Student* createStudent(char* name, int rollNumber, float marks) {
    Student* student = (Student*) malloc(sizeof(Student));
    if (student == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(student->name, name);
    student->rollNumber = rollNumber;
    student->marks = marks;
    student->next = NULL;
    return student;
}

void addStudent(StudentDatabase* db, char* name, int rollNumber, float marks) {
    Student* student = createStudent(name, rollNumber, marks);
    if (student == NULL) {
        return;
    }
    if (db->head == NULL) {
        db->head = student;
    } else {
        Student* current = db->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = student;
    }
    db->numStudents++;
}

void removeStudent(StudentDatabase* db, int rollNumber) {
    Student* current = db->head;
    Student* previous = NULL;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            if (previous == NULL) {
                db->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            db->numStudents--;
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Student not found!\n");
}

void searchStudent(StudentDatabase* db, int rollNumber) {
    Student* current = db->head;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            printf("Student found!\n");
            printf("Name: %s, Roll Number: %d, Marks: %.2f\n",
                   current->name, current->rollNumber, current->marks);
            return;
        }
        current = current->next;
    }
    printf("Student not found!\n");
}

void displayStudents(StudentDatabase* db) {
    Student* current = db->head;
    while (current != NULL) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n",
               current->name, current->rollNumber, current->marks);
        current = current->next;
    }
}

int main() {

    printf("                      ------------------------------------------------------\n");
    printf("                              Welcome to the Student Database System         \n");
    printf("                      ------------------------------------------------------\n");

    StudentDatabase db;
    db.head = NULL;
    db.numStudents = 0;

    int choice;
    int rollNumber;
    char name[20];
    float marks;
    while (1) {
        printf("\n");
        printf("\n1. Add student\n");
        printf("\n2. Remove student\n");
        printf("\n3. Search student\n");
        printf("\n4. Display students\n");
        printf("\n5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        printf("\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%19s", name);
                printf("Enter roll number: ");
                scanf("%d", &rollNumber);
                printf("Enter marks: ");
                scanf("%f", &marks);
                addStudent(&db, name, rollNumber, marks);
                break;
            case 2:
                printf("Enter roll number of student to remove: ");
                scanf("%d", &rollNumber);
                removeStudent(&db, rollNumber);
                break;
            case 3:
                printf("Enter roll number of student to search: ");
                scanf("%d", &rollNumber);
                searchStudent(&db, rollNumber);
                break;
            case 4:
                displayStudents(&db);
                break;
            case 5:
                printf("Thank you for using the Student Database System!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
