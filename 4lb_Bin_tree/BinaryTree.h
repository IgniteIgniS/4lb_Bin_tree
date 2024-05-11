#pragma once
struct Node
{
    int data;
    Node* left;
    Node* right;

};

class BinaryTree
{
private:

    Node* root;
    Node* createNode(int data);
    Node* insertNode(Node* root, int data);
    void printTree(Node* root);
    void print2D(Node* root, int space);
    void deleteTree(Node* node);
    Node* minValueNode(Node* node);
    Node* maxValueNode(Node* node);
    int findHeight(Node* node);
    Node* deleteNode(Node* root, int key);
    bool findElement(Node* node, int value);

public:
    BinaryTree();
    ~BinaryTree();

    void insert(int data);
    void remove(int key);
    void sortedPrint();
    void print2D();
    void GetMinElem();
    void GetMaxElem();
    void GetHeight();
    bool findElement(int value);

    void BFS();
};

