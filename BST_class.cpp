#include <iostream>
using namespace std;
/*
functions to be implemented
1 search
2 insert
3 deletion
4 printTree

*/
class bst
{
    // class for binary tree node
    class node
    {
    public:
        int data;
        node *left;
        node *right;

        node(int data)
        {
            this->data = data;
            left = right = NULL;
        }

        ~node()
        {
            delete left;
            delete right;
        }
    };

private:
    node *root;

public:
    bst()
    {
        root = NULL;
    }
    ~bst()
    {
        delete root;
    }

private:
    // helper function for serach function
    bool searchHelper(node *tnode, int data)
    {
        // base case
        if (!tnode)
            return false;
        if (tnode->data == data)
            return true;
        else if (data < tnode->data)
            return searchHelper(tnode->left, data);
        else
            return searchHelper(tnode->right, data);
    }

    // helper function for insert function
    node *insertHelper(node *tnode, int data)
    {
        // adding node where jagah khaali hai
        if (tnode == NULL)
        {
            node *newNode = new node(data);
            return newNode;
        }
        // going right if data if bigger
        if (data > tnode->data)
            tnode->right = insertHelper(tnode->right, data);
        // going left if data is smaller
        else
            tnode->left = insertHelper(tnode->left, data);
        return tnode;
    }

    // helper function for delete function
    node *deleteHelper(node *tnode, int data)
    {
        if (tnode == NULL)
            return NULL;
        if (tnode->data == data)
        {
            if (!tnode->left && !tnode->right)
            {
                delete tnode;
                return NULL;
            }
            else if (!tnode->right)
            {
                node *temp = tnode->left;
                tnode->left = NULL;
                delete tnode;
                return temp;
            }
            else if (!tnode->left)
            {
                node *temp = tnode->right;
                tnode->right = NULL;
                delete tnode;
                return temp;
            }
            else
            {
                node *temp = tnode->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                int rightMin = temp->data;
                tnode->data = rightMin;
                tnode->left = deleteHelper(tnode->left, rightMin);
                return tnode;
            }
        }
        else if (tnode->data < data)
        {
            tnode->right = deleteHelper(tnode->right, data);
            return tnode;
        }
        else
        {
            tnode->left = deleteHelper(tnode->left, data);
            return tnode;
        }
        return tnode;
    }

    void printBSTHelper(node *tnode)
    {
        if (tnode == NULL)
            return;
        cout << tnode->data << " ";
        if (tnode->left != NULL)
            cout << "L" << tnode->left->data;
        if (tnode->right != NULL)
            cout << "R" << tnode->right->data;

        cout << endl;
        printBSTHelper(tnode->left);
        printBSTHelper(tnode->right);
    }

    void printPostorder(node *tnode)
    {
        if (tnode == NULL)
            return;
        printPostorder(tnode->left);
        printPostorder(tnode->right);
        cout << tnode->data << " ";
    }

    void printInorder(node *tnode)
    {
        if (tnode == NULL)
            return;
        printInorder(tnode->left);
        cout << tnode->data << " ";
        printInorder(tnode->right);
    }

    void printPreorder(node *tnode)
    {
        if (tnode == NULL)
            return;
        cout << tnode->data << " ";
        printPreorder(tnode->left);
        printPreorder(tnode->right);
    }

public:
    bool search(int data)
    {
        return searchHelper(root, data);
    }
    void insert(int data)
    {
        root = insertHelper(root, data);
    }
    void deleteNode(int data)
    {
        //root = delete_data(data, root);
        root = deleteHelper(root, data);
    }
    void printBST()
    {
        printBSTHelper(root);
    }
    void inOrder()
    {
        printInorder(root);
    }
    void postOrder()
    {
        printPostorder(root);
    }
    void preOrder()
    {
        printPreorder(root);
    }
};


int main()
{
    bst b;

    // creat tree
    b.insert(4);
    b.insert(5);
    b.insert(3);
    b.insert(2);
    b.insert(1);
    cout << "BST:" << endl;
    b.printBST();
    b.deleteNode(3);
    cout << "BST after deletion of 3:" << endl;
    b.printBST();
    cout << "check for 4 in BST: ";
    cout << b.search(4) << endl;
    cout << "inorder: ";
    b.inOrder();
    cout << endl;
    cout << "postorder: ";
    b.postOrder();
    cout << endl;
    cout << "preorder: ";
    b.preOrder();
    cout << endl;
}
