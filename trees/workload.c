#include <stdio.h>
#include <stdlib.h>

// AVL tree node structure
struct Player {
    int playerID;
    int skillLevel;
    struct Player* left;
    struct Player* right;
    int height;
};

// Function to get the height of a node
int getHeight(struct Player* player) {
    if (player == NULL)
        return 0;
    return player->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new player node
struct Player* createPlayer(int playerID, int skillLevel) {
    struct Player* player = (struct Player*)malloc(sizeof(struct Player));
    player->playerID = playerID;
    player->skillLevel = skillLevel;
    player->left = NULL;
    player->right = NULL;
    player->height = 1;
    return player;
}

// Function to perform a right rotation
struct Player* rightRotate(struct Player* y) {
    struct Player* x = y->left;
    struct Player* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Function to perform a left rotation
struct Player* leftRotate(struct Player* x) {
    struct Player* y = x->right;
    struct Player* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a player node
int getBalance(struct Player* player) {
    if (player == NULL)
        return 0;
    return getHeight(player->left) - getHeight(player->right);
}

// Function to insert a player into the AVL tree
struct Player* insert(struct Player* player, int playerID, int skillLevel) {
    // Perform the normal BST insertion
    if (player == NULL)
        return createPlayer(playerID, skillLevel);

    if (playerID < player->playerID)
        player->left = insert(player->left, playerID, skillLevel);
    else if (playerID > player->playerID)
        player->right = insert(player->right, playerID, skillLevel);
    else // Duplicate player IDs are not allowed
        return player;

    // Update the height of the current player node
    player->height = 1 + max(getHeight(player->left), getHeight(player->right));

    // Check the balance factor and balance the tree if needed
    int balance = getBalance(player);

    // Left Left Case
    if (balance > 1 && playerID < player->left->playerID)
        return rightRotate(player);

    // Right Right Case
    if (balance < -1 && playerID > player->right->playerID)
        return leftRotate(player);

    // Left Right Case
    if (balance > 1 && playerID > player->left->playerID) {
        player->left = leftRotate(player->left);
        return rightRotate(player);
    }

    // Right Left Case
    if (balance < -1 && playerID < player->right->playerID) {
        player->right = rightRotate(player->right);
        return leftRotate(player);
    }

    // Return the unchanged player node pointer
    return player;
}

// Function to print the AVL tree in inorder traversal
void inorder(struct Player* player) {
    if (player != NULL) {
        inorder(player->left);
        printf("Player ID: %d, Skill Level: %d\n", player->playerID, player->skillLevel);
        inorder(player->right);
    }
}

int main() {
    struct Player* root = NULL;

    // Example usage: Inserting players into the AVL tree
    root = insert(root, 1001, 75);
    root = insert(root, 1002, 82);
    root = insert(root, 1003, 90);
    root = insert(root, 1004, 68);
    root = insert(root, 1005, 93);

    printf("Inorder traversal of the AVL tree:\n");
    inorder(root);

    return 0;
}
