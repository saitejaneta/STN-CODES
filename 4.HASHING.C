//DSOE 10B: Hashing
/*
Write a program to search an element from a given array using Hash table Using this algorithm the Time Complexity will be O(1) but Space Complexity will be O(n) Array elements need not be in sorted order

Input Format

First line an integer N
Second line N integers
Third line an integer K
Constraints

1 <= N < = 100000

Output Format

Print “Yes” if given element present in the array otherwise print “No”

Sample Input 0

5
4 8 13 27 41
55
Sample Output 0

No
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;scanf("%d",&n);
    int a[n],i,key;
    int h[100000]={0};
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        h[a[i]]=1;
    }
    scanf("%d",&key);
    if(h[key])
        printf("Yes");
    else 
        printf("No");
    return 0;
}
