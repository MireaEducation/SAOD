#pragma once
#include "BinaryTreeNode.h"

class RedBlackTree
{
private:
	Node* root;
public:
	/// <summary>
	/// Инициализирует пустой узел дерева
	/// </summary>
	RedBlackTree(char data)
	{
		this->root = new BinaryTreeNode();
		root->data;
	}
	~RedBlackTree();
};

