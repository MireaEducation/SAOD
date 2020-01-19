#include <iostream>
#include <Windows.h>
#include "BTree.h"

using namespace std;

template<typename T>
int BTree<T>::FindParent(NodeBTree<T>* tree, int i)
{
	return tree->childrens[i];
}

template<typename T>
int BTree<T>::rightBrather(BTree* tree, int i)
{
	int parent_index = FindParent(tree.root, i);
	if (tree->root.childrens[i + 1] == parent_index) return i + 1;
	else - 1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	return 0;
}