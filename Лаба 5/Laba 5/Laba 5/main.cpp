#include <iostream>
#include <windows.h>
	
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;

	while (answer != 0) {
		system("cls");
		cout << "Лабораторная работа №5 Бикеева А. И. Вариант 2\n\n";
		cout << "Тема: Хеширование для организации быстрого поиска данных\n";
		cout << "Цель: Получить навыки по разработке хеш таблиц\n";
		cout << "\nМеню\n";
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