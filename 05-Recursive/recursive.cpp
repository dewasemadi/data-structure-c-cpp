// Recursive C++ program to recursively insert
// a node and recursively print the list.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

// Allocates a new node with given data
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the
// end of linked list using recursion.
Node *insertEnd(Node *head, int data)
{
    // If linked list is empty, create a
    // new node (Assuming newNode() allocates
    // a new node with given data)
    if (head == NULL)
        return newNode(data);

    // If we have not reached end, keep traversing
    // recursively.
    else
        head->next = insertEnd(head->next, data);
    return head;
}

void traverse(Node *head)
{
    if (head == NULL)
        return;

    // If head is not NULL, print current node
    // and recur for remaining list
    cout << head->data << " ";

    traverse(head->next);
}

// a recursive function to append data to a
//linked list after a specified value (key)
void insertAfterKey(Node *p, int key, int data)
{
    // initialize new node from new data
    Node *baru = newNode(data);
    if (p->data != key)
    {
        // if the old node does not have the same key,
        // the new node is automatically placed in the last position
        if (p->next == NULL)
        {
            p->next = baru;
            baru->next = NULL;
        }
        // If we have not reached the same key,
        // keep traversing recursively.
        else
            insertAfterKey(p->next, key, data);
    }
    // if we found the key position, insert new node
    else
    {
        baru->next = p->next;
        p->next = baru;
    }
}

//recursive function to delete a node with a
//specified value on the linked list
void deleteKey(Node *prev, Node *p, int key)
{
    // prev is used to point to the node before the node to be deleted
    // p is used to point to the node to be deleted
    if (prev->next == NULL)
        cout << "Node not found!";
    // if the node does not have the same key,
    if (prev->next->data != key)
        deleteKey(prev->next, p, key);
    else
    {
        p = prev->next; //13
        prev->next = p->next;
        free(p);
    }
}

// Driver code
int main()
{
    Node *head = NULL;
    head = insertEnd(head, 6);
    head = insertEnd(head, 8);
    head = insertEnd(head, 10);
    head = insertEnd(head, 12);
    head = insertEnd(head, 14);
    traverse(head);
    cout << "\n";
    insertAfterKey(head, 12, 13);
    insertAfterKey(head, 8, 9);
    insertAfterKey(head, 15, 16);
    traverse(head);
    cout << "\n";
    deleteKey(head, head, 16);
    traverse(head);
    return 0;
}