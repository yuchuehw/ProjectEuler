#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_MIN 2
#define A_MAX 100
#define B_MIN 2
#define B_MAX 100

#define RED 0
#define BLACK 1

struct Node {
    int *data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int color;
};

struct RBTree {
    struct Node *root;
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

struct Node* createNode(const int *arr, int size) {
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
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->color = RED; // New nodes are always red

    return newNode;
}

void leftRotate(struct RBTree *tree, struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(struct RBTree *tree, struct Node *y) {
    struct Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        tree->root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void insertFixup(struct RBTree *tree, struct Node *z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct Node *y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            struct Node *y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

void insertNode(struct RBTree *tree, int *z, int *listLength, int size) {
    struct Node *y = NULL;
    struct Node *x = tree->root;

    while (x != NULL) {
        y = x;
        int compare_result = compareArrays(z, x->data, A_MAX);
        if (compare_result == 0){
            return; // node already exist. return early
        }
        if (compare_result < 0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    struct Node *newNode = createNode(z, size);

    newNode->parent = y;
    if (y == NULL) {
        tree->root = newNode;
    } else if (compareArrays(newNode->data, y->data, A_MAX) < 0) {
        y->left = newNode;
    } else {
        y->right = newNode;
    }

    insertFixup(tree, newNode);
    (*listLength)++;
}

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->data);
        free(root);
    }
}

int main() {
    struct RBTree tree;
    tree.root = NULL;
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

            
            insertNode(&tree, arr2, &listLength, size);
        }
    }

    printf("%d\n", listLength);

    freeTree(tree.root);

    return 0;
}
