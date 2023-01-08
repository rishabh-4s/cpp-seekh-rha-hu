#include "BinaryTree.cpp"
#include <algorithm>
#include <climits>

// que 0
BinaryTreeNode<int> *insertDuplicate(BinaryTreeNode<int> *root)
{   
    // base case
    if (root == NULL)
        return NULL;
    // store root->left and replace it with the new duplicate node
    // and then call recursion on the left of new node and on the
    // right of the root
    BinaryTreeNode<int> *temp = root->left;
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    root->left = newNode;
    newNode->left = insertDuplicate(temp);
    root->right = insertDuplicate(root->right);
    return root;
}

// que 1
// function to store node data in vecotr
vector<int> StoreInVector(BinaryTreeNode<int> *root, vector<int> arr)
{
    
    if (!root)
        return arr;
    arr.push_back(root->data);
    arr = StoreInVector(root->left, arr);
    arr = StoreInVector(root->right, arr);
    return arr;

}

// function to find pair sums in the vector
void pairSumHelper(vector<int> arr, int sum)
{
    // sorting the vector
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = arr.size() - 1;

    while(end > start)
    {
        int csum =  arr[start] + arr[end];
        if (csum == sum)
        {
            cout << arr[start] << " " << arr[end] << endl;
            start++;
        }
        else if (csum < sum)    
            start++;
        else
            end--; 
    }  
}
// final function
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> arr;
    arr = StoreInVector(root, arr);
    pairSumHelper(arr, sum);
}

// que 2
// lowest common ancestor
BinaryTreeNode<int> *findLCA_BT(BinaryTreeNode<int> *root, int n1, int n2)
{   
    // base case
    if (root == NULL)
        return NULL;
    // if one of the keys is equal to the root then the root is the LCA
    if (root->data == n1 || root->data == n2)
        return root;
    
    BinaryTreeNode<int> *leftLCA = findLCA_BT(root->left, n1, n2);
    BinaryTreeNode<int> *rightLCA = findLCA_BT(root->right, n1, n2);

    // if none of them is null
    if (leftLCA && rightLCA)
        return root;
    // if one of them is null
    else if (leftLCA == NULL)
    {
        return rightLCA;
    }
    else
        return leftLCA;
    

}

// que 3
// iterative approach taaki call stack ki space use na ho (gfg)
BinaryTreeNode<int> *findLCA_BST(BinaryTreeNode<int>*root, int n1, int n2)
{
    while (root)
    {
        // agar dono bde toh go right
        if (n1 > root->data && n2 > root->data)
            root = root->right;
        // agar dono chhote toh go
        else if (n1 < root->data && n2 < root->data)
            root = root->left;
        // agar dono mein se ek bhi root ke equal aa gya toh vahi apna lca hai
        else
            break;
        
    }
    return root;
}

// que 4
int isBSTUtil(BinaryTreeNode<int>* node, int min, int max); 
/* Returns true if the given 
tree is a binary search tree 
(efficient version). */
int isBST(BinaryTreeNode<int>* node) 
{ 
    return(isBSTUtil(node, INT_MIN, INT_MAX)); 
} 
/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(BinaryTreeNode<int>* node, int min, int max) 
{ 
    /* an empty tree is BST */
    if (node==NULL) 
        return 1; 
            
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max) 
        return 0; 
    
    /* otherwise check the subtrees recursively, 
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values 
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values 
}  
// helper function for finding the largest bst ih binary tree
BinaryTreeNode<int> *largestBSTinBT(BinaryTreeNode<int> *root, int *h)
{
    if (root == NULL)
        return NULL;
    if (isBST(root) && height(root) > *h)
        *h = height(root);
    root->left = largestBSTinBT(root->left, h);
    root->right = largestBSTinBT(root->right, h);
    return root;
}
int largetBST(BinaryTreeNode<int> *root)  
{
    int *h = new int(0);
    root = largestBSTinBT(root, h);
    return *h;
}


// que 5
// helper function to replace node data with sum of all the nodes greater than it
void replaceWithSumHelper(BinaryTreeNode<int> *root, int *sum )
{
    if (!root)
        return;
    
    // right mein deepest par chle jayenge aur vaha se add krna shuru kr denge
    replaceWithSumHelper(root->right, sum);

    // modifying the sum and the root
    *sum += root->data;
    root->data = *sum;

    // recursion for left subtree
    replaceWithSumHelper(root->left, sum);
}

void replaceWithSum(BinaryTreeNode<int> *root)
{
    int *sum = new int(0);
    replaceWithSumHelper(root, sum);
}

// que 6
void printPaths(BinaryTreeNode<int> *root, int sum)
{
    vector<int> current_path;
     
}



int main()
{
    BinaryTreeNode<int> *root = levelWiseInput();
    levelOrderPrint(root);
    //root = insertDuplicate(root);
    //levelOrderPrint(root);
    //pariSum(root, 3);
    //pairSum(root, 15);
    //cout << findLCA_BT(root, 2, 3)->data;
    //cout << largetBST(root);
    replaceWithSum(root);
    levelOrderPrint(root);
}