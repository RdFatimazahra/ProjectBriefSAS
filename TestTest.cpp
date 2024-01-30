#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
    char description[100];
    int completed;
} Task;

void addTask(Task tasks[], int *taskCount, const char *description) {
    if (*taskCount < MAX_TASKS) {
        Task newTask;
        strcpy(newTask.description, description);
        newTask.completed = 0; // 0 means task is not completed
        tasks[*taskCount] = newTask;
        (*taskCount)++;
        printf("Task added successfully.\n");
    } else {
        printf("Task limit reached.\n");
    }
}

void viewTasks(Task tasks[], int taskCount) {
    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "X" : " ", tasks[i].description);
    }
}

void markCompleted(Task tasks[], int taskCount, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        tasks[taskIndex - 1].completed = 1; // 1 means task is completed
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void removeTask(Task tasks[], int *taskCount, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= *taskCount) {
        for (int i = taskIndex - 1; i < *taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        (*taskCount)--;
        printf("Task removed successfully.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void editTask(Task tasks[], int taskCount, int taskIndex, const char *newDescription) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        strcpy(tasks[taskIndex - 1].description, newDescription);
        printf("Task edited successfully.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Remove Task\n");
        printf("5. Edit Task\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char description[100];
                    printf("Enter task description: ");
                    scanf(" %[^\n]s", description);
                    addTask(tasks, &taskCount, description);
                    break;
                }
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                {
                    int taskIndex;
                    printf("Enter task index to mark as completed: ");
                    scanf("%d", &taskIndex);
                    markCompleted(tasks, taskCount, taskIndex);
                    break;
                }
            case 4:
                {
                    int taskIndex;
                    printf("Enter task index to remove: ");
                    scanf("%d", &taskIndex);
                    removeTask(tasks, &taskCount, taskIndex);
                    break;
                }
            case 5:
                {
                    int taskIndex;
                    char newDescription[100];
                    printf("Enter task index to edit: ");
                    scanf("%d", &taskIndex);
                    printf("Enter new task description: ");
                    scanf(" %[^\n]s", newDescription);
                    editTask(tasks, taskCount, taskIndex, newDescription);
                    break;
                }
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}
