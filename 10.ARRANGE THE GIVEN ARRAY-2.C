//DSOE 7C: Arrange the given Array-2
/*
You are given an array arr[] of N elements in sorted order except last element. Your task is to insert the last element in correct position so that all elements will become as sorted in order.

Input Format

First line an integer N
Second line N integers
Constraints

1 <= N < = 100000

Output Format

Print the array elements after inserting

Sample Input 0

6
4 7 10 12 20 9
Sample Output 0

4 7 9 10 12 20
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    int last=a[n-1];
    for(i=n-2;i>=0;i--)
    {
        if(a[i]>last)
        {
            a[i+1]=a[i];
        }
        else 
            break;
        
    }
    a[i+1]=last;
    
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}


