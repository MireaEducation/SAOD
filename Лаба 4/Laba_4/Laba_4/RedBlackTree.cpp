#include "RedBlackTree.h"

RedBlackTree::~RedBlackTree()
{
}

Node* RedBlackTree::InsertNode(char data)
{
	Node* current, * parent, * x;

	current = root;
	parent = 0;

	// Перебираем узлы дерева, вплоть до листьев
	// или пока не встретим элемент с теми эе данными
	while (current)
	{
		if (data == current->data)
			return current;
		parent = current;
		current = data > current->data ? current->right : current->left;
	}

	// Для нового узла создаем объект вершины
	x = new Node();

	// Если дерево имеет хотяб 1 вершину
	if (parent) {
		// Определяем с какой стороны вставить новый узел
		if (data == parent->data)
			parent->left = x;
		else
			parent->right = x;
	}
	else {
		// Иначе делаем вершину главной
		root = x;
	}

	return x;
}
