#include <iostream>
#include <windows.h>
#include "Operation.h"
#include "Telephone.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer2 = 10;
	Telephone* list = nullptr;

	while (answer2 != 0) {
		system("cls");
		cout << "Лабораторная работа №1 Бикеева А. И. Вариант 2\n\n";
		cout << "Задание 1\nРазработать многомодульную программу, \nкоторая демонстрирует выполнение всех операций, \nопределенных вариантом, над линейным однонаправленным \nдинамическим списком.\n";
		cout << "\nМеню\n";
		cout << "1) Создать новый список из n узлов\n";
		cout << "2) Вывести список\n";
		cout << "0) Выход\n";
		cout << "\nВаш выбор: ";
		while ((!(cin >> answer2)) || cin.get() != '\n') {     //делаем проверку на ввод букв   
			cout << "ERROR\n";
			cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
			cin.sync();//Удалим данные из буффера
			cout << "Повторите ввод : ";
		}
		system("cls");
		cout << "Лабораторная работа №1 Бикеева А. И. Вариант 2\n\n";
		switch (answer2)
		{
		case 0: {
			system("pause");
			break;
		}
		case 1:
		{
			if (list)
			{
				free(list);
			}
			int n = 0;
			cout << "Список из скольких элементов вы хотите создать? : ";
			cin >> n;
			cout << "\n\n";
			list = (Telephone*)malloc(sizeof(Telephone));
			list = createList(list, n);

			cout << "\n\nСписок сформирован";
			system("pause");
			break;
		}
		default:
		{
			cout << "Вывод списка\n\n";
			showList(list);
			system("pause");
		}
		break;
		}
	}

	return 0;
}
