#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    struct Node *temp;
    int val;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}
int evaluatePostfix(char exp[])
{
    int i = 0;
    int op1, op2;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (exp[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }

    return pop();
}

int main()
{
    char exp[] = "231*+9-";

    printf("Result = %d", evaluatePostfix(exp));

    return 0;
}
