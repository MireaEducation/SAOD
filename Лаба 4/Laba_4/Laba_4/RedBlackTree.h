#pragma once
#include "BinaryTreeNode.h"

class RedBlackTree: BinaryTreeNode
{
private:
	/// <summary>
	/// Вращение дерева влево
	/// </summary>
	/// <param name="node">Узел дерева, ветви которого нужно вращать</param>
	/// <returns></returns>
	BinaryTreeNode* RotateToLeft(BinaryTreeNode* node);

	/// <summary>
	/// Балансировка дерева на основе вставляемого узла
	/// </summary>
	/// <param name="root">Новый узел дерева</param>
	void BalanceInsert(BinaryTreeNode** root);

	/// <summary>
	/// Добавляет новый узел с заданным значением
	/// </summary>
	/// <param name="value">Значение узла</param>
	/// <returns></returns>
	BinaryTreeNode* InsertNode(char value);
public:

	/// <summary>
	/// Инициализирует пустой узел дерева
	/// </summary>
	RedBlackTree();
	~RedBlackTree();

	/// <summary>
	/// Рекурсивно вставка узла.
	/// Возвращает true если изменений не было или если балансировка в вершине не нужна
	/// </summary>
	/// <param name="value">Значение добавляемого узла</param>
	/// <param name="root">Указатель на головной узел дерева/поддерева</param>
	/// <returns></returns>
	bool Insert(char value, BinaryTreeNode** root);
};

