#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

class BST
{
private:
    Node *root;
    Node *insertNode(Node *rt, int data)
    {
        if (!rt)
            return new Node(data);

        if (data < rt->data)
            rt->left = insertNode(rt->left, data);
        else if (data > rt->data)
            rt->right = insertNode(rt->right, data);
        else
            return rt;

        return rt;
    }
    Node *findMin(Node *temp)
    {
        if (!temp)
            return temp;

        while (temp->left)
            temp = temp->left;
        return temp;
    }

    Node *deleteNode(Node *rt, int data)
    {
        if (!rt)
            return rt;

        if (data < rt->data)
            rt->left = deleteNode(rt->left, data);
        else if (data > rt->data)
            rt->right = deleteNode(rt->right, data);
        else
        {
            if(!rt->left || !rt->right)
            {
                if(!rt->left)
                {
                    Node* temp = rt->right;
                    delete rt;
                    return temp;
                }
                else if(!rt->right)
                {
                    Node* temp = rt->left;
                    delete rt;
                    return temp;
                }
            }
            else
            {
                Node *temp = findMin(rt->right);
                rt->data = temp->data;
                rt->right = deleteNode(rt->right, temp->data);
            }
        }
        return rt;
    }
    void display(Node *rt)
    {
        if (!rt)
            return;

        display(rt->left);
        cout << rt->data << "->";
        display(rt->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    void insert(int data)
    {
        root = insertNode(root, data);
    }
    void Display()
    {
        display(root);
    }
    void Delete(int data)
    {
        root = deleteNode(root, data);
    }
};
int main()
{
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(17);
    bst.Delete(7);
    bst.Delete(17);
    bst.Display();

    return 0;
}