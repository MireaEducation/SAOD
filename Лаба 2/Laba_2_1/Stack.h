#pragma once
#include "Expression.h"
class Stack
{
private:
	Expression* mass;
	int size;
public:
	Stack(string exp);

	/// <summary>
	/// Добавляет в конец стека новый элемент
	/// </summary>
	/// <param name="elem">Новое выражение</param>
	void push(Expression elem);
};

