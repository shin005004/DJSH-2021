#include <cstdio>

class BinaryNode
{
protected:
    int data;
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
        : data(val), left(l), right(r) { }
    void setData(int val)  { data = val; }
    void setLeft(BinaryNode *l) { left = l; }
    void setRight(BinaryNode *r) { right = r; }
    int getData() { return data; }
    
    BinaryNode* getLeft() { return left; }
    BinaryNode* getRight() { return right; }
    bool isLeaf() { return left == NULL && right == NULL; }
};

class BinaryTree
{
    BinaryNode* root;
public:
    BinaryTree(): root(NULL) { }
    void setRoot(BinaryNode* node) { root = node; }
    BinaryNode* getRoot() { return root; }
    bool isEmpty() { return root = NULL; }

    void inorder()
    {
        printf("inorder: ");
        inorder(root);
    }
    void inorder(BinaryNode* node)
    {
        if(node != NULL)
        {
            inorder(node->getLeft());
            printf(" [%c] ", node->getData());
            inorder(node->getRight());
        }
    }
    void preorder()
    {
        printf("preorder: ");
        preorder(root);
    }
    void preorder(BinaryNode* node)
    {
        if(node != NULL)
        {
            printf(" [%c] ", node->getData());
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }
    void postorder()
    {
        printf("postorder: ");
        postorder(root);
    }
    void postorder(BinaryNode* node)
    {
        if(node != NULL)
        {
            postorder(node->getLeft());
            postorder(node->getRight());
            printf(" [%c] ", node->getData());
        }
    }
};