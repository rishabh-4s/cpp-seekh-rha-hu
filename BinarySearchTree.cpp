#include "BinaryTree.cpp"
//#include "linkedList.cpp"

BinaryTreeNode<int> *constructBST(int arr[], int n)
{
    int mid = 0;
    /*
    if (n != 0){
        if (n % 2 == 0)
            mid = n/2 - 1;
        else
            mid = (n - 1)/ 2;
    }
    else
        return NULL;
        */
    if (n == 0)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    if (n % 2 != 0)
    {
        mid = (n - 1) / 2;

        root = new BinaryTreeNode<int>(arr[mid]);
        root->left = constructBST(arr, mid);
        root->right = constructBST(arr + mid + 1, mid);
    }
    else
    {
        mid = n / 2 - 1;

        root = new BinaryTreeNode<int>(arr[mid]);
        root->left = constructBST(arr, mid);
        root->right = constructBST(arr + mid + 1, mid + 1);
    }
    return root;
}

// inserting node behind root
void addNodeToFront(int data, node *head, node *tail)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// inserting node ahead of root
void addNodeToBecc(int data, node *head, node *tail)
{
    node *newNode = new node(data);
    tail->next = newNode;
    tail = newNode;
}
/*
node *BSTtoLL(BinaryTreeNode<int> *root)
{
    node *head = new node(root->data);
    node *tail = new node(root->data);
    if (root->left)
    {
        addNodeToFront(root->left->data, head, tail);
        BSTtoLL(root->left);
    }
    if (root->right)
    {
        addNodeToBecc(root->right->data, head, tail);
        BSTtoLL(root->right);
    }
    return head;
}
*/
/*
// linked list ki khichadi hai, kabhi time lga toh dekh lena, boht gnda bhora hai
node* pathInBSTHelper(BinaryTreeNode<int> *root, int k, node *head, node *tail)
{
    //node *head = NULL;
    //node *tail = NULL;
    if (root->data == k)
    {
        addNodeToFront(root->data, head, tail);
    }
    else if (root->data > k)
    {
        addNodeToFront(root->data, head, tail);
        pathInBSTHelper(root->left, k, head, tail);
    }
    else
    {
        addNodeToFront(root->data, head, tail);
        pathInBSTHelper(root->right, k, head, tail);
    }
    return head;
}

void pathInBST(BinaryTreeNode<int> *root, int k)
{
    node *head = NULL;
    node *tail = NULL;

    head = pathInBSTHelper(root, k, head, tail);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

}
*/


void pathInBSTHelper(BinaryTreeNode<int> *root, vector<int> &bruh, int k)
{
    int h = height(root);

    // check for root and if not root then left ya right check karenge accordingly
    if (root->data == k)
    {
        bruh.push_back(root->data);
        //cout << root->data << " ";
        return;
    }
    else if (root->data > k)
    {
        bruh.push_back(root->data);
        // check if the key is not present in the tree
        // agar vector full ho rha hai toh last element should be the key for it to be present in the tree
        if (bruh.size() == h)
        {
            bruh.clear();
            return;
        }

        pathInBSTHelper(root->left, bruh, k);
    }
    else
    {
        bruh.push_back(root->data);
        // same check for key not present in the tree
        if (bruh.size() == h)
        {
            bruh.clear();
            return;
        }
        pathInBSTHelper(root->right, bruh, k);
    }
}

void pathInBST(BinaryTreeNode<int> *root, int k)
{
    vector<int> bruh;

    // helper function call
    pathInBSTHelper(root, bruh, k);

    // if the key is not present in the tree
    if (bruh.size() == 0)
        cout << "bekaar key" << endl;

    for (int i = 0; i < bruh.size(); i++)
    {
        cout << bruh[i] << " ";
    }
}




int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    BinaryTreeNode<int> *root = constructBST(arr, 7);
    levelOrderPrint(root);
    //vector<int> bruh = pathInBST(root, 3);
    //pathPrinter(bruh);
    pathInBST(root, 8);
    return 0;
}
