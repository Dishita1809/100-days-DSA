#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    return stack[top--];
}

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, k = 0;

    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        if(isalnum(c))
        {
            postfix[k++] = c;
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    while(top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}
