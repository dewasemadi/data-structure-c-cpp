#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0

typedef struct queue
{
    int item[MAXQUEUE], front, rear;
} que;

void init(que *pq);
void insert(que *pq, int x);
int remov(que *pq);
int empty(que *pq);

void main()
{
    que q;
    int x, c;
    char ch;
    system("cls");
    init(&q);

start:
    printf("1. Initialize the queue\n");
    printf("2. Insert the queue         (enqueue)\n");
    printf("3. Remove from the queue    (dequeue)\n");
    printf("4. Exit\n");
    printf("============================================\n");
    printf("Enter your choice : \t");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        init(&q);
        break;
    case 2:
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &x);
        insert(&q, x);
        break;
    case 3:
        x = remov(&q);
        printf("\nRemoved item is : =>\t%d", x);
        break;
    case 4:
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

void init(que *pq)
{
    pq->rear = -1;
    pq->front = 0;
}

// kalo enqueue, nilai rear + 1
void insert(que *pq, int x)
{
    if (pq->rear == MAXQUEUE - 1) //cek 7
    {
        printf("Queue Overflows");
        exit(1);
    }
    pq->rear++; //cek 8
    pq->item[pq->rear] = x;
    // printf("Nilai rear : %d", pq->rear);
}

// kalo dequeue, nilai front + 1
int remov(que *pq)
{
    if (empty(pq))
    {
        printf("Queue Underflows");
        exit(1);
    }
    int x = pq->item[pq->front];
    pq->front++; // cek 9
    // printf("Nilai front :%d", pq->front);
    return x;
}

int empty(que *pq)
{
    if ((pq->rear - pq->front + 1) == 0) // cek 10
        return TRUE;
    else
        return FALSE;
}