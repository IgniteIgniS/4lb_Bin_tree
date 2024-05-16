#include "Binarytree.h"
#include <iostream>
#include <queue>
#include <vector>


Node* BinaryTree::createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* BinaryTree::insertNode(Node* root, int data)
{
    if (root == nullptr)
    {
        root = createNode(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void BinaryTree::printTree(Node* root)
{
    if (root == nullptr) return;

    printTree(root->left);
    std::cout << root->data << " ";
    printTree(root->right);
}

void BinaryTree::print2D(Node* root, int space){
    int COUNT = 5;
    if (root == nullptr) return;
    space += COUNT;
    print2D(root->right, space);
    std::cout << std::endl;
    for (int i = 0; i < space ; i++) 
    {
        std::cout << "  ";
    }
    std::cout << root->data << "\n";
    print2D(root->left, space);
}

void BinaryTree::deleteTree(Node* node)
{
    if (node == nullptr) return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

Node* BinaryTree::minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* BinaryTree::maxValueNode(Node* node)
{
    Node* current = node;
    while (current && current->right != nullptr)
        current = current->right;
    return current;
}

int BinaryTree::findHeight(Node* node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return 1 + std::max(findHeight(node->left), findHeight(node->right));
    }
}

Node* BinaryTree::deleteNode(Node* root, int key)
{
    if (root == nullptr) return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);

    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);

    }
    else
    {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void BinaryTree::findElement(Node* node, int value)
{
    if (node == nullptr)
    {
        std::cout << "n";
    }
    else if (node->data == value)
    {
        std::cout << "y";
    }
    else if (value < node->data)
    {
        return findElement(node->left, value);
    }
    else
    {
        return findElement(node->right, value);
    }
}

Node* BinaryTree::copyTree(Node* node)
{
    if (node == nullptr) return nullptr;

    Node* newNode = createNode(node->data);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}





void BinaryTree::DFS(Node* node, std::vector<int>& result) {
    if (node == nullptr) return;
    result.push_back(node->data);
    DFS(node->left, result);
    DFS(node->right, result);
}
void BinaryTree::BFS(std::vector<Node*>& nodes, std::vector<int>& result) {
    if (nodes.empty()) return;

    std::vector<Node*> nextLevel;
    for (Node* node : nodes) {
        result.push_back(node->data);
        if (node->left != nullptr)
            nextLevel.push_back(node->left);
        if (node->right != nullptr)
            nextLevel.push_back(node->right);
    }
    BFS(nextLevel, result);
}



//public

BinaryTree::BinaryTree()
{
    root = nullptr;
}
BinaryTree::~BinaryTree()
{
    deleteTree(root);
}

BinaryTree::BinaryTree(const BinaryTree& other)
{
    root = copyTree(other.root);
}
BinaryTree& BinaryTree::operator=(const BinaryTree& other)
{
    if (this == &other) return *this; // self-assignment check

    deleteTree(root); // delete current tree
    root = copyTree(other.root); // copy new tree
    return *this;
}

void BinaryTree::insert(int data)
{
    root = insertNode(root, data);
}
void BinaryTree::remove(int key)
{
    root = deleteNode(root, key);
}
void BinaryTree::sortedPrint()
{
    printTree(root);
}
void BinaryTree::print2D()
{
    print2D(root, 5);
}
void BinaryTree::GetMinElem()
{
    Node* minNode = minValueNode(root);
    if (minNode != nullptr)
    {
        std::cout << "Min element: " << minNode->data << std::endl;
    }
    else
    {
        std::cout << "Tree is empty!" << std::endl;
    }
}
void BinaryTree::GetMaxElem()
{
    Node* maxNode = maxValueNode(root);
    if (maxNode != nullptr)
    {
        std::cout << "Max element: " << maxNode->data << std::endl;
    }
    else
    {
        std::cout << "Tree is empty!" << std::endl;
    }
}
void BinaryTree::GetHeight()
{
    std::cout << findHeight(root);
}
void BinaryTree::findElement(int value)
{
    return findElement(root, value);
}
//void BinaryTree::BFS()
//{
//    if (root == nullptr)
//    {
//        return;
//    }
//
//    std::queue<Node*> nodes;
//    nodes.push(root);
//
//    while (!nodes.empty())
//    {
//        Node* currNode = nodes.front();
//        nodes.pop();
//
//        std::cout << currNode->data << " ";
//
//        if (currNode->left != nullptr)
//        {
//            nodes.push(currNode->left);
//        }
//
//        if (currNode->right != nullptr)
//        {
//            nodes.push(currNode->right);
//        }
//    }
//}

std::vector<int> BinaryTree::DFS() 
{
    std::vector<int> result;
    DFS(root, result);
    return result;
}
std::vector<int> BinaryTree::BFS() 
{
    std::vector<Node*> currentLevel;
    std::vector<int> result;
    currentLevel.push_back(root);
    BFS(currentLevel, result);
    return result;
}