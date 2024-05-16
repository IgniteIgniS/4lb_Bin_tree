#include <iostream>
#include "Binarytree.h"
#include <iostream>
int main()
{
	BinaryTree tree;
	tree.insert(2); tree.insert(1); tree.insert(6); tree.insert(4); tree.insert(7); tree.insert(13); tree.insert(14); tree.insert(10); tree.insert(8);
	std::cout << "Print tree:"; tree.print2D();
    // Обход в глубину
    std::vector<int> dfsResult = tree.DFS();
    std::cout << "DFS: ";
    for (int value : dfsResult) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Обход в ширину
    std::vector<int> bfsResult = tree.BFS();
    std::cout << "BFS: ";
    for (int value : bfsResult) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

