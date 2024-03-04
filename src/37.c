#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define TRUNCATABLE 11

struct Node {
    int val;
    struct Node *next;
    struct Node *previous;
};

bool search(struct Node *head, const int a) {
    struct Node *current = head;

    while (current != NULL) {
        if (current->val == a) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void freeLinkedList(struct Node *head) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *node2 = malloc(sizeof(struct Node));
    struct Node *node3 = malloc(sizeof(struct Node));
    struct Node *node5 = malloc(sizeof(struct Node));
    struct Node *node7 = malloc(sizeof(struct Node));

    node2->next = node3;
    node3->next = node5;
    node5->next = node7;
    node7->next = NULL;

    node2->previous = NULL;
    node3->previous = node2;
    node5->previous = node3;
    node7->previous = node5;

    node2->val = 2;
    node3->val = 3;
    node5->val = 5;
    node7->val = 7;

    struct Node *last = node7;
    struct Node *first = node2;

    int listLength = 4;

    int sum = 0;
    for (int i = 0, p = 11; i < TRUNCATABLE; p += 2) {
        int n = p;
        bool is_prime = true;

        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) {
                is_prime = false;
                break;
            }
        }

        bool is_trunc_prime = true;
        if (is_prime) {
            struct Node *new_node = malloc(sizeof(struct Node));
            last->next = new_node;
            new_node->previous = last;
            new_node->val = p;
            new_node->next = NULL;
            last = new_node;
            listLength++;
        }

        int digits = log10(n);
        while (is_trunc_prime && n > 10) {
            n /= 10;
            if (!search(first, n)) {
                is_trunc_prime = false;
                break;
            }
        }
        n = p;
        while (is_trunc_prime && digits > 0) {
            n = n % (int)pow(10, digits);
            if (!search(first, n)) {
                is_trunc_prime = false;
                break;
            }
            digits--;
        }
        if (is_prime && is_trunc_prime) {
            sum += p;
            i++;
        }
    }
    printf("%d\n", sum);
    freeLinkedList(node2);

    return 0;
}
