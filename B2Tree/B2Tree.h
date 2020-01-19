#pragma once

/// <summary>
/// Структура сильно ветвистого B-дерева 
/// </summary>
template<typename T>
struct B2Tree
{
	/// <summary>
	/// Кол-во насследников
	/// </summary>
	int N;

	/// <summary>
	/// Указатель на дин. массив насследников
	/// </summary>
	B2Tree* inherits;

	/// <summary>
	/// Информационная часть узла
	/// </summary>
	T data;
};