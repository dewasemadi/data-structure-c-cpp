#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20
#define h(k) k % SIZE
#define h_probe(k, i) (h(k) + i) % SIZE

struct node
{
    char *key, *val;
};

struct node T[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
        T[i].key = NULL;
}

int keyToValue(char *key)
{
    int n = strlen(key), radix128 = 0;
    for (int i = 0; i < n; i++)
        radix128 += key[n - 1 - i] * pow(128, i);
    return radix128;
}

void insert(char *key, char *val)
{
    int idx, i = 0;
    do
    {
        idx = h_probe(keyToValue(key), i);
        if (T[idx].key == NULL || T[idx].key == "DELETED")
        {
            T[idx].key = key;
            T[idx].val = val;
            return;
        }
        else
            i++;

    } while (i != idx);
    fprintf(stderr, "hash table overflow!");
}

void delete (char *key)
{
    int idx, i = 0;
    do
    {
        idx = h_probe(keyToValue(key), i);
        if (!strcmp(T[idx].key, key))
        {
            printf("key '%s' with value '%s' has been deleted\n\n", T[idx].key, T[idx].val);
            T[idx].key = "DELETED";
            T[idx].val = NULL;
            return;
        }
        else
            i++;
    } while (T[idx].key != NULL);
}

int search(char *key)
{
    int idx, i = 0;
    do
    {
        idx = h_probe(keyToValue(key), i);
        if (!strcmp(T[idx].key, key))
            return idx;
        else
            i++;
    } while (i != idx && T[idx].key != NULL && T[idx].key != "DELETED");
    return -1;
}

void print()
{
    for (int i = 0; i < SIZE; i++)
        printf("%s:%s\n", T[i].key, T[i].val);
}

int main()
{
    // init array of list to NULL
    init();
    insert("ab", "red");   // i = 14
    insert("bc", "black"); // i = 3
    insert("cd", "white"); // i = 12
    insert("12", "night"); // i = 2
    insert("xyz", "kids"); // i = 10

    print();

    int idx = search("cd");
    if (idx != -1)
        printf("\n%s:%s\n\n", T[idx].key, T[idx].val);
    else
        printf("\nData is not found!\n\n");

    delete ("ab");
    print();
    return 0;
}