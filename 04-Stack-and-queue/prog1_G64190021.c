#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100
#define TRUE 1
#define FALSE 0

typedef struct stack
{
    int item[STACKSIZE], top;
} st;

void init(st *);
void push(st *, int x);
int pop(st *);
int empty(st *);
int stacktop(st s);

void main()
{
    st s;
    int c, x;
    char ch;
    system("cls");

start:
    printf("1. initialization of stack\n");
    printf("2. Insertion in the stack (push)\n");
    printf("3. Removal from the stack (pop)\n");
    printf("4. Displaying the top Element of the stack\n");
    printf("5. Exit\n");
    printf("============================================\n");
    printf("Enter your choice : \t");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        init(&s);
        break;
    case 2:
        printf("\nEnter the element to be inserted: ");
        scanf("%d", &x);
        push(&s, x);
        break;
    case 3:
        x = pop(&s);
        printf("\nRemoved item is: =>\t%d", x);
        break;
    case 4:
        x = stacktop(s);
        printf("\nStacktop item is: =>\t%d", x);
        break;
    case 5:
        exit(1);
    default:
        printf("\nWrong choice");
        break;
    }

    printf("\nDo you wish to continue?(y/n) : ");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        goto start;
}

void init(st *s)
{
    s->top = -1; //cek 1
}

int empty(st *s)
{
    if (s->top == -1) //cek 2
        return TRUE;
    else
        return FALSE;
}

void push(st *s, int x)
{
    if (s->top == STACKSIZE - 1) //cek 3
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->top++; //cek 4
    s->item[s->top] = x;
}

int pop(st *s)
{
    if (empty(s))
    {
        printf("Stack Underflows");
        exit(1);
    }
    int y = s->item[s->top]; //y buat nampung nilai yang di pop coy
    s->top--;                //cek 5
    return y;
}

int stacktop(st s)
{
    int y = s.item[s.top];
    return y;
}