#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int roll_number;
    char name[50];
    float marks;
    struct Student* next;
} Student;

Student* createStudent(int roll_number, char name[], float marks) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->roll_number = roll_number;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

void addStudent(Student** head, int roll_number, char name[], float marks) {
    Student* newStudent = createStudent(roll_number, name, marks);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
    printf("Student added successfully.\n");
}

void removeStudent(Student** head, int roll_number) {
    if (*head == NULL) {
        printf("Student Management System is empty.\n");
        return;
    }
    if ((*head)->roll_number == roll_number) {
        Student* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Student removed successfully.\n");
        return;
    }
    Student* current = *head;
    while (current->next != NULL) {
        if (current->next->roll_number == roll_number) {
            Student* temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("Student removed successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Student not found.\n");
}

void updateStudent(Student* head, int roll_number, float new_marks) {
    Student* current = head;
    while (current != NULL) {
        if (current->roll_number == roll_number) {
            current->marks = new_marks;
            printf("Student information updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Student not found.\n");
}

float calculateAverageMarks(Student* head) {
    if (head == NULL) {
        printf("Student Management System is empty.\n");
        return 0.0;
    }
    int count = 0;
    float sum = 0.0;
    Student* current = head;
    while (current != NULL) {
        sum += current->marks;
        count++;
        current = current->next;
    }
    return sum / count;
}

void generateReport(Student* head) {
    if (head == NULL) {
        printf("Student Management System is empty.\n");
        return;
    }
    printf("Student Report:\n");
    printf("Roll Number\tName\t\tMarks\n");
    Student* current = head;
    while (current != NULL) {
        printf("%d\t\t%s\t\t%.2f\n", current->roll_number, current->name, current->marks);
        current = current->next;
    }
}

int main() {
    Student* head = NULL;
    int choice, roll_number;
    char name[50];
    float marks, new_marks;

    do {
        printf("\n---------------------------\n");
        printf("Student Management System\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Update Student Information\n");
        printf("4. Calculate Average Marks\n");
        printf("5. Generate Report\n");
        printf("6. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll_number);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                addStudent(&head, roll_number, name, marks);
                break;
            case 2:
                printf("Enter Roll Number to remove: ");
                scanf("%d", &roll_number);
                removeStudent(&head, roll_number);
                break;
            case 3:
                printf("Enter Roll Number to update: ");
                scanf("%d", &roll_number);
                printf("Enter new Marks: ");
                scanf("%f", &new_marks);
                updateStudent(head, roll_number, new_marks);
                break;
            case 4:
                printf("Average Marks: %.2f\n", calculateAverageMarks(head));
                break;
            case 5:
                generateReport(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    // Free memory
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
