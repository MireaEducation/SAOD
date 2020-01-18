#include <iostream>
#include <Windows.h>

using namespace std;

/// <summary>
/// ��������� ������ mass � ������� ��������� ������� ����������
/// </summary>
/// <param name="mass">������ �� ����� �����</param>
/// <param name="left">������ ����� ������� ���������� �������</param>
/// <param name="right">������ ������ ������� ���������� �������</param>
void QuickSort(int* mass, int left, int right)
{
	int item = mass[(left + right)/2];//������� ����������� ������� (����� ���� �����, �� ���������� ����� �� �������)
	int i = left, 
		j = right;
	do {
		//������� ������ ������� ��������, ������� ����� ������ item
		//� �������� ��������� [left, right]
		while (mass[i] < item) i++;

		//������� ������ ������� ��������, ������� ����� ������ item
		//� �������� ��������� [left, right]
		while (mass[j] > item) j--;

		//���� �������, ������� ������ item ����������
		//����� ��������, ������� ������ item
		if (i < j) {
			//������ ��� �������� �������
			int copy = mass[i];
			mass[i] = mass[j];
			mass[j] = copy;
		}
		else {
			i++;
			j--;
		}
	} while (i < j);//��������� ���� �� ��� ���, ���� ��� ��������� (i � j) �� ���������� ����� ���� �����
	if (left < j) QuickSort(mass, left, j);
	if (i < right) QuickSort(mass, i, right);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int N = 3;
	int a[N] = { 3, 1, 4 };

	QuickSort(a, 0, N-1);

	return 0;
}