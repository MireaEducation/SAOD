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
	HashTableNodePair<TKey, TValue> *mass;

	/// <summary>
	/// Размер хэш-таблицы
	/// </summary>
	int size;

	/// <summary>
	/// Хэщ-функция
	/// </summary>
	/// <param name="key">Ключ элемента из хэш-таблицы</param>
	/// <returns></returns>
	int GetIndex(TKey key)
	{
		return (sizeof(key) % 12 - 'a') % size;
	}
public:

	/// <summary>
	/// Инициализирует хэш-таблицу с заданным размером
	/// </summary>
	/// <param name="size">Размер хэш-таблицы</param>
	HashTable(int size)
	{
		mass = new HashTableNodePair<TKey, TValue>[size];
	}

	/// <summary>
	/// Добавляет новый элемент в хэш таблицу
	/// </summary>
	/// <param name="key">Ключ элемента из хэш-таблицы</param>
	/// <param name="value">Значение соответствующее данному ключу</param>
	void Add(TKey key, TValue value)
	{
		int index = this->GetIndex(key);

		HashTableNodePair<TKey, TValue> node = this->mass[index];

		if(! node) {
			node = new HashTableNodePair<TKey, TValue>(key, value);
			mass[index] = node;
		}
	}
};

