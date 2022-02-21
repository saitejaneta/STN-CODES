//DSOE 9A: Binary Tree Traversal
/*
Write a program to print preorder, inorder and postorder traversal for a given Binary Tree You are given a binary tree in the form of an array.

Binary tree is represented as an array in the following format: 1. The root node value is stored in a[0],

If the value of a parent node is stored in a[i], then the value for the left child of the node is stored in a[2*i+1] and the value for the right child of the node is stored in a[2*i+2]

for any node, if a[i] is 0 it means the node is null for given input values store the values in the array representation of a binary tree, print its Preorder,Inorder and Postorder Traversal

Note: All inputs are valid inputs only

Input Format

First line an integer N
Second line an integer that value can be stored at root node of a binary tree
Next N-1 lines contain three values separated by space, first value is an integer denoting the parent node, second value is a character denoting position (left or right) of inserted node and third value is an integer denotes the child value to be inserted in the position
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
int a[100];
void preorder(int i)
{
    if(i>=0 && i<100 && a[i]!=0)
    {
        printf("%d ",a[i]);
        preorder(2*i+1);
        preorder(2*i+2);
    }
}
void inorder(int i)
{
    if(i>=0 && i<100 && a[i]!=0)
    {
        inorder(2*i+1);
        printf("%d ",a[i]);
        inorder(2*i+2);
    }
}
void postorder(int i)
{
    if(i>=0 && i<100 && a[i]!=0)
    {
        postorder(2*i+1);
        postorder(2*i+2);
        printf("%d ",a[i]);
    }
}

int main()
{
    int i,j,n,r;
    scanf("%d",&n);
    scanf("%d",&r);
    a[0]=r;
    for(i=1;i<n;i++)
    {
        int p,c;char pos;
        scanf("%d %c %d",&p,&pos,&c);
        for(j=0;j<100;j++)
        {
            if(p==a[j])
                break;
        }
        if(pos=='L')
            a[2*j+1]=c;
        else 
            a[2*j+2]=c;
    }
    printf("Preorder:");
    preorder(0);
    printf("\nInorder:");
    inorder(0);
    printf("\nPostorder:");
    postorder(0);
    return 0;
}

