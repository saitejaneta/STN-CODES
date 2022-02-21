//DSOE 9C: Level Order of a Binary Tree
/*
Your task is to write a program to print level order traversal for a given Binary Tree Here are a few examples:

Ex1: 1 / \ 2 3 Level Order Traversal:1 2 3

Ex2: 1 / \ 2 3 / \ \ 4 5 6 Level Order Traversal:1 2 3 4 5 6

Input Format

First line an integer N
Second line an integer that value can be stored at root node of a binary tree
Next N-1 lines contain three values separated by space, first value is an integer denoting the parent node, second value is a single capital letter character denoting position (left or right) of inserted node and third value is an integer denotes the child value to be inserted in the position.
Note: All inputs are valid inputs only.

Constraints

1 < = N <= 100

Output Format

Print the level order traversal as explained

Sample Input 0

3
1
1 L 2
1 R 3
Sample Output 0

Level Order Traversal:1 2 3
*/

#include <stdio.h>
#include <math.h>
int a[2000];
int q[2000],f=-1,r=-1,max;
int find(int k)
{
    int i;
    for(i=0;i<max;i++)
    {
        if(k==a[i])
            break;
    }
    return i;
}
void enQ(int x)
{
    if(f==-1)
    {
        f++;r++;
    }
    else 
        r++;
    q[r]=x;
}
int deQ()
{
    int x=q[f];
    if(f==r)
        f=r=-1;
    else 
        f++;
    return x;
}
void level()
{
    //step 1: store the root in Q 
    enQ(a[0]);
    while(f!=-1) //if Q is not empty
    {
       int x=deQ(); // delete 
       printf("%d ",x);
       int i=find(x);
       if(a[2*i+1]!=0) //if left child exist
        enQ(a[2*i+1]);
       if(a[2*i+2]!=0) //if right child exist
        enQ(a[2*i+2]);
    }
}
int main()
{
    int i,n,r;
    scanf("%d",&n);
    max=pow(2,n)-1;
    scanf("%d",&r);
    a[0]=r;
    for(i=1;i<n;i++)
    {
        int p,c;char pos;
        scanf("%d %c %d",&p,&pos,&c);
        int j=find(p);
        if(pos=='L')
            a[2*j+1]=c;
        else 
            a[2*j+2]=c;
    }
    printf("Level Order Traversal:");
    level();
    return 0;
}
