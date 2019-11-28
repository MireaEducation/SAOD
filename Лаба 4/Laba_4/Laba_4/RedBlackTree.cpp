#include "RedBlackTree.h"

RedBlackTree::~RedBlackTree()
{
}

Node* RedBlackTree::InsertNode(char data)
{
	Node* current, * parent, * x;

	current = root;
	parent = 0;
	while (current)
	{
		if (data == current->data)
			return current;
		parent = current;
		current = data > current->data ? current->right : current->left;
	}

	x = new Node();

	if (parent) {
		if (data == parent->data)
			parent->left = x;
		else
			parent->right = x;
	}
	else {
		root = x;
	}

	return x;
}
