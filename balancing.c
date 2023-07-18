#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100000
typedef struct node
{
 struct node* left;
 int data;
 struct node* right;

}*NODE;
NODE newNODE(int data);
void display_preorder(NODE root);
void display_inorder(NODE root);
void display_postorder(struct node *root);
NODE function_to_link(NODE root,NODE leftchild,NODE rightchild);
void rand_numbers(int n,int lower,int upper,FILE *fp);     //printing the random numbers
void linkTreeTillEnd(NODE node);
void linktree(struct node** root, int data);
NODE findMinNode(NODE node);
NODE deleteNode(struct node* root, int key);
NODE rightRotate(NODE root);
NODE leftRotate(NODE root);
NODE leftrightRotate(NODE root);
NODE rightleftRotate(NODE root);
int getHeight(NODE root);
NODE balanceTree(NODE root);
void main()
{
    int n;
    FILE *fp;
    int ele;
    int low;
    int high;
    fp=fopen("input_random.txt","w");
    printf(" lower range:");
    scanf("%d",&low);
    printf(" higher range:");
    scanf("%d",&high);
    printf("enter the number of random integers to be genrated:");
    scanf("%d",&n);
    rand_numbers(n,low,high,fp);
    fclose(fp);
    fp=fopen("input_random.txt","r");
    NODE root=NULL;
    for(int i=0;i<n;i++)
   {
    fscanf(fp,"%d",&ele);
    linktree(&root,ele);
   }

    //root node
    //reading in preorder
    //reading in postorder
    //reading in inorder
    clock_t start=clock();
    printf("PREORDER:\n");
    display_preorder(root);
    clock_t stop=clock();
    double timeSpent=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nTime spent:%.2f seconds\n",timeSpent);
    printf("\n");
    start=clock();
    printf("INORDER:\n");
    display_inorder(root);
    stop=clock();
    timeSpent=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nTime spent:%.2f seconds\n",timeSpent);
    printf("\n");
    start=clock();
    printf("POSTORDER:\n");
    display_postorder(root);
    stop=clock();
    timeSpent=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nTime spent:%.2f seconds\n",timeSpent);
    printf("Enter the element ot be delete:");
    scanf("%d",&ele);
    root=deleteNode(root,ele);
    display_preorder(root);
    root=balanceTree(root);
    printf("\nBALANCED TREE:\n");
    display_preorder(root);
}
void display_preorder(NODE root)
{
if(root)
{
    printf("%d ",root->data);
    display_preorder(root->left);
    display_preorder(root->right);
}
}
NODE newNODE(int data)
 {
NODE node=(struct node*)malloc(sizeof(struct node));
node->data=data;
node->left=NULL;
node->right=NULL;
return node;
}
void display_inorder(NODE root)
{
    if(root)
    {
        display_inorder(root->left);
        printf("%d ",root->data);
        display_inorder(root->right);
    }
}
void display_postorder(struct node *root)
{
    if(root)
    {
      display_postorder(root->left);
      display_postorder(root->right);
      printf("%d ",root->data);

    }
}
void rand_numbers(int n,int lower,int upper,FILE *fp)
{
    int num;
    int count=0;
    int array[size];
    srand(time(NULL));
for(int i=0;i<n;i++)
{
    num=lower+rand()%(upper-lower+1);
    fprintf(fp,"%d ",num); //printing the numbers in input file

}
}
void linktree(struct node** root, int data)
 {
    if (*root == NULL) {
        *root = newNODE(data);
    } else {
        if (data > (*root)->data) {
            linktree(&((*root)->right), data);
        } else {
            linktree(&((*root)->left), data);
        }
    }
}
NODE findMinNode(NODE node)
{
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

NODE deleteNode(struct node* root, int key)
 {
    if (root == NULL)
    {
        printf("Key element is not found\n");
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found

        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Replace with in-order successor (smallest value in the right subtree)
        struct node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

NODE rightRotate(NODE root)
{
    NODE newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

// Function to perform a left rotation on a binary tree
NODE leftRotate(NODE root)
{
    NODE newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}
NODE leftrightRotate(NODE root)
{
root=leftRotate(root);
root=rightRotate(root);
return root;
}
NODE rightleftRotate(NODE root)
{
root=rightRotate(root);
root=leftRotate(root);
return root;
}
int getHeight(NODE root)
{
    if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
NODE balanceTree(NODE root)
{
    int heightDiff = getHeight(root->left) - getHeight(root->right);

    if (heightDiff > 1) {
        if (getHeight(root->left->left) >= getHeight(root->left->right))
            root = rightRotate(root);
        else {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    }
    else if (heightDiff < -1) {
        if (getHeight(root->right->right) >= getHeight(root->right->left))
            root = leftRotate(root);
        else {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }

    return root;
}


