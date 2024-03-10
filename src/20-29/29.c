#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_MIN 2
#define A_MAX 100
#define B_MIN 2
#define B_MAX 100

struct Node {
    int *data;
    struct Node *next;
    struct Node *previous;
};

void primeFactor(int *arr, int num) {
    for (int k = 2; k <= num; ++k) {
        while (num % k == 0) {
            num /= k;
            arr[k] += 1;
        }
    }
}

int compareArrays(const int *arr1, const int *arr2, int size) {
    for (int k = 0; k < size; ++k) {
        if (arr1[k] > arr2[k]) {
            return 1;
        } else if (arr1[k] < arr2[k]) {
            return -1;
        }
    }
    return 0;
}

void insertSorted(struct Node **head, const int *arr, int size, int *listLength) {
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && compareArrays(current->data, arr, size) < 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL || compareArrays(current->data, arr, size) != 0) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
    
        newNode->data = (int *)malloc(size * sizeof(int));
        if (newNode->data == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
    
        memcpy(newNode->data, arr, size * sizeof(int));
        newNode->next = current;
    
        if (current != NULL) {
            current->previous = newNode;
        }

        if (prev == NULL) {
            *head = newNode;
        } else {
            prev->next = newNode;
            newNode->previous = prev;
        }

        (*listLength)++;
    }
}

void freeLinkedList(struct Node *head) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

int main() {
    struct Node *answer = NULL;
    int size = A_MAX;
    int listLength = 0;

    for (int i = A_MIN; i <= A_MAX; ++i) {
        int arr[A_MAX] = {0};
        primeFactor(arr, i);

        for (int j = B_MIN; j <= B_MAX; ++j) {
            int *arr2 = (int *)malloc(size * sizeof(int));
            if (arr2 == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }

            for (int k = 0; k < size; ++k) {
                arr2[k] = arr[k] * j;
            }

            insertSorted(&answer, arr2, size, &listLength);
        }

    }

    printf("%d\n", listLength);

    freeLinkedList(answer);

    return 0;
}
