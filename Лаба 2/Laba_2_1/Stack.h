#pragma once
#include "Operation.h"
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

	/// <summary>
	/// Возвращает тот же массив, но с новым размером
	/// </summary>
	/// <param name="exp">Матемическое выражение</param>
	/// <param name="size_old">Старый размер массива</param>
	/// <param name="size_new">Новый размер массива</param>
	/// <returns></returns>
	Expression* updateSize(const Expression* exp, int size_old, int size_new);

	bool isExpression(string exp)
	{
		int index = -1;

		Expression obj;

		obj.getCharOperation(exp, index);

		if (index == -1)
			return false;
		else
			return true;
	}

	/// <summary>
	/// Возвращает значение математического выражения
	/// </summary>
	/// <returns></returns>
	double getResultExpression();
};

