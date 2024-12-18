// 2. Convert Infix Arithmetic Expressions into PostFix Arithmetic Expressions and evaluate them.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isfull()
{
    return top == MAX - 1;
}

int isempty()
{
    return top == -1;
}

void push(char data)
{
    if (isfull())
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = data;
}

char pop()
{
    if (isempty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

char peek()
{
    if (isempty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isdigit(infix[i]) || isalpha(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isempty() && peek() != '(')
            {
                postfix[j++] = pop();
            }
            if (!isempty() && peek() != '(')
            {
                printf("Invalid expression\n");
                return;
            }
            else
            {
                pop();
            }
        }
        else
        {
            while (!isempty() && precedence(infix[i]) <= precedence(peek()))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (!isempty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix)
{
    int i = 0;
    int stack[MAX];
    int top = -1;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            stack[++top] = postfix[i] - '0';
        }
        else
        {
            int op2 = stack[top--];
            int op1 = stack[top--];
            switch (postfix[i])
            {
            case '+':
                stack[++top] = op1 + op2;
                break;
            case '-':
                stack[++top] = op1 - op2;
                break;
            case '*':
                stack[++top] = op1 * op2;
                break;
            case '/':
                stack[++top] = op1 / op2;
                break;
            case '^':
                stack[++top] = op1 ^ op2;
                break;
            }
        }
        i++;
    }
    return stack[top];
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}