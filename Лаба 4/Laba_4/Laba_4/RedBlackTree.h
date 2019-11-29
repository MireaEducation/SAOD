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
	RedBlackTree() {}
	~RedBlackTree();

	/// <summary>
	/// Делает балансирвоку вставленного узла Х
	/// </summary>
	/// <param name="x">Вставленный узел в дерево</param>
	void BalanceInsert(Node* x);


	/// <summary>
	/// Добавляет в дерево элемент с указанным значением
	/// </summary>
	/// <param name="data">Значение добавляемого узла</param>
	/// <returns></returns>
	Node* InsertNode(char data);

	/// <summary>
	/// Делае
	/// </summary>
	/// <param name="x"></param>
	void RotateRight(Node* x);

	/// <summary>
	/// Возращает указатель на родительский элемет дерева
	/// </summary>
	/// <returns></returns>
	Node* GetRoot();
};

