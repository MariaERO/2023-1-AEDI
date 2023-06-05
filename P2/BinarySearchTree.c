#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct Node* root = createNode(arr[mid]);

    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);

    return root;
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int C;
    scanf("%d", &C);

    int testCases[C];
    for (int i = 0; i < C; i++) {
        scanf("%d", &testCases[i]);
    }

    for (int i = 0; i < C; i++) {
        int N = testCases[i];
        int arr[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
        }

        struct Node* root = buildTree(arr, 0, N - 1);

        printf("Case %d:\n", i + 1);
        printf("Pre.: ");
        preOrder(root);
        printf("\n");
        printf("In..: ");
        inOrder(root);
        printf("\n");
        printf("Post: ");
        postOrder(root);
        printf("\n\n");

        freeTree(root);
    }

    return 0;
}
