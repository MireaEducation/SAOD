#pragma once

/// <summary>
/// Перечисление цвета вершин
/// </summary>
enum class NodeColor
{
	Black,
	Red
};

/// <summary>
/// Структура вершины красно-черного дерева
/// </summary>
typedef struct Node {
	/// <summary>
	/// Левый узел
	/// </summary>
	struct Node* left;   
	
	/// <summary>
	/// Правый ухел
	/// </summary>
	struct Node* right;

	/// <summary>
	/// Родительский узел
	/// </summary>
	struct Node* parent;

	/// <summary>
	/// Цвет вершины parent
	/// </summary>
	NodeColor color;

	/// <summary>
	/// Информационная часть вершины parent
	/// </summary>
	char data;

	Node() {
		this->color = NodeColor::Black;
		this->left = 0;
		this->parent = 0;
		this->right = 0;
		this->data = ' ';
	}
} BinaryTreeNode;