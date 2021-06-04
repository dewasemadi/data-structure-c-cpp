#include <iostream>
#include <cstdlib>
using namespace std;

struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
} * root;

class avlTree
{
public:
    int height(avl_node *);
    int diff(avl_node *);

    avl_node *fun1(avl_node *);
    avl_node *fun2(avl_node *);
    avl_node *fun3(avl_node *);
    avl_node *fun4(avl_node *);

    avl_node *balance(avl_node *);
    avl_node *insert(avl_node *, avl_node *);

    void display(avl_node *, int);
    avlTree()
    {
        root = NULL;
    };
};

int main()
{
    int choice, item;
    avlTree avl;
    avl_node *temp;
    while (1)
    {
        cout << "\n------------------------" << endl;
        cout << " Impelementasi AVL Tree";
        cout << "\n------------------------" << endl;
        cout << "1.Tambah Node pada AVL Tree " << endl;
        cout << "2.Tampilkan AVL Tree" << endl;
        cout << "3.Keluar" << endl;
        cout << "Ketik opsi yang anda pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            temp = new avl_node;
            cout << "Ketik angka yang akan ditambahken ke AVL Tree: ";
            cin >> item;
            temp->data = item;
            root = avl.insert(root, temp);
            break;
        case 2:
            if (root == NULL)
            {
                cout << "Tree kosong, tidak dapat menampilkan Tree" << endl;
                continue;
            }
            cout << " AVL Tree yang Seimbangnya adalah:" << endl;
            avl.display(root, 1);
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "Pilihan yang anda masukkan tidak ada!" << endl;
        }
    }
    return 0;
}

int avlTree::diff(avl_node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = fun2(temp);
        else
            temp = fun3(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = fun4(temp);
        else
            temp = fun1(temp);
    }
    return temp;
}

// Right-right rotation
avl_node *avlTree::fun1(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// left-left rotation
avl_node *avlTree::fun2(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// left-right rotation
avl_node *avlTree::fun3(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = fun1(temp);
    return fun2(parent);
}

// right-left rotation
avl_node *avlTree::fun4(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = fun2(temp);
    return fun1(parent);
}

avl_node *avlTree::insert(avl_node *root, avl_node *newNode)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = newNode->data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (root->data == newNode->data)
    {
        cout << "Node yang akan ditambahkan sudah berada di dalam tree" << endl;
        return 0;
    }
    else if (newNode->data < root->data)
    {
        root->left = insert(root->left, newNode);
        root = balance(root);
    }
    else if (newNode->data >= root->data)
    {
        root->right = insert(root->right, newNode);
        root = balance(root);
    }
    return root;
}

void avlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout << "Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout << "      ";
        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}
