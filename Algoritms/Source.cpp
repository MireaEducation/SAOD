#include <iostream>
#include <Windows.h>

using namespace std;

/// <summary>
/// ������� ������ ����� num � ��������������� ������� mass � ������� ��������� ������
/// </summary>
/// <param name="mass">����� �����</param>
/// <param name="num">������� ����� � ������ ����� mass</param>
/// <param name="length">������ ������� mass</param>
int BinarySearch(int* mass, int num, int length)
{
	int left = 0,
		right = length - 1;

	//���� �� ����� �� ������� �������
	do
	{
		int mid = (right + left) / 2;//������� ������� ������ � �������� ��������� [left, right]

		if (mass[mid] == num)
			return mid;
		else if (mass[mid] > num)
			right = mid - 1;
		else if (mass[mid] < num)
			left = mid + 1;
	} while (left <= right);

	return -1;//���������, ��� ������� �� ������
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int N = 3;
	int a[N] = { 1, 2, 3 };

	cout << BinarySearch(a, 3, N) << endl;//2
	cout << BinarySearch(a, 2, N) << endl;//1
	cout << BinarySearch(a, 1, N) << endl;//0
	cout << BinarySearch(a, 11, N) << endl;//-1

	return 0;
}