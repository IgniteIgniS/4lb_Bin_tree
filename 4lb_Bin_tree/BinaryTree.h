#pragma once
#include <iostream>
#include <vector>

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
    void findElement(Node* node, int value);

    Node* copyTree(Node* node);



    void DFS(Node* node, std::vector<int>& result);
    void BFS(std::vector<Node*>& nodes, std::vector<int>& result);


public:
    BinaryTree();
    ~BinaryTree();

    BinaryTree& operator=(const BinaryTree& other);
    BinaryTree(const BinaryTree& other);

    void insert(int data);
    void remove(int key);
    void sortedPrint();
    void print2D();
    void GetMinElem();
    void GetMaxElem();
    void GetHeight();
    void findElement(int value);

    std::vector<int> DFS();
    std::vector<int> BFS();


};

