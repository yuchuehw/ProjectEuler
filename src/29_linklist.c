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
            arr[(k-1)/2] += 1;
        }
    }
}

int compareArrays(const int *arr1, const int *arr2, int size) {
    for (int k = 0; k < size; ++k) {
        if (arr2[k] < arr1[k]) {
            return -1; // arr2 is left of arr1
        } else if (arr1[k] < arr2[k]) {
            return 1; // arr2 is right of arr1
        }
    }
    return 0; // arr2 is arr1
}

void insertSorted(struct Node **head, const int *arr, int size, int *listLength) {
    struct Node *current = *head;

    int pos = 0;
    int left = 0;
    int right = *listLength;

    int comparison = -1;

    while (current != NULL && left < right) {
        int mid = (left + right) / 2;
        while (pos < mid) {
            current = current->next;
            pos++;
        }
        while (pos > mid) {
            current = current->previous;
            pos--;
        }
        comparison = compareArrays(current->data, arr, size);
        if (comparison == 1) { // arr2 is right of arr1
            left = mid + 1;
        } else if (comparison == -1) { // arr2 is left of arr1
            right = mid;
        } else {
            break;
        }
    }

    struct Node *prev = (current != NULL) ? current->previous : NULL;
    struct Node *nxt = (current != NULL) ? current->next : NULL;

    if (comparison != 0) {
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

        if (comparison == -1) { // perform insert left
            newNode->next = current;
            if (current == NULL) {
                newNode->next = NULL;
            }else{
                newNode->next = current;                
                current->previous = newNode;
            }
            if (prev == NULL) {
                newNode->previous = NULL;
                *head = newNode;
            } else {
                newNode->previous = prev;
                prev->next = newNode;
            }
        } else if (comparison == 1) { // perform insert right
            newNode->next = nxt;
            if (current == NULL) {
                newNode->previous = NULL;
                *head = newNode;
            }else{
                newNode->previous = current;
                current->next = newNode;
            }

            if (nxt == NULL) {
                newNode->next = NULL;
            }else{
                newNode->next = nxt;
                nxt->previous = newNode;
            }
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
    struct Node *link_list = NULL;
    int size = (A_MAX-1)/2+1;
    int listLength = 0;

    for (int i = A_MIN; i <= A_MAX; ++i) {
        int arr[size];
        memset(arr, 0, sizeof(int)*size);
        primeFactor(arr, i);

        for (int j = B_MIN; j <= B_MAX; ++j) {
            int arr2[size];
            for (int k = 0; k < size; ++k) {
                arr2[k] = arr[k] * j;
            }

            insertSorted(&link_list, arr2, size, &listLength);
        }
    }

    printf("%d\n", listLength);

    freeLinkedList(link_list);

    return 0;
}
