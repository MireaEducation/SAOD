#pragma once
#include "HashTable.h"
#include "BankAccount.h"

class HashTableOpenAddress :
	public HashTable<int, BankAccount*>
{
public: 
	HashTableOpenAddress(int size) :HashTable(size) {}

	/// <summary>
	/// Хэщ-функция
	/// </summary>
	/// <param name="key">Ключ элемента из хэш-таблицы</param>
	/// <param name="attempt">Номер попытки</param>
	/// <returns></returns>
	int GetIndex(int key, int attempt)
	{
		return (sizeof(key) % 12 + attempt) % size;
	}

	/// <summary>
	/// Возвращает индекс элемента с заданным ключем и значением в массиве хэш-таблицы
	/// или -1 в случаи если такой элемент не нашелся
	/// </summary>
	/// <param name="key">Ключ элемента из хэш-таблицы</param>
	/// <returns></returns>
	int FindNode(int key)
	{
		int attempt = 0; // кол-во попыток поиска ключа
		int index; // Индекс искомого элемента
		bool flag = false; // Флаг указывающий, что ключ подошел
		HashTableNodePair<int, BankAccount*>* node = 0;
		do
		{
			index = this->GetIndex(key, attempt);
			node = &this->mass[index];
			attempt++;

			flag = node && !node->GetIsVoid() ? (node->GetValue()->account_number == key ? true : false) : false;
			if (flag) break;

		} while (node && attempt != size); // пока не найдется нужный элемент с заданным ключем и значением

		// Если нашелся элемент с заданным ключем и значением в таблице
		if (node && flag) {
			return index;
		}
		else {
			return -1;
		}
	}
};

