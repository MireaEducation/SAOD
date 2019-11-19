#pragma once
#include "Expression.h"
#include "stdlib.h"

class Stack
{
private:
	Expression* mass;
	int size;

public:
	Stack();

	/// <summary>
	/// Инициализирует стек
	/// </summary>
	/// <param name="exp">Математическое выражение</param>
	void init(string exp);

	/// <summary>
	/// Добавляет в конец стека новый элемент
	/// </summary>
	/// <param name="elem">Новое выражение</param>
	void push(Expression elem);
};

