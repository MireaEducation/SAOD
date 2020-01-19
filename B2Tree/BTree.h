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

	/// <summary>
	/// Возвращает индекс родителя узла с индексом i
	/// </summary>
	/// <param name="tree">Указатель на корень дерева</param>
	/// <param name="i">Индекс потомка</param>
	/// <returns></returns>
	int FindParent(NodeBTree* tree, int i);

	/// <summary>
	/// Возвращает индекс правого брата
	/// Или -1, если правого брата нет
	/// </summary>
	/// <param name="tree">Указатель на корень дерева</param>
	/// <param name="i">Индекс потомка</param>
	/// <returns></returns>
	int rightBrather(BTree* tree, int i);
};