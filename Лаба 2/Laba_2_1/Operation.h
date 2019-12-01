#pragma once
#include <string>
#include "Expression.h"
using namespace std;

/// <summary>
/// true - Данное exp является выраженим
/// false - Данное exp является аргументом
/// </summary>
/// <param name="exp">Второй аргумент в математическом выражении</param>
/// <returns></returns>
bool isExpression(string exp);

/// <summary>
/// Изменяет аргументы местами, согласно высокому приориту операции - меняется порядок
/// </summary>
/// <param name="last">Последнее выражение</param>
/// <param name="preLast">Предпоследнее выражение</param>
void changeNodes(Expression &last, Expression &preLast);

/// <summary>
/// Изменяет аргументы в выражении местами
/// </summary>
/// <param name="last">Последнее выражение</param>
void changeArgs(Expression& last);

/// <summary>
/// Возвращает тот же массив, но с новым размером
/// </summary>
/// <param name="exp">Матемическое выражение</param>
/// <param name="size_old">Старый размер массива</param>
/// <param name="size_new">Новый размер массива</param>
/// <returns></returns>
Expression* updateSize(const Expression* exp, int size_old, int size_new);

/// <summary>
/// Возвращает true - если exp имеет корректную запись
/// false - в ином случаи
/// </summary>
/// <param name="exp">Мат. выражение</param>
/// <returns></returns>
bool isCoorectExpression(string exp);