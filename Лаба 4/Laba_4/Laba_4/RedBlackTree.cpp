#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	this->parent = &BinaryTreeNode();
	this->data = ' ';
}

RedBlackTree::~RedBlackTree()
{
}

BinaryTreeNode* RedBlackTree::RotateToLeft(BinaryTreeNode* node)
{
	BinaryTreeNode* p2 = node->right;
	BinaryTreeNode* p21 = p2->left;
	p2->left = node;
	node->right = p21;
	return p2;
}

void RedBlackTree::BalanceInsert(BinaryTreeNode** root)
{
	BinaryTreeNode* p1, * p2, * px1, * px2;
	BinaryTreeNode* node = *root;

	if (node->color == NodeColor::Red) 
		return;

	p1 = node->left;
	p2 = node->right;
	if (p1 && (p1->color == NodeColor::Red)) 
	{
		px2 = p1->right;             // задача найти две рядом стоящие крастне вершины
		if (px2 && (p1->color == NodeColor::Red)) p1 = node->left = RotateToLeft(p1);

		px1 = p1->left;
		if (px1 && (p1->color == NodeColor::Red)) 
		{
			node->color = NodeColor::Red;
			p1->color = NodeColor::Black;
			if (p2 && (p2->color == NodeColor::Red)) 
			{ // отделаемся перекраской вершин
				px1->color = NodeColor::Red;
				p2->color = NodeColor::Black;
				return;
			}
			*root = RotateToLeft(node);
			return;
		}
	}
	// тоже самое в другую сторону
	if (p2 && (p2->color == NodeColor::Red)) {
		px1 = p2->left;             // задача найти две рядом стоящие крастне вершины
		if (px1 && (px1->color == NodeColor::Red)) p2 = node->right = RotateToLeft(p2);
		px2 = p2->right;
		if (px2 && (px2->color == NodeColor::Red)) {
			node->color = NodeColor::Red;
			p2->color = NodeColor::Black;
			if (p1 && (p1->color == NodeColor::Red)) { // отделаемся перекраской вершин
				px2->color = NodeColor::Red;
				p1->color = NodeColor::Black;
				return;
			}
			*root = RotateToLeft(node);
			return;
		}
	}
}

bool RedBlackTree::Insert(char value, BinaryTreeNode** root)
{
	BinaryTreeNode* node = *root;
	if (!node) *root = this->InsertNode(value);
	else {
		if (value == node->data) return true;
		if (Insert(value, value < node->data ? &node->left : &node->right)) return true;
		BalanceInsert(root);
	}
	return false;
}

BinaryTreeNode* RedBlackTree::InsertNode(char value)
{
	BinaryTreeNode* node = new BinaryTreeNode;
	node->left = node->right = 0;
	node->parent->color = NodeColor::Black;
	return node;
}
