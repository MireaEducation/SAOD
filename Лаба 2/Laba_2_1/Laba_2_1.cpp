﻿#include <iostream>
#include <windows.h>
#include "Stack.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer1 = 10, answer2 = 10;
	Stack stack;
	string exp = "";
	try
	{
		while (answer1 != 0) {
			system("cls");
			cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
			cout << "Вычислить значение арифметического бесскобочного выражения, введенного в виде строки.Операнды операций – это \nцелые числа.Перед вычислением значения выражения следует проверить \nего на корректность записи операций и операндов. .\n";
			cout << "\nМеню - выбор структуры данных\n";
			cout << "1) Динамический массив\n";
			cout << "2) Однонаправленный список\n";
			cout << "0) Выход\n";
			cout << "\nВаш выбор: ";
			while ((!(cin >> answer1)) || cin.get() != '\n') {     //делаем проверку на ввод букв   
				cout << "ERROR\n";
				cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
				cin.sync();//Удалим данные из буффера
				cout << "Повторите ввод : ";
			}
			system("cls");
			cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
			switch (answer1) {
				case 1: {
					while (answer2 != 0) {
						system("cls");
						cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
						cout << "Вычислить значение арифметического бесскобочного выражения, введенного в виде строки.Операнды операций – это \nцелые числа.Перед вычислением значения выражения следует проверить \nего на корректность записи операций и операндов. .\n";
						cout << "\nМеню - выбор дейсвтий\n";
						cout << "1) Записать новое математическое выражение\n";
						cout << "2) Вывести его значение\n";
						cout << "0) Назад\n";
						cout << "\nВаш выбор: ";
						while ((!(cin >> answer2)) || cin.get() != '\n') {     //делаем проверку на ввод букв   
							cout << "ERROR\n";
							cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
							cin.sync();//Удалим данные из буффера
							cout << "Повторите ввод : ";
						}
						system("cls");
						cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
						switch (answer2)
						{
						case 0: {
							break;
						}
						case 1:
						{
							cin >> exp;
							stack.init(exp);

							cout << "Математическое выражение спешно распарсено в стек" << endl;
							system("pause");
							break;
						}
						case 2:
						{
							if (stack.top().getOperation() != ' ')
							{
								double res = stack.getResultExpression();
								cout << exp << " = " << res << endl;
								stack.pop();
							}
							else {
								cout << "Для начала введите мат. выражение" << endl;
							}
							break;
							system("pause");
						}
						default:
						{
							system("pause");
						}
						break;
						}
					}
					break;
				}
				case 2: {
					break;
				}
			}
		}
	}
	catch (const std::exception & ex)
	{
		cout << "Ошибка: " << ex.what() << endl;
	}

	return 0;
}
