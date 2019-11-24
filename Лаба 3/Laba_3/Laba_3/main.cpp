#include <windows.h>
#include "Opeartion.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	short answer = 10;
	LinkedList* linkLst = nullptr;

	try
	{
		while (answer != 0) {
			system("cls");
			cout << "Лабораторная работа №3 Бикеева А. И. Вариант 2\n\n";
			cout << "\nМеню\n";
			cout << "1) Найти n-ое число Фибоначчи\n";
			cout << "2) Найти указатель на n-ый элемент списка\n";
			cout << "0) Выход\n";
			cout << "\nВаш выбор: ";
			while ((!(cin >> answer)) || cin.get() != '\n') {     //делаем проверку на ввод букв   
				cout << "ERROR\n";
				cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
				cin.sync();//Удалим данные из буффера
				cout << "Повторите ввод : ";
			}
			system("cls");
			cout << "Лабораторная работа №2 Бикеева А. И. Вариант 2\n\n";
			short n = 0;
			switch (answer) {
				case 1: {
					cout << "Введите n: ";

					short depth = 0;
					cin >> n;
					cout << "F[" << n << "] = " << Fibonachi(n, 0, 0, depth) << endl<<"Глубина рекурсии: "<<depth<<endl;
					system("pause");
					break;
				}
				case 2: {
					cout << "Введите n: ";

					cin >> n;
					if (linkLst != nullptr)
						ClearList(linkLst);

					linkLst = CreateList(linkLst, n);
					
					cout << "Введите значение искомого узла: ";

					int value = 0;
					cin >> value;
					
					LinkedList* elem = FindNode(linkLst, value);
					if (elem != nullptr) {
						cout << "Данный узел имеет адрес: " << &elem << endl;
					}
					else {
						cout << "Узла с заданным значение value - не найден в списке\n";
					}

					system("pause");
					break;
				}
				case 0: {

					break;
				}
				default:
					break;
			}
		}
		if (linkLst != nullptr)
			ClearList(linkLst);
	}
	catch (const std::exception* exc)
	{
		cout << "Error: " << exc->what()<<endl;
	}


	return 0;
}