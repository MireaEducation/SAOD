#include <iostream>
#include <windows.h>
#include <algorithm>
#include "StackDynamic.h"
#include "LinkedStack.h"
#include "StackHellper.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer1 = 10, answer2 = 10;
	StackDynamic stackDynamic;
	LinkedStack* stackLink = nullptr;
	stack<Expression> expStack = stack<Expression>();

	string exp = "";

		while (answer1 != 0) {
			try
			{
			system("cls");
			cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
			cout << "Вычислить значение арифметического бесскобочного выражения, введенного в виде строки.Операнды операций – это \nцелые числа.Перед вычислением значения выражения следует проверить \nего на корректность записи операций и операндов. .\n";
			cout << "\nМеню - выбор структуры данных\n";
			cout << "1) Динамический массив\n";
			cout << "2) Однонаправленный список\n";
			cout << "3) Контейнер stack из STL\n";
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
#pragma region 1 задание
					while (answer2 != 0) {
						system("cls");
						cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
						cout << "Вычислить значение арифметического бесскобочного выражения, введенного в виде строки.Операнды операций – это \nцелые числа.Перед вычислением значения выражения следует проверить \nего на корректность записи операций и операндов. .\n";
						cout << "\nМеню - выбор дейсвтий над динамическим массивом\n";
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
							case 1:
							{
								cin >> exp;
								stackDynamic.init(exp);
								cout << "Математическое выражение спешно распарсено в стек" << endl;
								system("pause");
								break;
							}
							case 2:
							{
								if (stackDynamic.top().getOperation() != ' ')
								{
									double res = stackDynamic.getResultExpression();
									cout << exp << " = " << res << endl;
									stackDynamic.pop();
								}
								else {
									cout << "Для начала введите мат. выражение" << endl;
								}
								system("pause");
								break;
							}
							default:
							{
								break;
							}
						}
					}
					answer2 = 10;
					break;
#pragma endregion
				}
				case 2: {
#pragma region 2 Заданме
					
					while (answer2 != 0) {
						system("cls");
						cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
						cout << "Вычислить значение арифметического бесскобочного выражения, введенного в виде строки.Операнды операций – это \nцелые числа.Перед вычислением значения выражения следует проверить \nего на корректность записи операций и операндов. .\n";
						cout << "\nМеню - выбор дейсвтий над однонаправленным списком\n";
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
						switch (answer2) {
							case 1:{
								cin >> exp;
								stackLink = new LinkedStack(Expression(exp));//stackLink->init(exp);

								cout << "Математическое выражение спешно распарсено в стек" << endl;
								system("pause");
								break;
							}
							case 2:
							{
								if (stackLink != nullptr)
								{
									double res = stackLink->getResultExpression(stackLink);
									cout << exp << " = " << res << endl;
									stackLink->pop();
								}
								else {
									cout << "Для начала введите мат. выражение" << endl;
								}
								system("pause");
								break;
							}
							case 0: {

							}
							default:
								break;
						}
#pragma endregion
				}
				case 3: {
#pragma region 4 Заданме
					StackHellper hellper;
					while (answer2 != 0) {
						system("cls");
						cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
						cout << "Вычислить значение арифметического бесскобочного выражения, введенного в виде строки.Операнды операций – это \nцелые числа.Перед вычислением значения выражения следует проверить \nего на корректность записи операций и операндов. .\n";
						cout << "\nМеню - выбор дейсвтий над контейнером stack из STL\n";
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
						switch (answer2) {
						case 1: {
							cin >> exp;
							hellper.init(expStack, Expression(exp), exp);


							cout << "Математическое выражение спешно распарсено в стек" << endl;
							system("pause");
							break;
						}
						case 2:
						{
							if (!expStack.empty())
							{
								double res = hellper.getResultExpression(expStack);
								cout << exp << " = " << res << endl;
								expStack.pop();
							}
							else {
								cout << "Для начала введите мат. выражение" << endl;
							}
							system("pause");
							break;
						}
						case 0: {

						}
						default:
							break;
						}
#pragma endregion
					}
				}
				answer2 = 10;
				break;
				}
			}
		}
		catch (const std::exception & ex)
		{
			cout << "Ошибка: " << ex.what() << endl;
			system("pause");
		}
	}

	return 0;
}
