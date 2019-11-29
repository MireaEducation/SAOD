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
				else {
					if (x == x->parent->right) {
						x = x->parent;
						// Тут должен быть поворот дерева влево
					}

					x->parent->color = NodeColor::Black;
					x->parent->parent->color = NodeColor::Red;
					// Здесь должен быть поворт вправо
				}
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
				else {
					if (x == x->parent->left) {
						x = x->parent;
						//здесь должен быть поворот вправо
					}

					x->parent->color = NodeColor::Black;
					x->parent->parent->color = NodeColor::Red;
					// Здесь должен быть поворт влево
				}
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
}

Node* RedBlackTree::GetRoot()
{
	return this->root;
}
