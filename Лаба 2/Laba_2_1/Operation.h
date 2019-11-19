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