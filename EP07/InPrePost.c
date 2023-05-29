#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the index of a value in the in-order traversal
int findIndex(char inOrder[], int start, int end, char value) {
    int i;
    for (i = start; i <= end; i++) {
        if (inOrder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to construct the binary tree
struct Node* buildTree(char inOrder[], char preOrder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    // Create a new node with the current pre-order element
    struct Node* node = newNode(preOrder[*preIndex]);
    (*preIndex)++;

    // If the current subtree has no elements, return the node
    if (inStart == inEnd)
        return node;

    // Find the index of the current node in the in-order traversal
    int inIndex = findIndex(inOrder, inStart, inEnd, node->data);

    // Recursively construct the left and right subtrees
    node->left = buildTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

    return node;
}

// Function to perform post-order traversal of the binary tree
void postOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    // Recursively traverse the left subtree
    postOrderTraversal(root->left);

    // Recursively traverse the right subtree
    postOrderTraversal(root->right);

    // Print the current node's data
    printf("%c", root->data);
}

// Function to compute the post-order traversal of a binary tree
void computePostOrderTraversal(char inOrder[], char preOrder[], int n) {
    int preIndex = 0;
    struct Node* root = buildTree(inOrder, preOrder, 0, n - 1, &preIndex);

    // Perform post-order traversal
    postOrderTraversal(root);
    printf("\n");

    // Free dynamically allocated memory
    free(root);
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        char S1[53], S2[53];
        scanf("%d %s %s", &N, S1, S2);

        computePostOrderTraversal(S2, S1, N);
    }

    return 0;
}
