#include <iostream>
#include <windows.h>
#include "Stack.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer2 = 10;
	Stack stack;
	string exp = "";
	try
	{
		while (answer2 != 0) {
			system("cls");
			cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
			cout << "Задание 1\nВычислить значение арифметического бесскобочного выражения, введенного в виде строки.Операнды операций – это \nцелые числа.Перед вычислением значения выражения следует проверить \nего на корректность записи операций и операндов. .\n";
			cout << "\nМеню\n";
			cout << "1) Записать новое математическое выражение\n";
			cout << "2) Вывести его значение\n";
			cout << "0) Выход\n";
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
				system("pause");
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
				cout << exp << " = " << stack.getResultExpression() << endl;
				system("pause");
				break;
			}
			case 3:
			{

				system("pause");
				break;
			}
			case 4:
			{

				system("pause");
				break;
			}
			case 5:
			{

				system("pause");
				break;
			}
			case 6:
			{

				system("pause");
				break;
			}
			case 7:
			{

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

	}
	catch (const std::exception & ex)
	{
		cout << "Ошибка: " << ex.what() << endl;
	}
		
	stack.~Stack();
		

	return 0;
}
