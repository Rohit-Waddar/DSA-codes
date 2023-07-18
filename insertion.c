#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new element in the BST
struct TreeNode* insertNode(struct TreeNode* node, int value) {
    // If the tree is empty, create a new node and return it
    if (node == NULL) {
        return createNode(value);
    }

    // Otherwise, do recursive insertion
    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    }

    return node;
}

// In-order traversal
void inorderTraversal(struct TreeNode* node, FILE* file) {
    if (node == NULL) {
        return;
    }

    inorderTraversal(node->left, file);
    fprintf(file, "%d ", node->data);
    inorderTraversal(node->right, file);
}

// Pre-order traversal
void preorderTraversal(struct TreeNode* node, FILE* file) {
    if (node == NULL) {
        return;
    }

    fprintf(file, "%d ", node->data);
    preorderTraversal(node->left, file);
    preorderTraversal(node->right, file);
}

// Post-order traversal
void postorderTraversal(struct TreeNode* node, FILE* file) {
    if (node == NULL) {
        return;
    }

    postorderTraversal(node->left, file);
    postorderTraversal(node->right, file);
    fprintf(file, "%d ", node->data);
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int choice;
    int numNodes;
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("preorder.txt","w");
    fp2=fopen("postorder.txt","w");
    fp3=fopen("inorder.txt","w");
    fp4=fopen("random.txt","w");
    printf("Enter the number of nodes to insert in the tree: ");
    scanf("%d", &numNodes);

    // Generate random numbers and insert them into the tree
    srand(time(NULL));
    for (int i = 0; i < numNodes; i++) {
        int value = rand() % 100;  // Generate random number between 0 and 99
        root = insertNode(root, value);
        fprintf(fp4,"%d\t ", value);
    }

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. In-order traversal\n");
        printf("2. Pre-order traversal\n");
        printf("3. Post-order traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                FILE* file = fopen("inorder.txt", "w");
                if (file == NULL) {
                    printf("Failed to open file.\n");
                    exit(1);
                }
                printf("In-order traversal: ");
                inorderTraversal(root, file);
                fclose(file);
                printf("\nTraversal stored in 'inorder.txt'.\n");
                break;
            }
            case 2: {
                FILE* file = fopen("preorder.txt", "w");
                if (file == NULL) {
                    printf("Failed to open file.\n");
                    exit(1);
                }
                printf("Pre-order traversal: ");
                preorderTraversal(root, file);
                fclose(file);
                printf("\nTraversal stored in 'preorder.txt'.\n");
                break;
            }
            case 3: {
                FILE* file = fopen("postorder.txt", "w");
                if (file == NULL) {
                    printf("Failed to open file.\n");
                    exit(1);
                }
                printf("Post-order traversal: ");
                postorderTraversal(root, file);
                fclose(file);
                printf("\nTraversal stored in 'postorder.txt'.\n");
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
