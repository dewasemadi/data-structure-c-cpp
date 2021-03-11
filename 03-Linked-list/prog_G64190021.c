#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;

NODEPTR list = NULL;

// func prototype
NODEPTR getnode(void);
void freenode(NODEPTR);
void insbeg(int);
void insafter(int, int);
void insend(int);
int delbeg();
int delafter(int);
int delend();
void traverse();
// tambahan
void inserttoK(int, int);
void cetak_ganjil();
int delbeforend();
int countAll();

void main()
{
    NODEPTR p;
    int x, c, y, k;
    char ch;
begin:
    printf("==================================\n");
    printf("1. Insert in the beginning\n");
    printf("2. Insert after a node\n");
    printf("3. Insert in the end\n");
    printf("4. Delete from the beginning\n");
    printf("5. Delete after a node\n");
    printf("6. Delete from the end\n");
    printf("7. Traverse\n");
    // new menu :)
    printf("8. Insert node from position\n");
    printf("9. Show odd numbers\n");
    printf("10. Delete before end\n");
    printf("11. Count all nodes\n");
    // new menu
    printf("12. Exit\n");
    printf("==================================\n");
    printf("Enter your choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        printf("\nEnter the element to be inserted: ");
        scanf("%d", &x);
        insbeg(x);
        break;
    case 2:
        printf("\nEnter the element to be inserted after which node: ");
        scanf("%d", &y);
        printf("\nEnter the element to be inserted: ");
        scanf("%d", &x);
        insafter(y, x);
        break;
    case 3:
        printf("\nEnter the element to be inserted: ");
        scanf("%d", &x);
        insend(x);
        break;
    case 4:
        printf("\nThe deleted item is: => %d", delbeg());
        break;
    case 5:
        printf("\nEnter the element to be deleted after which node: ");
        scanf("%d", &y);
        printf("The deleted item is: => %d", delafter(y));
        break;
    case 6:
        printf("The deleted item is: => %d", delend());
        break;
    case 7:
        traverse();
        break;
    // insert node when posisiton k = ?
    case 8:
        printf("\nEnter the position: ");
        scanf("%d", &k);
        printf("\nEnter the element to be inserted: ");
        scanf("%d", &x);
        inserttoK(k, x);
        break;
    case 9:
        cetak_ganjil();
        break;
    case 10:
        printf("The deleted item is: => %d", delbeforend());
        break;
    case 11:
        printf("\nThe number of nodes: %d\n", countAll());
        break;
    case 12:
        exit(1);
    default:
        printf("\nWrong choice");
        break;
    }

    printf("\nDo you wish to continue?(y/n): ");
    fflush(stdin);
    scanf("%c", &ch);

    if (ch == 'y' || ch == 'Y')
        goto begin;
}

//get node
NODEPTR getnode(void)
{
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}

// free node
void freenode(NODEPTR p)
{
    free(p);
}

// traverse
void traverse()
{
    NODEPTR p = list;
    printf("\nThe Linked List is: \n");
    while (p != NULL)
    {
        printf("%d\t", p->info);
        p = p->next;
    }
}

// insert after
void insafter(int y, int x)
{
    NODEPTR p, q = getnode();
    q->info = x;
    for (p = list; p->info != y && p != NULL; p = p->next)
        ;
    q->next = p->next;
    p->next = q;
}

// insert begin
void insbeg(int x)
{
    NODEPTR p = getnode();
    p->info = x;
    p->next = list;
    list = p;
}

// insert end
void insend(int x)
{
    NODEPTR p = list, q = getnode();
    q->info = x;
    q->next = NULL;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}

// delete begin
int delbeg()
{
    NODEPTR p = list;
    int x = p->info;
    list = p->next;
    freenode(p);
    return x;
}

// delete after
int delafter(int y)
{
    NODEPTR p = list, q;
    int x;
    for (p = list; p->info != y && p != NULL; p = p->next)
        ;
    q = p->next;
    p->next = q->next;
    x = q->info;
    freenode(q);
    return x;
}

// delete end
int delend()
{
    NODEPTR p = list, q = NULL;
    int x;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    x = p->info;
    freenode(p);
    q->next = NULL;
    return x;
}

// insert to posisiton k = ?
void inserttoK(int k, int x)
{
    // p = lama, q = baru
    NODEPTR p = list, q = getnode();
    q->info = x; //masukin nilai
    int cek = 0;
    if (k == 1)
        insbeg(x);
    else
    {
        for (int i = 1; i < k - 1; i++) // cari posisi dimana mau dimasukin node baru
        {
            if (p->next == NULL)
                cek = 1;
            else
                p = p->next;
        }
        // kalo user input K > banyaknya node, otomatis taruh paling akhir
        if (cek == 0)
        {
            q->next = p->next;
            p->next = q;
        }
        else
            insend(x);
    }
}

// cetak ganjil
void cetak_ganjil()
{
    NODEPTR p = list;
    printf("\nThe odd numbers on linked list is: \n");
    while (p != NULL)
    {
        if (p->info % 2 != 0)
            printf("%d\t", p->info);
        p = p->next;
    }
}

// delete before end
int delbeforend()
{
    // p = lama, q baru
    NODEPTR p = list, q, temp;
    int x;
    // kondisi kalo node kosong/cuma isi 1
    if (p == NULL || p->next == NULL)
        printf("\nUps, cannot run this command!\n");
    // 1 2 3 4 5 6
    while (p->next->next->next != NULL)
    {
        q = p;
        p = p->next; //4
    }
    temp = p->next;
    x = temp->info;
    q = p->next->next;
    p->next = q;
    return x;
}

// count all element
int countAll()
{
    NODEPTR p = list;
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}
