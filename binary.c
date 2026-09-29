#include <stdio.h>
#define MAX 32

struct stack
{
    int data[MAX];
    int top;
};

void push(struct stack *s, int x)
{
    s->data[++s->top] = x;
}

int pop(struct stack *s)
{
    return s->data[s->top--];
}

void decimalToBinary(struct stack *s, int n)
{
    if (n == 0)
    {
        printf("Binary = 0\n");
        return;
    }

    while (n > 0)
    {
        push(s, n % 2);
        n = n / 2;
    }

    printf("Binary = ");

    while (s->top != -1)
    {
        printf("%d", pop(s));
    }

    printf("\n");
}

int main()
{
    struct stack s;
    int n;

    s.top = -1;

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Enter a non-negative number.\n");
    else
        decimalToBinary(&s, n);

    return 0;
}
