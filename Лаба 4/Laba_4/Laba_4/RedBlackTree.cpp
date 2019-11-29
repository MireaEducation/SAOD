#include "RedBlackTree.h"

RedBlackTree::~RedBlackTree()
{
}

void RedBlackTree::BalanceInsert(Node* x)
{
	// Если х - корень
	if (x == this->root)
	{
		x->color = NodeColor::Black;
		return;
	}

	while (x->parent->color == NodeColor::Red)
	{
		// Если отец == левый ребенок
		if (x->parent == x->parent->parent->left) {
			Node* y = x->parent->parent->right;

			// Если есть дядя
			if (y)
			{
				// Если дядя красный
				if (y->color == NodeColor::Red)
				{
					x->parent->color = NodeColor::Black;
					y->color = NodeColor::Black;
					x->parent->parent->color = NodeColor::Red;
					x = x->parent->parent;
				}

			} else {
				if (x == x->parent->right) {
					x = x->parent;
					this->RotateLeft(x);
				}

				x->parent->color = NodeColor::Black;
				x->parent->parent->color = NodeColor::Red;
				this->RotateRight(x->parent->parent);
			}
		}
		else { // Иначе - отец == правый ребенок
			Node* y = x->parent->parent->left;

			// Если есть дядя
			if (y)
			{
				// Если дядя красный
				if (y->color == NodeColor::Red) {
					x->parent->color = NodeColor::Black;
					y->color = NodeColor::Black;
					x->parent->parent->color = NodeColor::Red;
					x = x->parent->parent;
				}
				
			}else {
				if (x == x->parent->left) {
					x = x->parent;
					this->RotateRight(x);
				}

				x->parent->color = NodeColor::Black;
				x->parent->parent->color = NodeColor::Red;
				this->RotateLeft(x->parent->parent);
			}
		}
	}

	this->root->color = NodeColor::Black;
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
	x->data = data;

	// Если дерево имеет хотяб 1 вершину
	if (parent) {
		// Определяем с какой стороны вставить новый узел
		if (data < parent->data) {
			parent->left = x;
		}
		else {
			parent->right = x;
		}
		x->parent = parent;
	}
	else {
		// Иначе делаем вершину главной
		root = x;
	}

	BalanceInsert(x);
	return x;
}

void RedBlackTree::RotateRight(Node* x)
{
	Node* y = x->left;

	x->left = y->right;

	if (y->right != 0) y->right->parent = x;

	if (x->parent) {
		if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
	}
	else {
		this->root = y;
	}

	y->right = x;
	if (x != 0) x->parent = y;
}

void RedBlackTree::RotateLeft(Node* x)
{
	Node* y = x->right;

	x->right = y->left;

	if (y->left != 0) y->left->parent = x;

	if (x->parent) {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else {
		this->root = y;
	}

	y->left = x;
	if (x != 0) x->parent = y;
}

Node* RedBlackTree::GetRoot()
{
	return this->root;
}
