#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// Шаблонный класс для узлов Хэш-Таблицы
/// TKey - тип для ключа
/// TValue - тип для значения
/// </summary>
template<class TKey, class TValue>
class HashTableNodePair
{
private:
	TKey key;
	TValue value;
public:

	/// <summary>
	/// Инициализирует новый элемент в хэш-таблице
	/// </summary>
	/// <param name="key">Ключ в хэш-таблице</param>
	/// <param name="value">Значение соответствующее данному ключу</param>
	HashTableNodePair(TKey key, TValue value)
	{
		this->key = key;
		this->value = value;
	}
};

/// <summary>
/// Шаблонный класс Хэш-Таблицы
/// TKey - тип для ключа
/// TValue - тип для значения
/// </summary>
template<class TKey, class TValue>
class HashTable
{
private:

	/// <summary>
	/// Массив узлов хэш-таблицы
	/// </summary>
	HashTableNodePair<TKey, TValue> mass;
public:

	/// <summary>
	/// Инициализирует хэш-таблицу с заданным размером
	/// </summary>
	/// <param name="size">Размер хэш-таблицы</param>
	HashTable(int size)
	{
		mass = new HashTableNodePair<TKey, TValue>[size];
	}
};

