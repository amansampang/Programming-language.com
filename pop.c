#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
typedef struct
{
    /* data */
    int tos;
    char item[MAX];
}stack;
int isEmpty(stack *s)
{
    return s->tos==-1;
}
int isfull(stack *s)
{
    return s->tos==MAX-1;
}
char pop(stack*s) //one must check whether the stack is empty before calling pop'
{
    if(isEmpty(s))
    {
        printf("illegal attempt to pop an item from the empty stack");
        getch();
        exit(0);
    }
 return s->item[s->tos--];
}
void push(stack *s,char ch)
{
    if(isfull(s))
    {
       printf("illegal attempt to push an item from the full stack");
       getch();
       exit(0);
    }
s->item[++s->tos]=ch;//put the new item at the next position of the toss
    
}
int main()
{
    stack st;
    char exp[MAX];
    char symb,poppedsymb;
    int valid=TRUE;//initially we assusme that our expression is valid
    int i;
    st.tos=-1;//empty stack
    
    printf("Enter your Expression:");
    gets(exp);
    for(i=0;i<strlen(exp);i++)//read all the characters of the expression one by one
    {
        symb=exp[i];
        if(symb=='('||symb=='{'||symb=='[')
        {
            push(&st,symb);
        }
        else if(symb==')'||symb=='}'||symb==']')
        {
            if(isEmpty(&st))//if nothing is in stack
            {
                valid=FALSE;
                break;
            }
            poppedsymb=pop(&st);
            if((symb==')' && poppedsymb!='(')
            ||(symb=='{'&& poppedsymb!='}')
            ||(symb=='[' && poppedsymb!=']'))
            {
                valid=FALSE;
                break;
            }
        }
        
    }
    if(!isEmpty(&st)) //no.of opener is more than no of close brackets
       valid=FALSE;
    if(valid)
    {
        printf("Expression is valid");
    }
    else
    {
        printf("Expression is invalid");
    }
return 0;
}

