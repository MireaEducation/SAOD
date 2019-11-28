#include <iostream>
#include <windows.h>
#include "Operation.h"
#include "RedBlackTree.h"

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
		cout << "������������ ������ �4 ������� �. �. ������� 2\n\n";
		cout << "������������  ���������������� �������� ������ (��������� ������-������ �������)\n";
		cout << "�������������� ����� ���� �������� ���������� ��������\n";
		cout << "\t� ������� ������ �� n �����.\n";
		cout << "\t� ���������� ����� ����, ������������ � ������, �������� �������� ������������� ������\n";
		cout << "\t� ����� ������ ��������� ��������� ������� � ������� ��������� �� ����\n";
		cout << "\t� ����� ������������ �������� ����� ������� ������\n";
		cout << "\n����\n";
		cout << "1) ������� ����� ������ �� n �����\n";
		cout << "0) �����\n";
		cout << "\n��� �����: ";
		while ((!(cin >> answer)) || cin.get() != '\n') {     //������ �������� �� ���� ����   
			cout << "ERROR\n";
			cin.clear(); // ���������� ��� ���� ������, ������ ����� ���������� "�������"
			cin.sync();//������ ������ �� �������
			cout << "��������� ���� : ";
		}
		system("cls");
		cout << "������������ ������ �4 ������� �. �. ������� 2\n\n";
		switch (answer)
		{

			case 0: {
				system("pause");
				break;
			}
			case 1: {
				cout << "������� ���-�� ����� � ������: ";
				cin >> n;
				if (rbTree != nullptr)
					free(rbTree);
				rbTree = new RedBlackTree();
				CreateTree(rbTree, n);
				system("pause");
				break;
			}
			default:
				break;
		}
	}

	return 0;
}