template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data){
        this->data = data;
        left = right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

int numNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    return 1 + numNodes(root->left) + numNodes(root->right);
}

int numLeafNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return  numLeafNodes(root->left) + numLeafNodes(root->right);
}
BinaryTreeNode<int>* copy(BinaryTreeNode<int>*root){
    if(!root){
        return NULL;
    }
    BinaryTreeNode<int>*newroot=new BinaryTreeNode<int>(root->data);
    newroot->left=copy(root->left);
    newroot->right=copy(root->right);
    return newroot;

}