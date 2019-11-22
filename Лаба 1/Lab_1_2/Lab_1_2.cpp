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
		cout << "Задание 2\nРазработать многомодульную программу, \nкоторая демонстрирует выполнение всех операций, \nопределенных вариантом, над линейным однонаправленным \nдинамическим списком.\n";
		cout << "\nМеню\n";
		cout << "1) Создать новый список из n узлов\n";
		cout << "2) Вывести список\n";
		cout << "3) Найти первый узел с указанным номером отправителя\n";
		cout << "4) Добавит новый узел в список\n";
		cout << "5) Упорядочить список по 1-ым четырем цифрам телефона\n";
		cout << "6) Удалить последний узел с заданным значением телефона отправителя\n";
		cout << "7) Подчитать суммарное время разговора с заданным номером отправителя\n";
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
		case 2:
		{
			if (list)
			{
				cout << "Вывод списка\n\n";
				showList(list);
			}
			else {
				cout << "Список пуст";
			}
			system("pause");
			break;
		}
		case 3:
		{
			if (list)
			{
				int phoneFrom = 0;
				cout << "Введите номер телефона отправителя: "; cin >> phoneFrom;
				Telephone* finded = findNode(list, phoneFrom);
				if (finded)
				{
					cout << "\n\n";
					cout << "Номер отправителя: " << finded->getPhoneFrom() << "\tНомер получателя: " << finded->getPhoneTo() << "\tВремя разговора: " << finded->getTimeTell() << endl;
				}
				else {
					cout << "Узле с указанным телефоном отправителя - не найден" << endl;
				}
			}
			else {
				cout << "Список пуст\n\n";
			}
			system("pause");
			break;
		}
		case 4:
		{
			if (list)
			{
				addNode(getLastNode(list), nullptr);
				cout << "\n\nНовый узел добавлен";
			}
			else {
				cout << "Список пуст\n\n";
			}
			system("pause");
			break;
		}
		case 5:
		{
			if (list)
			{
				sortList(list);
				cout << "\n\nСписок упорядочен" << endl;
			}
			else {
				cout << "Список пуст\n\n";
			}
			system("pause");
			break;
		}
		case 6:
		{
			if (list)
			{
				deletChoosenNode(list);
				cout << "\n\nОперация выполнена успешно" << endl;
			}
			else {
				cout << "Список пуст\n\n";
			}
			system("pause");
			break;
		}
		case 7:
		{
			if (list)
			{
				int phoneFrom = 0;
				cout << "Введите номер телефона отправителя: "; cin >> phoneFrom;
				cout << "\n\nВремя разговора с данным телефоном = " << sumTimeTell(list, phoneFrom) << endl;
			}
			else {
				cout << "Список пуст\n\n";
			}
			system("pause");
			break;
		}
		default:
		{
			system("pause");
		}
		break;
		}
	}

	if (list)
	{
		free(list);
	}
	return 0;
}
