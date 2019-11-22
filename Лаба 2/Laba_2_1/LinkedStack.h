#pragma once
#include "Operation.h"
#include "stdlib.h"
#include "math.h"

class LinkedStack
{
private:
	Expression* next;
	Expression* current;
	int size;

public:
	LinkedStack();
	~LinkedStack();

	/// <summary>
	/// Инициализирует стек
	/// </summary>
	/// <param name="exp">Математическое выражение</param>
	void init(string exp);

	/// <summary>
	/// Добавляет в конец стека новый элемент
	/// </summary>
	/// <param name="elem">Новое выражение</param>
	void push(Expression* elem);

	/// <summary>
	/// Удаляет последний элемент из стека
	/// </summary>
	void pop();

	/// <summary>
	/// Возвращает последний элемент в стеке
	/// </summary>
	Expression top();

	/// <summary>
	/// Возвращает значение математического выражения
	/// </summary>
	/// <returns></returns>
	double getResultExpression();
};

