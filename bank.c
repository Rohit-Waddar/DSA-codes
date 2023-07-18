#include <stdio.h>
#include <stdlib.h>

// Structure for a database record
typedef struct {
    int transactionId;
    float amount;
    // Add additional fields for the record data
} Transaction;

// Structure for a node in the AVL tree
typedef struct Node {
    Transaction* transaction;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to calculate the height of a node
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with the given transaction
Node* createNode(Transaction* transaction) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->transaction = transaction;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to calculate the balance factor of a node
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a transaction into the AVL tree
Node* insert(Node* node, Transaction* transaction) {
    if (node == NULL)
        return createNode(transaction);

    if (transaction->transactionId < node->transaction->transactionId)
        node->left = insert(node->left, transaction);
    else if (transaction->transactionId > node->transaction->transactionId)
        node->right = insert(node->right, transaction);
    else
        return node; // Duplicate transaction IDs are not allowed

    // Update the height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check the balance factor and perform rotations if needed
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && transaction->transactionId < node->left->transaction->transactionId)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && transaction->transactionId > node->right->transaction->transactionId)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && transaction->transactionId > node->left->transaction->transactionId) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && transaction->transactionId < node->right->transaction->transactionId) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find transactions above a specified amount
void findTransactionsAboveAmount(Node* node, float amount) {
    if (node == NULL)
        return;

    findTransactionsAboveAmount(node->left, amount);

    if (node->transaction->amount > amount) {
        printf("Transaction ID: %d, Amount: $%.2f\n", node->transaction->transactionId, node->transaction->amount);
    }

    findTransactionsAboveAmount(node->right, amount);
}

// Function to free the memory allocated for the AVL tree
void freeTree(Node* node) {
    if (node == NULL)
        return;
    freeTree(node->left);
    freeTree(node->right);
    free(node->transaction);
    free(node);
}

int main() {
    Node* root = NULL;

    // Insert transactions into the AVL tree
    Transaction* transaction1 = (Transaction*)malloc(sizeof(Transaction));
    transaction1->transactionId = 1001;
    transaction1->amount = 5000.50;
    root = insert(root, transaction1);

    Transaction* transaction2 = (Transaction*)malloc(sizeof(Transaction));
    transaction2->transactionId = 1002;
    transaction2->amount = 7500.75;
    root = insert(root, transaction2);

    Transaction* transaction3 = (Transaction*)malloc(sizeof(Transaction));
    transaction3->transactionId = 1003;
    transaction3->amount = 15000.25;
    root = insert(root, transaction3);

    Transaction* transaction4 = (Transaction*)malloc(sizeof(Transaction));
    transaction4->transactionId = 1004;
    transaction4->amount = 3000.00;
    root = insert(root, transaction4);

    Transaction* transaction5 = (Transaction*)malloc(sizeof(Transaction));
    transaction5->transactionId = 1005;
    transaction5->amount = 12000.50;
    root = insert(root, transaction5);

    // Find transactions above $10,000
    printf("Transactions above $10,000:\n");
    findTransactionsAboveAmount(root, 10000.0);

    // Free the memory allocated for the AVL tree
    freeTree(root);

    return 0;
}
