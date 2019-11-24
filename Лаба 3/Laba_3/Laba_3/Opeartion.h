#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

/// <summary>
/// Возвращает n-ое число Фибоначчи
/// </summary>
/// <param name="n">Номер числа Фибоначчи</param>
/// <param name="sum_first">k-1 число Фибоначчи</param>
/// <param name="sum_second">k число Фибоначчи</param>
/// <param name="depth">Глубина рекурсии</param>
int Fibonachi(int n, int sum_first, int sum_second, short& depth);

/// <summary>
/// Создает односвязанный список из целых чисел
/// </summary>
/// <param name="head">Указатель на элемент списка</param>
/// <param name="n">Кол-во элементов, которые нужно добавить к head</param>
/// <returns></returns>
LinkedList* CreateList(Node* head, int n);