#include <iostream>
#include <Windows.h>

using namespace std;

/// <summary>
/// ��������� ������ ����� mass � ������� ������ "����������� ���������"
/// </summary>
/// <param name="mass">������ �����</param>
/// <param name="length">������ �������</param>
void InsertSort(int* mass, int length)
{
	//����������� �� ���� ��������� ��� ����������
	for (int i = 0; i < length-1; i++)
	{
		//����� ����� ���������� � ��������������� ��������� item
		// item = mass[i + 1];

		//���������� item � ���������������� ����������
		for (int j = i + 1; j > 0; j--)
		{
			//���� ������� ������� ������ �����������
			if (mass[j] < mass[j - 1])
				//������ �� �������
				swap(mass[j], mass[j - 1]);
			else
				//������������� ���������� ������� ��������
				break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int N = 8;
	int a[N] = { 1,2,3,6,2,6,4,65 };

	InsertSort(a, N);

	return 0;
}