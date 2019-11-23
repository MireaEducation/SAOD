#pragma once
#include <stack>
#include "Operation.h"

static class StackHellper
{
public:
	/// <summary>
	/// Инициализирует стек
	/// </summary>
	/// <param name="exp">Математическое выражение</param>
	static void init(stack<Expression>& mass, Expression elem, string exp);

	/// <summary>
	/// Возвращает значение математического выражения
	/// </summary>
	/// <returns></returns>
	static double getResultExpression(stack<Expression>& mass);
private:
	static Expression* mass;
};