//DSOE 9B: Binary Tree Traversal
/*
Write a program to print preorder, inorder and postorder traversal for a given Binary Tree

You are given a binary tree in the form of Linked List.

Binary tree is represented as a Linked List in the following format:

Tree Node Structure

image

for given input values store the values in the Linked List representation of a binary tree then print its Preorder,Inorder and Postorder Traversal

Note: All inputs are valid inputs only

Input Format

First line an integer N
Second line an integer that value can be stored at root node of a binary tree
Next N-1 lines contain three values separated by space, first value is an integer denoting the parent node, second value is a character denoting position (left or right) of inserted node and third value is an integer denotes the child value to be inserted in the position.
Constraints

1 < = N <= 50

Output Format

Display the preorder, inorder and postorder traversal in three different lines as explained

Sample Input 0

3
1
1 L 2
1 R 3
Sample Output 0

Preorder:1 2 3 
Inorder:2 1 3 
Postorder:2 3 1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node 
{
    struct node *left;
    int data;
    struct node *right;
};
struct node* createNode(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
    
}
void preorder(struct node *root)
{
    if(root)
    {
        //1.visit root node 
        printf("%d ",root->data);
        //2. traverse the LSB in rec
        preorder(root->left);
        //3. tracerse the RST in rec
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root)
    {
        //1. traverse the LSB in rec
        inorder(root->left);
        
        //2.visit root node 
        printf("%d ",root->data);
        //3. tracerse the RST in rec
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root)
    {
        //1. traverse the LSB in rec
        postorder(root->left);
            //2. tracerse the RST in rec
        postorder(root->right);
    
        //3.visit root node 
        printf("%d ",root->data);
    }
}
struct node* find(struct node *root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return root;
    struct node *t1=find(root->left,key);
    if(t1!=NULL)
        return t1;
    struct node *t2=find(root->right,key);
    
    return t2;
    
}
int height(struct node *root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    if(lh>rh)
        return lh+1;
    else 
        return rh+1;    
}
int main()
{
    int i,n,r;
    scanf("%d",&n);
    scanf("%d",&r);
    struct node *root=createNode(r);
    for(i=1;i<n;i++)
    {
        int p,c;char pos;
        scanf("%d %c %d",&p,&pos,&c);
        struct node *parent=find(root,p);
        if(pos=='L')
            parent->left=createNode(c);
        else 
            parent->right=createNode(c);
    }
    printf("Preorder:");
    preorder(root);
    printf("\nInorder:");
    inorder(root);
    printf("\nPostorder:");
    postorder(root);
   
    return 0;
}
