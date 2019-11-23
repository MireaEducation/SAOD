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

private:
	static Expression* mass;
};