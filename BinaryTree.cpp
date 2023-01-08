#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
#include "node.h"
using namespace std;

// normal print with L and R
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    if (root->left)
        cout << "L" << root->left->data;
    if (root->right)
        cout << "R" << root->right->data;

    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

// level wise print with L and
void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        int leftData, rightData;
        if (front->left)
        {
            cout << "L" << front->left->data << ",";
            pendingNodes.push(front->left);
        }

        else
            cout << "L"
                 << "-1"
                 << ",";

        if (front->right)
        {
            if (front->right->data != -1)
            {
                cout << "R" << front->right->data;
                pendingNodes.push(front->right);
            }
        }
        else
            cout << "R"
                 << "-1";
        cout << endl;
    }
}

// total nodes in the binary tree 
int numNodes(BinaryTreeNode<int> *root)
{
    int count = 0;
    if (root == NULL)
        return 0;
    /*
    count += numNodes(root->left);
    count += numNodes(root->right);
    return count + 1;
    */
    return 1 + numNodes(root->left) + numNodes(root->left);
}

// input function (dont use this)
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    root->left = takeInput();
    root->right = takeInput();
}

// level wise input as the name suggests (use this)
BinaryTreeNode<int> *levelWiseInput()
{
    int rootData;
    cin >> rootData;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

// searchihng a element in the binary tree
bool searchElement(BinaryTreeNode<int> *root, int x)
{

    // base case
    if (root == NULL)
        return 0;
    if (root->data == x)
        return 1;

    // recursive calls
    if (searchElement(root->left, x))
        return 1;
    if (searchElement(root->right, x))
        return 1;
}

// height of binary tree (worse method)
int heightOfBinaryTree(BinaryTreeNode<int> *root)
{

    if (root == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = heightOfBinaryTree(root->left);
        int rDepth = heightOfBinaryTree(root->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

// mirroring/reversing a binary tree
BinaryTreeNode<int> *mirrorBInaryTreee(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *tempRight = root->right;
    BinaryTreeNode<int> *tempLeft = root->left;

    if (root->left)
        root->right = mirrorBInaryTreee(tempLeft);
    if (root->right)
        root->left = mirrorBInaryTreee(tempRight);

    return root;
}

//maximum element of the binary tree
int findMax(BinaryTreeNode<int> *root)
{
    int maxi = root->data;

    if (root->left)
    {
        int temp = findMax(root->left);
        maxi = max(temp, maxi);
    }
    if (root->right)
    {
        int temp = findMax(root->right);
        maxi = max(temp, maxi);
    }
    return maxi;
}

// height function better one
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// diameter of binary tree unoptimized
/*
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, option2, option3);
}
*/

// diameter function optimized
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

// assignment
// que 0
// sum of all the nodes
int sumOfNodes(BinaryTreeNode<int> *root)
{

    if (root == NULL)
        return 0;
    int sum = 0;
    sum += root->data;
    sum += sumOfNodes(root->left);
    sum += sumOfNodes(root->right);
    return sum;
}

// que 1
// checking if the tree is balanced or not
// iski complexity is O(n * height), so niche O(n) waala function bhi hai
bool balanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 1;
    if (1 < abs(height(root->left) - height(root->right)))
        return 0;

    bool a = balanced(root->left);
    bool b = balanced(root->right);

    return a && b;
}

pair<int, int> optimizedBalancedHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = optimizedBalancedHelper(root->left);
    pair<int, int> rightAns = optimizedBalancedHelper(root->right);

    int lb = leftAns.second;
    int lh = leftAns.first;
    int rb = rightAns.second;
    int rh = rightAns.first;
    int height = 1 + max(lh, rh);
    int bal = lb && rb;
    pair<int, int> p;
    p.first = height;
    p.second = bal;
    return p;
}

bool optimizedBalanced(BinaryTreeNode<int> *root)
{
    return optimizedBalancedHelper(root).second;
}

// que 2
// printing level wise without l and r
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

// que 3
// removing all the nodes without children which are also called leaves
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    // agar child ka aage koi child nhi hai then its a leaf and we'll remove it
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    //levelOrderPrint(root);
    return root;
}

// que 4
//converting each level in a linked list
// incomplete (not printing anything)
void nodeAdder(int data, node *head, node *tail)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

node *levelWiseLL(BinaryTreeNode<int> *root)
{
    int h = height(root);
    // array for heads
    //node *arr[h];
    node **arr = new node *[h];

    queue<BinaryTreeNode<int> *> pendingNodes;
    //cout << root->data << endl;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    node *head = NULL; //new node(pendingNodes.front()->data);
    node *tail = NULL; //new node(pendingNodes.front()->data);
    while (!pendingNodes.empty())
    {
        int i = 0;
        // last null hoga toh yeh karenge taaki extra line add na ho
        if (pendingNodes.size() == 1 && pendingNodes.front() == NULL)
        {
            //arr[i] = head;
            break;
        }

        // use null as a check to end a level
        // jab queue mein null ayega then we'll end our linked list, add the head to the array and start a new one
        if (pendingNodes.front() == NULL)
        {
            pendingNodes.push(NULL);
            //cout << endl;
            pendingNodes.pop();
            arr[i] = head;
            i++;
            head = tail = NULL; //new node(pendingNodes.front()->data);
        }

        BinaryTreeNode<int> *front = pendingNodes.front();
        // inserting node to the current linkedlist
        nodeAdder(front->data, head, tail);
        pendingNodes.pop();

        if (front->left)
        {
            pendingNodes.push(front->left);
            //cout << front->left->data << " ";
        }
        if (front->right)
        {
            pendingNodes.push(front->right);
            //cout << front->right->data << " ";
        }
    }
    return *arr;
}

vector<node *> levelWiseLLVeector(BinaryTreeNode<int> *root)
{
    //int h = height(root);
    // array for heads
    //node *arr[h];
    //node **arr = new node *[h];
    vector<node *> res;
    queue<BinaryTreeNode<int> *> pendingNodes;
    //cout << root->data << endl;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    node *head = NULL; //new node(pendingNodes.front()->data);
    node *tail = NULL; //new node(pendingNodes.front()->data);
    while (!pendingNodes.empty())
    {
        //int i = 0;
        // last null hoga toh yeh karenge taaki extra line add na ho
        if (pendingNodes.size() == 1 && pendingNodes.front() == NULL)
        {
            //res.push_back(head);
            break;
        }

        // use null as a check to end a level
        // jab queue mein null ayega then we'll end our linked list, add the head to the array and start a new one
        if (pendingNodes.front() == NULL)
        {
            pendingNodes.push(NULL);
            //cout << endl;
            pendingNodes.pop();
            //arr[i] = head;
            //i++;
            res.push_back(head);
            head = tail = NULL; //new node(pendingNodes.front()->data);
        }

        BinaryTreeNode<int> *front = pendingNodes.front();
        // inserting node to the current linkedlist
        nodeAdder(front->data, head, tail);
        pendingNodes.pop();

        if (front->left)
        {
            pendingNodes.push(front->left);
            //cout << front->left->data << " ";
        }
        if (front->right)
        {
            pendingNodes.push(front->right);
            //cout << front->right->data << " ";
        }
    }
    return res;
}

void printTreeFromLL(node *arr[], int h)
{

    for (int i = 0; i < h; i++)
    {
        node *temp = arr[i];
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// que 6
void nodesWOSiblings(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    // agar dono hai
    if (root->left && root->right)
    {
        nodesWOSiblings(root->left);
        nodesWOSiblings(root->right);
    }
    // agar sirf left hai
    if (root->left && !root->right)
    {
        cout << root->left->data << " ";
        nodesWOSiblings(root->left);
    }
    // agar sirf right hai
    else if (!root->left && root->right)
    {
        cout << root->right->data << " ";
        nodesWOSiblings(root->right);
    }
}

vector<node *> make_ll_oflevels(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        vector<node *> v;
        v.push_back(0);
        return v;
    }

    vector<node *> v;
    queue<BinaryTreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);
    node *head = NULL;
    node *tail = NULL;
    while (pendingnodes.size() != 0)
    {

        BinaryTreeNode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        if (front == NULL)
        {
            if (pendingnodes.size() == 0)
            {
                break;
            }

            v.push_back(head);
            pendingnodes.push(NULL);
            head = NULL;
            tail = NULL;
        }
        else
        {
            node *newnode = new node(front->data);
            if (head == NULL)
            {

                head = newnode;
                tail = newnode;
            }
            else
            {

                tail->next = newnode;
                tail = tail->next;
            }
            if (front->left != NULL)
            {
                pendingnodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingnodes.push(front->right);
            }
        }
    }
    return v;
}

//int main()
//{
    /*
    BindaryTreeNode<int> *root = new BindaryTreeNode<int>(1);
    BindaryTreeNode<int> *node1 = new BindaryTreeNode<int>(2);
    BindaryTreeNode<int> *node2 = new BindaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    */
    //BinaryTreeNode<int> *root = levelWiseInput();
    //printLevelWise(root);
    //root = mirrorBInaryTreee(root);
    //printLevelWise(root);
    //root = removeLeafNodes(root);
    //levelOrderPrint(root);
    //node *arr = levelWiseLL(root);
    //int h = height(root);
    //cout << h;
    //printTreeFromLL(&arr, h);
    //nodesWOSiblings(root);
//}


int main()
{
    BinaryTreeNode<int> *root = levelWiseInput();

    bool p = optimizedBalanced(root);
    cout << p;
}

// gfg questions
BinaryTreeNode<int>* mirror(BinaryTreeNode<int>* root)
{
        if (!root) return root;
        BinaryTreeNode<int>* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
}