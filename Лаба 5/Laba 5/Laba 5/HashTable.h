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

	TValue GetValue() {
		return value;
	}

	TKey GetKey() {
		return key;
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
	/// <param name="attempt">Номер попытки</param>
	/// <returns></returns>
	int GetIndex(TKey key, int attempt)
	{
		return (sizeof(key) % 12 - 'a' + attempt) % size;
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
		int attempt = 0; // кол-во попыток добавить новый элемент
		int index; // индекс для нового элемента
		HashTableNodePair<TKey, TValue> node = 0; // Новый элемент на добавление в таблицу
		do
		{
			index = this->GetIndex(key, attempt);
			node = this->mass[index];
			attempt++;
		} while (node && attempt != size); // пока существует по заданному ключу элемент
		mass[index] = node;
	}

	void Print()
	{
		for (size_t j = 0; j < 50; j++) cout << "_";
		cout << endl;

		cout << "|\Key\t|";
		for (size_t i = 0; i < this->size; i++)
		{
			if(mass[i])
				cout << "|\t" <<mass[i].GetKey()<< "\t|";
			else
				cout << "|\tNULL\t|";
		}
		cout << endl;

		cout << "|\Value\t|";
		for (size_t i = 0; i < this->size; i++)
		{
			if (mass[i])
				cout << "|\t" << mass[i].GetValue() << "\t|";
			else
				cout << "|\tNULL\t|";
		}
		cout << endl;
	}
};

