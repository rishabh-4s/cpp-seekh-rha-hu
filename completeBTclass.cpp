#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

class completeBT
{
private:
    BinaryTreeNode<int> *root;
    queue<BinaryTreeNode<int> *> q;

public:
    completeBT()
    {
        root = NULL;
    }

private:
    BinaryTreeNode<int> *insertHelper(BinaryTreeNode<int> *node, int data)
    {
        BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
        if (node == NULL)
        {
            q.push(newNode);
            return newNode;
        }
        else
        {
            for (int i = 0; i < q.size(); i++)
            {

                BinaryTreeNode<int> *front = q.front();

                if (!front->left)
                {
                    front->left = newNode;
                    q.push(newNode);
                    break;
                }
                else if (!front->right)
                {
                    front->right = newNode;
                    q.push(newNode);
                    break;
                }
                else
                    q.pop();
            }
        }
        return node;
    }
    /*
    BinaryTreeNode<int> *DeleteHelper(BinaryTreeNode<int> *node, int data)
    {
        if (node->data = data)
        {
            if (!node->right && !node->left)
            {
                delete node;
                return NULL;
            }
            else
            {
                BinaryTreeNode<int> *temp = root;
                while (!temp->right)
                {
                    temp = temp->right;
                }
                node->data = temp->data;
                delete temp;
                
            }
        }
        else
        {
            node->left = DeleteHelper(node->left, data);
            node->right = DeleteHelper(node->right, data);
        }
    return node;
        
    }
    
BinaryTreeNode<int>* deleteHelper(BinaryTreeNode<int>*root,int data){
    if(!root){
        return NULL;
    }
    if(root->data==data){
        queue<BinaryTreeNode<int>*> pending_nodes;
        pending_nodes.push(root);
        BinaryTreeNode<int>*front=pending_nodes.front();
        while(pending_nodes.size()){
            front=pending_nodes.front();
            pending_nodes.pop();
            if(front->left){
                pending_nodes.push(front->left);
            }
            if(front->right){
                pending_nodes.push(front->right);
            }
        }
        root->data=front->data;
        delete front;
        front=NULL;
        return root;
    }
    root->left=deleteHelper(root->left,data);
    root->right=deleteHelper(root->right,data);
    return root;
}
*/
    BinaryTreeNode<int> *delete_helper(BinaryTreeNode<int> *root, int data)
    {
        if (!root)
        {
            return NULL;
        }
        if (root->data == data)
        {
            if (!(root->left) && !(root->right))
            {
                delete root;
                return NULL;
            }
            if (!root->left)
            {
                BinaryTreeNode<int> *right = root->right;
                root->right = NULL;
                delete root;
                return right;
            }
            if (!root->right)
            {
                BinaryTreeNode<int> *left = root->left;
                root->left = NULL;
                delete root;
                return left;
            }
            else
            {
                queue<BinaryTreeNode<int> *> pending_nodes;
                pending_nodes.push(root);
                BinaryTreeNode<int> *front = pending_nodes.front();
                while (pending_nodes.size())
                {
                    front = pending_nodes.front();
                    pending_nodes.pop();
                    if (front->left)
                    {
                        pending_nodes.push(front->left);
                    }
                    if (front->right)
                    {
                        pending_nodes.push(front->right);
                    }
                }
                root->data = front->data;
                root->left = delete_helper(root->left, root->data);
                root->right = delete_helper(root->right, root->data);
                return root;
            }
        }
        root->left = delete_helper(root->left, data);
        root->right = delete_helper(root->right, data);
        return root;
    }

    void printPostorder(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return;
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }

    void printInorder(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    void printPreorder(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    void levelOrderPrint(BinaryTreeNode<int> *root)
    {
        queue<BinaryTreeNode<int> *> pendingNodes;
        cout << root->data << endl;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        while (!pendingNodes.empty())
        {

            // last null hoga toh yeh karenge taaki extra line add na ho
            if (pendingNodes.size() == 1 && pendingNodes.front() == NULL)
                break;

            // use null as a check to end a level
            if (pendingNodes.front() == NULL)
            {
                pendingNodes.push(NULL);
                cout << endl;
                pendingNodes.pop();
            }

            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();

            if (front->left)
            {
                pendingNodes.push(front->left);
                cout << front->left->data << " ";
            }
            if (front->right)
            {
                pendingNodes.push(front->right);
                cout << front->right->data << " ";
            }
        }
    }

public:
    void insert(int data)
    {
        root = insertHelper(root, data);
    }
    void Delete(int data)
    {
        root = delete_helper(root, data);
    }
    void print()
    {
        levelOrderPrint(root);
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
    completeBT b;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.insert(5);
    cout << "CBT:" << endl;
    b.print();
    //cout << endl;
    b.Delete(1);
    cout << "CBT after deletion of 1(the root):" << endl;
    b.print();
    //cout << endl;
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