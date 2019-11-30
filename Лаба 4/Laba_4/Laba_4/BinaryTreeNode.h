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
		this->color = NodeColor::Red;
		this->left = 0;
		this->parent = 0;
		this->right = 0;
		this->data = ' ';
	}

	/// <summary>
	/// Для генерации NIL
	/// </summary>
	/// <param name="isNil">Флаг, для геенерации NIL</param>
	Node(struct Node* left, struct Node* right, struct Node* parent, NodeColor color, char data)
	{
		this->left = left;
		this->right = right;
		this->parent = parent;
		this->color = color;
		this->data = data;
	}
} BinaryTreeNode;