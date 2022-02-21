/*DSOE 7E: Merge the arrays

For given two sorted arrays write a program to merge them into one sorted array

Input Format

First line an integer M
Second line M integers
Third line an integer N
Fourth line N integer

Output Format

Print the array after merging

Sample Input 0

5
4 8 13 27 41
3
2 6 11
Sample Output 0

2 4 6 8 11 13 27 41

*/

#include <stdio.h>

int main()
{
    
    int n1,n2,n3;            //Array Size Declaration
    int c[10];
    
    //printf("\nEnter the size of first array ");
    scanf("%d",&n1);
    int a[n1];
    //printf("\nEnter the sorted array elements");
    for(int i=0;i<n1;i++)      //Array Initialized
    {
       scanf("%d",&a[i]);
       c[i]=a[i];
    }
    int k=n1;
    
    //printf("\nEnter the size of second array ");
    scanf("%d",&n2);
    int b[n2];
   // printf("\nEnter the sorted array elements");
    for(int i=0;i<n2;i++)      //Array Initialized
    {
        scanf("%d",&b[i]);
        c[k]=b[i];
        k++;
    }
    
    n3=n1+n2;
    //int c[n3];
    
    //printf("\nThe merged array..\n");
    //for(int i=0;i<n3;i++)
    //printf("%d ",c[i]);        //Print the merged array
    
    //printf("\nAfter sorting...\n");
    for(int i=0;i<n3;i++)         //Sorting Array
    {
        int temp;
        for(int j=i+1; j<n3 ;j++)
        {
            if(c[i]>c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }   
    
    for(int i=0 ; i<n3 ; i++)       //Print the sorted Array 
    {
        printf("%d ",c[i]);
    }
    return 0;   
}
