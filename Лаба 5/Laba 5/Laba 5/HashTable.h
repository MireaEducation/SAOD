#pragma once

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
	bool isVoid; // Указывает - удален ли элемент
public:
	HashTableNodePair()
	{
		this->isVoid = true;
	}

	/// <summary>
	/// Инициализирует новый элемент в хэш-таблице
	/// </summary>
	/// <param name="key">Ключ в хэш-таблице</param>
	/// <param name="value">Значение соответствующее данному ключу</param>
	HashTableNodePair(TKey key, TValue value)
	{
		this->key = key;
		this->value = value;
		this->isVoid = false;
	}

	TValue GetValue() {
		return value;
	}

	TKey GetKey() {
		return key;
	}

	bool GetIsVoid() {
		return this->isVoid;
	}

	void SetValue(TValue value) {
		this->value = value;
	}

	void SetIsVoid(bool value) {
		this->isVoid = value;
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
		return (sizeof(key) % 12 + attempt) % size;
	}
public:

	/// <summary>
	/// Инициализирует хэш-таблицу с заданным размером
	/// </summary>
	/// <param name="size">Размер хэш-таблицы</param>
	HashTable(int size)
	{
		this->size = size;
		mass = new HashTableNodePair<TKey, TValue>[size];
	}

	HashTableNodePair<TKey, TValue>* GetMass()
	{
		return this->mass;
	}

	/// <summary>
	/// Добавляет новый элемент в хэш таблицу
	/// </summary>
	/// <param name="key">Ключ элемента из хэш-таблицы</param>
	/// <param name="value">Значение соответствующее данному ключу</param>
	void Add(TKey key, TValue value)
	{
		// Если указанного элемента нет в таблице
		if (this->FindNode(key, value) == -1)
		{
			int attempt = 0; // кол-во попыток добавить новый элемент
			int index; // индекс для нового элемента
			HashTableNodePair<TKey, TValue> *node = 0; // Новый элемент на добавление в таблицу
			do
			{
				index = this->GetIndex(key, attempt);
				node = &this->mass[index];
				attempt++;
			} while (node && node->GetIsVoid() == false && attempt != size); // пока существует по заданному ключу элемент
		
			if ( (node && node->GetIsVoid()) || !node) { // Если по заданному ключу - элемент удален
				this->mass[index] = HashTableNodePair<TKey, TValue>(key, value);
			}
			else {
				throw new exception("Таблица заполнена");
			}
		}
		else {
			throw new exception("Элемент с указанным ключем и значением уже существует");
		}
	}

	/// <summary>
	/// Удаляет элемент из таблицы с заданным ключом и значением
	/// </summary>
	/// <param name="key">Ключ элемента из хэш-таблицы</param>
	/// <param name="value">Значение соответствующее данному ключу</param>
	/// <returns></returns>
	bool Remove(TKey key, TValue value) 
	{
		// Если в таблице есть элементы
		if (size)
		{
			int index = this->FindNode(key, value); 

			// Если нашелся элемент с заданным ключем и значением в таблице
			if (index != -1)
			{
				this->mass[index].SetIsVoid(true); // Помечаем его удаленным
			}
			else {
				throw new exception("Элемента с указанным ключем и значением - нет в таблице");
			}
		}
	}

	/// <summary>
	/// Возвращает индекс элемента с заданным ключем и значением в массиве хэш-таблицы
	/// или -1 в случаи если такой элемент не нашелся
	/// </summary>
	/// <param name="key">Ключ элемента из хэш-таблицы</param>
	/// <param name="value">Значение соответствующее данному ключу</param>
	/// <returns></returns>
	int FindNode(TKey key, TValue value)
	{
		int attempt = 0; // кол-во попыток поиска ключа
		int index; // Индекс искомого элемента
		HashTableNodePair<TKey, TValue> *node = 0;
		do
		{
			index = this->GetIndex(key, attempt);
			node = &this->mass[index];
			attempt++;
		} while (node && (node->GetIsVoid() == true || node->GetValue() != value) && attempt != size); // пока не найдется нужный элемент с заданным ключем и значением

		// Если нашелся элемент с заданным ключем и значением в таблице
		if (node && node->GetIsVoid() == true && node->GetValue() == value) {
			return index;
		}
		else {
			return -1;
		}
	}
};