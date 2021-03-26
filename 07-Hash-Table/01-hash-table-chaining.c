#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define size 4
#define h(k) k % size

struct node
{
    char *key, *val;
    struct node *next;
};

struct node *chain[size];

void init()
{
    for (int i = 0; i < size; i++)
        chain[i] = NULL;
}

int keyToValue(char *key)
{
    int n = strlen(key), radix128 = 0;
    for (int i = 0; i < n; i++)
        radix128 += key[n - 1 - i] * pow(128, i);
    return radix128;
}

void insert(char *key, char *value)
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->key = key;
    newNode->val = value;

    //calculate hash key
    int idx = h(keyToValue(key));
    newNode->next = chain[idx];
    chain[idx] = newNode;
}

void delete (char *key)
{
    int idx = h(keyToValue(key));
    struct node *p = chain[idx];
    struct node *prev = p;

    while (p && strcmp(key, p->key))
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
        printf("\"%s\" is not found. Nothing to delete.\n", key);
    else if (p == prev)
    {
        chain[idx] = p->next;
        printf("\"%s\" is successfully removed\n", key);
        free(p);
    }
    else
    {
        prev->next = p->next;
        printf("\"%s\" is successfully removed\n", key);
        free(p);
    }
}

struct node *search(char *key)
{
    int idx = h(keyToValue(key));
    struct node *p = chain[idx];

    while (p && strcmp(key, p->key))
        p = p->next;
    return p;
};

void print()
{
    for (int i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d] --> ", i);
        while (temp)
        {
            printf("%s:%s --> ", temp->key, temp->val);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    // init array of list to NULL
    init();
    insert("ab", "red");   // i = 2'
    insert("bc", "black"); // i = 3
    insert("cd", "white"); // i = 0
    insert("12", "night"); // i = 2''
    insert("xyz", "kids"); // i = 2'''

    print();

    struct node *res = search("ab");
    if (res == NULL)
        printf("Data is not found!\n");
    else
        printf("%s:%s\n", res->key, res->val);

    delete ("12");
    delete ("cd");
    delete ("tx");
    print();
    return 0;
}