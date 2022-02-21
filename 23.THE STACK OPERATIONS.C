//DSOE 5D: The Stack Operations

/*
Your task is to implement following Stack operations: - 1.push(x):insert x at top of the stack - 2.pop():remove top of the element if exist, otherwise print “Invalid” - 3.top():print top of the element if exist, otherwise print “Invalid” - 4.isEmpty():if stack is empty print 1 otherwise print 0 - 5.min():print minimum value form the stack if exist, otherwise print “Invalid” - 6.max():print maximum value form the stack if exist, otherwise print “Invalid”

Note: Accessing elements other than top element is illegal in Stack and operations should be performed in O(1) time complexity

Input Format

First line an integer N
Next N lines each line contain one operation each:1 X denotes insert X value to stack, 2 denotes pop the top element,3 denotes print top element, 4 denotes check empty or not,5 denotes print the min value and 6 denotes print the min value
Constraints

1 <= N < = 25

Output Format

For every 5 and 6 type operations print the min and max element from the stack if exist otherwise print “Invalid”

Sample Input 0

5
1 10
1 20
4
2
3
Sample Output 0

0
10
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *stack,top=-1;
int *MinStack,*MaxStack,mintop=-1,maxtop=-1;

void push(int x)
{
    stack[++top]=x;
}

int pop()
{
    int x=stack[top];
    top--;
    return x;
}

void ipush(int x)
{
    MinStack[++mintop]=x;
}

void xpush(int x)
{
    MaxStack[++maxtop]=x;
}

void ipop()
{
    mintop--;
}

void xpop()
{
    maxtop--;
}

void isEmpty()
{
    if(top==-1)
        printf("1\n");
    else 
        printf("0\n");
}

void Top()
{
    if(top==-1)
        printf("Invalid\n");
    else 
        printf("%d\n",stack[top]);
}

void minTop()
{
    if(top==-1)
        printf("Invalid\n");
    else
        printf("%d\n",MinStack[mintop]);
}

void maxTop()
{
    if(top==-1)
        printf("Invalid\n");
    else
        printf("%d\n",MaxStack[maxtop]);
}


int main() 
{
    stack=(int*)malloc(100*sizeof(int)); //Dynamic Array
    MinStack=(int*)malloc(100*sizeof(int)); //Dynamic Array
    MaxStack=(int*)malloc(100*sizeof(int)); //Dynamic Array
   
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int x;
            scanf("%d",&x);
            if(top==-1)
            {
               ipush(x);
               xpush(x);
            }
            else
            {
                if(x <= MinStack[mintop])
                    ipush(x);
                if(x >= MaxStack[maxtop])
                    xpush(x);
            }
            push(x);
        }
        else if(ch==2)
        {
            if(top==-1)
            {
                printf("Invalid\n");
            }
            else 
            {
                int x=pop();
                if(MinStack[mintop]==x)
                    ipop();
                if(MaxStack[maxtop]==x)
                    xpop();
            }
        }
        else if(ch==3)
            Top();
        else if(ch==4) 
            isEmpty();
        else if(ch==5)
            minTop();
        else 
            maxTop();
    }
    
    return 0;
}

