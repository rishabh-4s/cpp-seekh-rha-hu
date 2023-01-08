#include <iostream>
using namespace std;
class TreeNode
{
public:
    int height;
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVL_Tree
{
    TreeNode *root;

public:
    AVL_Tree()
    {
        root = NULL;
    }

private:
    int height(TreeNode *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }
    int getBalance(TreeNode *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left),
                        height(y->right)) +
                    1;
        x->height = max(height(x->left),
                        height(x->right)) +
                    1;
        return x;
    }
    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left),
                        height(x->right)) + 1;
        y->height = max(height(y->left),
                        height(y->right)) + 1;
        return y;
    }
    TreeNode *insert(TreeNode *root, int data)
    {
        if (!root)
        {
            TreeNode *root = new TreeNode(data);
            return root;
        }
        if (root->data > data)
        {
            root->left = insert(root->left, data);
        }
        if (root->data < data)
        {
            root->right = insert(root->right, data);
        }
        root->height = max(height(root->left), height(root->right)) + 1;
        int balance = getBalance(root);
        if (balance > 1 && root->left->data > data)
        { //left left case
            return rightRotate(root);
        }
        if (balance > 1 && root->left->data <= data)
        { //left right case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && root->right->data > data)
        { //right left
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        if (balance < -1 && root->right->data <= data)
        { //right right
            return leftRotate(root);
        }
        return root;
    }
    void printTree(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }

public:
    void insert(int data)
    {
        root = insert(root, data);
    }
    void printTree()
    {
        printTree(root);
    }
};

int main()
{
    AVL_Tree Tree;
    Tree.insert(10);
    Tree.insert(20);
    Tree.insert(30);
    Tree.insert(40);
    Tree.insert(50);
    Tree.insert(25);

    Tree.printTree();

    return 0;
}
