#pragma once
#include "Operation.h"
#include <string>
using namespace std;


class Expression
{
private:
	/// <summary>
	/// Первый аргумент
	/// </summary>
	string firstArg;

	/// <summary>
	/// Второй аргумент
	/// </summary>
	string lastArg;

	/// <summary>
	/// Знак операции
	/// </summary>
	char operation;
public:
	/// <summary>
	/// Создает объект по умолчанию
	/// </summary>
	Expression();

	/// <summary>
	/// Создает объект распарсив выражение
	/// </summary>
	/// <param name="expression">Выражение, которое нужуно распарсить</param>
	Expression(string expression);

	/// <summary>
	/// Возвращает результат выражения
	/// </summary>
	/// <returns></returns>
	double getResult();

	string getLastArg();
};

