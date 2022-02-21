//DSOE 7A: Arrange the given Array-1
/*
Write a program for given array arr[] and an integer K,swap the first element of the array with the smallest element of the array, then second element of the array with the second smallest element in the array and so on. Repeat this process K times.

Input Format

First line an integer N
Second line N integers
Third line an integer K
Constraints

1 <= N < = 100000

Output Format

Print the array after ‘K’ times swapping

Sample Input 0

6
4 5 6 1 2 3
3
Sample Output 0

1 2 3 4 5 6
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;scanf("%d",&n);
    int a[n],i,minIndex,j,k;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        minIndex=i;
        for(j=i+1;j<n;j++)
        {
            if(a[minIndex] > a[j])
                minIndex=j;
        }
        int t=a[minIndex];a[minIndex]=a[i];a[i]=t;
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

