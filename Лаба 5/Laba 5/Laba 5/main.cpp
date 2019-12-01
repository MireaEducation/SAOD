#include <windows.h>
#include "Operation.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;
	HashTable<int, BankAccount*> *table = nullptr;

	while (answer != 0) {
		system("cls");
		cout << "Лабораторная работа №5 Бикеева А. И. Вариант 2\n\n";
		cout << "Тема: Хеширование для организации быстрого поиска данных\n";
		cout << "Цель: Получить навыки по разработке хеш таблиц\n";
		cout << "\nМеню\n";
		cout << "1) Сформировать хэш-таблицу из n элементов\n";
		cout << "0) Выход\n";
		cout << "\nВаш выбор: ";
		while ((!(cin >> answer)) || cin.get() != '\n') {     //делаем проверку на ввод букв   
			cout << "ERROR\n";
			cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
			cin.sync();//Удалим данные из буффера
			cout << "Повторите ввод : ";
		}
		system("cls");
		cout << "Лабораторная работа №5 Бикеева А. И. Вариант 2\n\n";
		switch (answer)
		{
		case 1: {
			cout << "Укажите размер хэш-таблицы: ";
			int n = 0;
			cin >> n;
			table = new HashTable<int, BankAccount*>(n);
			CreateTable(table, n);
			table->Print();
			system("pause");
			break;
		}
		case 0: {
			system("pause");
			break;
		}
		default:
			break;
		}
	}
	return 0;
}