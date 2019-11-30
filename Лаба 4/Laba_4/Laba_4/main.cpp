#include <iostream>
#include <windows.h>
#include "Operation.h"


using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;
	RedBlackTree* rbTree = nullptr;
	int n = 0;

	while (answer != 0) {
		system("cls");
		cout << "Лабораторная работа №4 Бикеева А. И. Вариант 2\n\n";
		cout << "Использовать  сбалансированное бинарное дерево (Использую Красно-Черные деревья)\n";
		cout << "Информационная часть узла содержит символьное значение\n";
		cout << "\t• Создать дерево из n узлов.\n";
		cout << "\t• Определить сумму цифр, содержащихся в дереве, применив алгоритм симметричного обхода\n";
		cout << "\t• Найти первое вхождение заданного символа и вернуть указатель на узел\n";
		cout << "\t• Найти максимальное значение среди листьев дерева\n";
		cout << "\nМеню\n";
		cout << "1) Создать новый список из n узлов\n";
		cout << "2) Определить сумму цифр, содержащихся в дереве, применив алгоритм симметричного обхода\n";
		cout << "3) Найти первое вхождение заданного символа и вернуть указатель на узел \n";
		cout << "4) Найти максимальное значение среди листьев дерева\n";
		cout << "0) Выход\n";
		cout << "\nВаш выбор: ";
		while ((!(cin >> answer)) || cin.get() != '\n') {     //делаем проверку на ввод букв   
			cout << "ERROR\n";
			cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
			cin.sync();//Удалим данные из буффера
			cout << "Повторите ввод : ";
		}
		system("cls");
		cout << "Лабораторная работа №4 Бикеева А. И. Вариант 2\n\n";
		switch (answer)
		{

			case 0: {
				system("pause");
				break;
			}
			case 1: {
				cout << "Введите кол-во узлов в дереве: ";
				cin >> n;
				if (rbTree != nullptr)
					free(rbTree);
				rbTree = new RedBlackTree();
				CreateTree(rbTree, n);
				PrintTree(rbTree->GetRoot(), n);
				system("pause");
				break;
			}
			case 2: {
				if (rbTree)
				{
					PrintTree(rbTree->GetRoot(), n);
					cout << "Сумма значений в узлав дерева: " << InOrderTravelRL(rbTree->GetRoot(), 0) << endl;
				}
				else {
					cout << "Для начало задайте не пустое дерево\n";
				}
				system("pause");
				break;
			}
			case 3: {
				if (rbTree)
				{
					cout << "Введите значение для поиска в дереве: ";
					char c;
					cin >> c;
					Node* node = FindNode(rbTree->GetRoot(), c);
					if (node && node->data != ' ') {
						cout << "Узел найден, его адрес: " << &node << " его значеение: " << node->data << endl;
					}
					else {
						cout << "Данного узла нет в дереве\n";
					}
				}
				else {
					cout << "Для начало задайте не пустое дерево\n";
				}
				system("pause");
				break;
			}
			case 4: {
				if (rbTree) {
					BinaryTreeNode* max_node = FindMax(rbTree->GetRoot());
					cout << "Максимальный элемент дерева имеет значение: " << max_node->data << " и численно равен: " << (int)max_node->data << endl;
				}else {
					cout << "Для начало задайте не пустое дерево\n";
				}
				system("pause");
				break;
			}
			default:
				break;
		}
	}

	return 0;
}