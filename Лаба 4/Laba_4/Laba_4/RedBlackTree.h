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

	/// <summary>
	/// Добавляет в дерево элемент с указанным значением
	/// </summary>
	/// <param name="data">Значение добавляемого узла</param>
	/// <returns></returns>
	Node* InsertNode(char data);
};

