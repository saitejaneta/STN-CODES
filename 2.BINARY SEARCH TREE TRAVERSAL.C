//DSOE 9D: Binary Search Tree Traversal
/*
You are given N values to be inserted into a binary search tree.

Every value in the left subtree of a node x must be less than or equal to x and every value in the right subtree of a node x must be greater than x.

You are to insert the N values into a binary search tree in the order that they are given.

Print the resultant binary search tree's pre-order, in-order and post-order traversal on three different lines.

Your task is to write a program to print preorder, inorder and postorder traversal for a given Binary Search Tree using linked list implementation

Input Format

First line contains a number N
Next line contains N integers
Constraints

1 <= N <= 1000

Output Format

Display the preorder, inorder and postorder traversal in three different lines as explained

Sample Input 0

3
1 2 3
Sample Output 0

Preorder:1 2 3 
Inorder:1 2 3 
Postorder:3 2 1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct TreeNode 
{
    struct TreeNode *L;
    int val;
    struct TreeNode *R;
}*root=NULL;
struct TreeNode* insert(struct TreeNode *root,int x)
{
    if(root==NULL)
    {
        struct TreeNode *temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->L=NULL;
        temp->val=x;
        temp->R=NULL;
    
        return temp;
    }
    else if(x <= root->val)
        root->L=insert(root->L,x);
    else
        root->R=insert(root->R,x);
    return root;
}
void preorder(struct TreeNode *root)
{
    if(root!=NULL)
    {
        //step 1 : visit the root node 
        printf("%d ",root->val);
        //step2 : Traverse the LST
        preorder(root->L);
        //step 3 : Traverse the RST 
        preorder(root->R);
    }
}
void inorder(struct TreeNode *root)
{
    if(root)
    {
        //setpr 1: Traverse the LST
        inorder(root->L);
        //step2 :visit the root node
        printf("%d ",root->val);
        //step3 :Traverse the RST
        inorder(root->R);
    }
}
void postorder(struct TreeNode *root)
{
    if(root)
    {
        //step1 : Traverse the LST
        postorder(root->L);
        //step2: Traverse the RST
        postorder(root->R);
        printf("%d ",root->val);
    }
}
int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }
    printf("Preorder:");
    preorder(root);
    printf("\nInorder:");
    inorder(root);
    printf("\nPostorder:");
    postorder(root);
    return 0;
}

