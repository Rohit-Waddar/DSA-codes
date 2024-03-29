#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int roll_number;
    char name[50];
    float marks;
    struct Student* next;
} Student;

typedef struct {
    Student* front;
    Student* rear;
} Queue;

Student* createStudent(int roll_number, char name[], float marks) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->roll_number = roll_number;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, Student* newStudent) {
    if (queue->rear == NULL) {
        queue->front = newStudent;
        queue->rear = newStudent;
    } else {
        queue->rear->next = newStudent;
        queue->rear = newStudent;
    }
}

void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Student Management System is empty.\n");
        return;
    }
    Student* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
}

void addStudent(Queue* queue, int roll_number, char name[], float marks) {
    Student* newStudent = createStudent(roll_number, name, marks);
    enqueue(queue, newStudent);
    printf("Student added successfully.\n");
}

void removeStudent(Queue* queue) {
    dequeue(queue);
    printf("Student removed successfully.\n");
}

void updateStudent(Queue* queue, int roll_number, float new_marks) {
    Student* current = queue->front;
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

float calculateAverageMarks(Queue* queue) {
    if (queue->front == NULL) {
        printf("Student Management System is empty.\n");
        return 0.0;
    }
    int count = 0;
    float sum = 0.0;
    Student* current = queue->front;
    while (current != NULL) {
        sum += current->marks;
        count++;
        current = current->next;
    }
    return sum / count;
}

void generateReport(Queue* queue) {
    if (queue->front == NULL) {
        printf("Student Management System is empty.\n");
        return;
    }
    printf("Student Report:\n");
    printf("Roll Number\tName\t\tMarks\n");
    Student* current = queue->front;
    while (current != NULL) {
        printf("%d\t\t%s\t\t%.2f\n", current->roll_number, current->name, current->marks);
        current = current->next;
    }
}

int main() {
    Queue* studentQueue = createQueue();
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
                addStudent(studentQueue, roll_number, name, marks);
                break;
            case 2:
                removeStudent(studentQueue);
                break;
            case 3:
                printf("Enter Roll Number to update: ");
                scanf("%d", &roll_number);
                printf("Enter new Marks: ");
                scanf("%f", &new_marks);
                updateStudent(studentQueue, roll_number, new_marks);
                break;
            case 4:
                printf("Average Marks: %.2f\n", calculateAverageMarks(studentQueue));
                break;
            case 5:
                generateReport(studentQueue);
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
    Student* current = studentQueue->front;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    free(studentQueue);

    return 0;
}
