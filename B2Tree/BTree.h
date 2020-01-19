#pragma once

/// <summary>
/// Структура вершины сильно ветвистого B-дерева
/// </summary>
template<typename T>
struct NodeBTree 
{
	/// <summary>
	/// true - если узел явл. листом
	/// </summary>
	bool leaf;

	/// <summary>
	/// Кол-во ключей узла
	/// </summary>
	int n;

	/// <summary>
	/// Ключи(Значения) узла
	/// </summary>
	T* keys;

	/// <summary>
	/// Указатели на детей узла упорядоченные по принципу бинарного дерева
	/// </summary>
	NodeBTree* childrens;
};

/// <summary>
/// Структура сильно ветвистого B-дерева 
/// </summary>
template<typename T>
struct BTree
{
	/// <summary>
	/// Минимальная степнь дерева (минимальное кол-во потомков)
	/// </summary>
	int t;

	/// <summary>
	/// Указатель на корень дерева
	/// </summary>
	NodeBTree root;
};