/* PROGRAM FOR BINARY SEARCH */

#include<stdio.h>
#include<stdlib.h>

int main()
{
int x[10],i,key,low,high,n,midpos;
//clrscr();
//printf("\n Enter the total number of elements");
scanf("%d",&n);
//printf("Enter the elements in ascending order");
for(i=0;i<n;i++)
{
scanf("%d",&x[i]);
}

//printf("\n Enter element to be search");
scanf("%d",&key);
low=0;
high=n-1;

while(low<=high)
{
midpos=(low+high)/2;
if(key==x[midpos])
{
printf("Yes");
//break;
exit(0);
}
else if(key<x[midpos])
high=midpos-1;
else
low=midpos+1;
}
printf("No");
//printf("\n END OF PROGRAM");
return 0;
}
