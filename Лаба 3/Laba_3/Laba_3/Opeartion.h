#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// Возвращает n-ое число Фибоначчи
/// </summary>
/// <param name="n">Номер числа Фибоначчи</param>
/// <param name="sum_first">k-1 число Фибоначчи</param>
/// <param name="sum_second">k число Фибоначчи</param>
/// <param name="depth">Глубина рекурсии</param>
int Fibonachi(int n, int sum_first, int sum_second, int depth);