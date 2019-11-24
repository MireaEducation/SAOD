#pragma once
#include "Operation.h"
#include "stdlib.h"
#include "math.h"

class LinkedStack
{
private:
	LinkedStack* next;
	Expression value;

	/// <summary>
	/// Возвращает предпоследний элемент в стеке
	/// </summary>
	LinkedStack* preTop();

	/// <summary>
	/// Возвращает предпоследний элемент в стеке
	/// </summary>
	LinkedStack* prePreTop();
public:
	LinkedStack(Expression elem);
	~LinkedStack();

	/// <summary>
	/// Добавляет в конец стека новый элемент
	/// </summary>
	/// <param name="elem">Новое выражение</param>
	void push(Expression elem);

	/// <summary>
	/// Удаляет последний элемент из стека
	/// </summary>
	void pop();

	/// <summary>
	/// Возвращает последний элемент в стеке
	/// </summary>
	LinkedStack* top();

	/// <summary>
	/// Возвращает значение математического выражения
	/// </summary>
	/// <returns></returns>
	double getResultExpression(LinkedStack* head);
};

