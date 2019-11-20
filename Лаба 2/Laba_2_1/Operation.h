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