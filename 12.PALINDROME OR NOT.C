//DSOE 6F: Palindrome or Not
/*
Your task is to check whether the given string is a palindrome or not using a stack.

Input Format

First line an integer N
Next N lines each line contain single string

Output Format

Print “YES” or “NO” in N lines according to the problem statement

Sample Input 0

3
abba
liril
abbabaa
Sample Output 0

YES
YES
NO
*/

// PALINDROME USING STACK
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char s[100];
int top=-1;
void push(char x)
{
    top++;
    s[top]=x;
}
void pop()
{
    top--;
}
int main() 
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[100];
        scanf("%s",str);
        int i=0,f=0;
        while(str[i])
        {
            push(str[i]);
            i++;
        }
        i=0;
        while(str[i])
        {
            if(str[i]!=s[top])
            {
                f=1;
                break;
            }
            else 
            {
                pop();
            }
            i++;
        }
        if(top==-1 && str[i]=='\0')
            printf("YES\n");
        if(f==1)
            printf("NO\n");
      
        top=-1;
    }
    return 0;
}



