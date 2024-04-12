#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
}Node;


Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}



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



void preOrder(Node *root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


int tNode(Node *T)
{
    if(T == NULL)
     return 0;
    return tNode(T->left) + tNode(T->right) + 1;
}


int lNode(Node *root)
{
    if(root->left == NULL && root->right == NULL)
        return 1;
    return lNode(root->left) + lNode(root->right);
}


void main()
{
    int ch;
    Node *root = NULL;
    do
    {
        printf("\n1.Create\n2.insert\n3.Display Inorder\n4.Count leaf Node\n5.Total Nodes\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: root = create(root);
                    break;
            case 2: int data;
                    printf("\nEnter elemet to insert: ");
                    scanf("%d", &data);
                    insert(root, data);
                    break;
            
            case 3: inOrder(root);
                    break;
                    
            case 4:
                    printf("Total leaf Nodes are: %d\n", lNode(root));
                    break;
            case 5: printf("Total Nodes are: %d\n", tNode(root));
                    break;
                    
            
            default: printf("Wrong Choice..");
        }
        
    }while(ch<=5);
}
