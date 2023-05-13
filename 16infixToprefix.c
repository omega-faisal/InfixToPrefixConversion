#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char data)
{

    ptr->top++;
    ptr->arr[ptr->top] = data;
}
char pop(struct stack *ptr)
{

    char data;
    data = ptr->arr[ptr->top];
    ptr->top--;
    return data;
}
char stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int isOperator(char ch)
{
    if(ch=='+' || ch=='-' ||ch=='*' ||ch=='/'||ch=='^')
    {
        return 1;
    }
    else
    return 0;
}
int precedence(char ch)
{
    if(ch=='^')
    {
        return 4;
    }
    if(ch=='*'||ch=='/')
    {
        return 3;
    }
    if(ch=='+'||ch=='-')
    {
        return 2;
    }
    else
    return 0;
}
char *infixToprefix(char *infix)
{
    struct stack *ps=(struct stack*)malloc(sizeof(struct stack));
    ps->size=100;
    ps->top=-1;
    ps->arr=(char*)malloc(ps->size*sizeof(char));
    int i=0;
    int j=0;
    char *postfix=(char*)malloc(strlen(infix)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++,j++;
        }
        else{
            if(precedence(infix[i])>precedence(stacktop(ps)))
            {
                push(ps,infix[i]);
                i++;
            }
            else
            {
               postfix[j]=pop(ps);
               //push(ps,infix[i]);
               j++;
            }
        }
    }
    while(!isempty(ps))
    {
        postfix[j]=pop(ps);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char exp[100];
    printf("enter the expression\n");
    scanf("%s",exp);
    printf("the postfix expression is:%s",infixToprefix(exp));  
    return 0;
}