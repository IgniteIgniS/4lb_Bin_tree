#include <iostream>
#include "Binarytree.h"
#include <iostream>
int main()
{
	BinaryTree tree;
	tree.insert(2); tree.insert(1); tree.insert(6); tree.insert(4); tree.insert(7); tree.insert(13); tree.insert(14); tree.insert(10); tree.insert(8);
	std::cout << "Binary Tree:";
	std::cout << "\n";
	std::cout << "Binary Tree 2d:" << std::endl;
	tree.print2D();
	//std::cout << "Removed:"; tree.remove(6);
	std::cout << "Binary Tree height:"; tree.GetHeight(); std::cout << "\n";
	std::cout << "Binary Tree BFS:"; tree.BFS();
	//std::cout << "Min element of tree:";
	//tree.GetMinElem();
	std::cout << "\n"; std::cout << "Element found?:";
	tree.findElement(1);

}

