#pragma once

/// <summary>
/// Перечисление цвета вершин
/// </summary>
enum NodeColor
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
} BinaryTreeNode;