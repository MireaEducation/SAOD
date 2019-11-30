#include "RedBlackTree.h"
#define NIL sentinel
Node* sentinel = new Node(NIL, NIL, 0, NodeColor::Black, ' ');

RedBlackTree::RedBlackTree()
{
	this->root = NIL;
}

RedBlackTree::~RedBlackTree()
{
}

void RedBlackTree::BalanceInsert(Node* x)
{
	/*************************************
		*  maintain Red-Black tree balance  *
		*  after inserting node x           *
		*************************************/

		/* check Red-Black properties */
	while (x != root && x->parent->color == NodeColor::Red) {
		/* we have a violation */
		if (x->parent == x->parent->parent->left) {
			Node* y = x->parent->parent->right;
			if (y->color == NodeColor::Red) {

				/* uncle is RED */
				x->parent->color = NodeColor::Black;
				y->color = NodeColor::Black;
				x->parent->parent->color = NodeColor::Red;
				x = x->parent->parent;
			}
			else {

				/* uncle is BLACK */
				if (x == x->parent->right) {
					/* make x a left child */
					x = x->parent;
					RotateLeft(x);
				}

				/* recolor and rotate */
				x->parent->color = NodeColor::Black;
				x->parent->parent->color = NodeColor::Red;
				RotateRight(x->parent->parent);
			}
		}
		else {

			/* mirror image of above code */
			Node* y = x->parent->parent->left;
			if (y->color == NodeColor::Red) {

				/* uncle is RED */
				x->parent->color = NodeColor::Black;
				y->color = NodeColor::Black;
				x->parent->parent->color = NodeColor::Red;
				x = x->parent->parent;
			}
			else {

				/* uncle is BLACK */
				if (x == x->parent->left) {
					x = x->parent;
					RotateRight(x);
				}
				x->parent->color = NodeColor::Black;
				x->parent->parent->color = NodeColor::Red;
				RotateLeft(x->parent->parent);
			}
		}
	}
	root->color = NodeColor::Black;
}

Node* RedBlackTree::InsertNode(char data)
{
	Node* current, * parent, * x;

	current = root;
	parent = 0;

	// Перебираем узлы дерева, вплоть до листьев
	// или пока не встретим элемент с теми эе данными
	while (current != NIL)
	{
		if (data == current->data)
			return current;
		parent = current;
		current = data > current->data ? current->right : current->left;
	}

	// Для нового узла создаем объект вершины
	x = new Node();
	x->data = data;
	x->parent = parent;
	x->left = NIL;
	x->right = NIL;
	x->color = NodeColor::Red;

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

	if (y->right != NIL) y->right->parent = x;

	if (y != NIL) y->parent = x->parent;
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
	if (x != NIL) x->parent = y;
}

void RedBlackTree::RotateLeft(Node* x)
{
	Node* y = x->right;

	x->right = y->left;
	if (y->left != NIL) y->left->parent = x;

	if (y != NIL) y->parent = x->right;
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
	if (x != NIL) x->parent = y;
}

Node* RedBlackTree::GetRoot()
{
	return this->root;
}
