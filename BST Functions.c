#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
}Node;



//create Node function
Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


//inserting element in BST
Node *insert(Node *root, int data)
{
    if(root == NULL)
        return createNode(data);
    if(root->data < data)
        root->right = insert(root->right,data);
    else if(root->data > data)
        root->left = insert(root->left, data);
    
    return root;
}


//create BST function 
Node *create(Node *root)
{
    int n;
    printf("\nEnter limit: ");
    scanf("%d", &n);
    printf("Enter data: ");
    for(int i=0; i<n; i++)
    {
        int data;
        
        scanf("%d", &data);
        if(root == NULL)
        root = insert(root,data);
        else
        insert(root, data);
    }
    return root;
}


//preorder traversal data
void preOrder(Node *root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


//calculating total Nodes in BST
int tNode(Node *T)
{
    if(T == NULL)
     return 0;
    return tNode(T->left) + tNode(T->right) + 1;
}


//calculating leaf node in BST
int lNode(Node *root)
{
    if(root->left == NULL && root->right == NULL)
        return 1;
    return lNode(root->left) + lNode(root->right);
}


//printig level data
void levelPrint(Node *root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d\t",root->data);
    else if(level > 1)
        {
            levelPrint(root->left,level-1);
            levelPrint(root->right, level-1);
        }
}


//calculating Height of BST
int height(Node *root)
{
    if(root == NULL)
        return 0;
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if(leftHeight > rightHeight)
            return leftHeight +1;
        else
            return rightHeight+1;
    }
}

//printing level wise data in BST
void print(Node *root)
{
    int h = height(root);
    for(int i=1; i<=h; i++)
    {
        printf("Level %d: ", i);
        levelPrint(root,i);
    }
}
