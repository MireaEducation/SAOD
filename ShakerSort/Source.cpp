#include <iostream>
#include <Windows.h>

using namespace std;


/// <summary>
/// ��������� ������ ����� mass � ������� ��������� ���������� "������"
/// </summary>
/// <param name="mass">������ �����</param>
/// <param name="length">������ �������</param>
void ShakerSort(int* mass, int length)
{
	bool the_end;//���� ���������� ���������� �������
	int left = 0,//��������� �� ����������������� ������� ����� �������
		right = length-1;//��������� �� ����������������� ������� ������ �������
	do
	{
		the_end = true;

		//����� 2 �������� ��������
		//����� � ����� - �������
		for (int i = left; i < right; i++) {
			//���� ������� ������� ������ ����������
			if (mass[i] > mass[i + 1]){
				//������ �� �������
				swap(mass[i + 1], mass[i]);
				the_end = false;
			}
		}
		//�������� ��������� �� ������� ����������������� ������� ������
		right--;

		//����� 2 �������� ��������
		//����� � ����� - ������
		for (int i = right; i > left; i--) {
			//���� ������� ������� ������ ����������
			if (mass[i] < mass[i - 1]) {
				//������ �� �������
				swap(mass[i - 1], mass[i]);
				the_end = false;
			}
		}
		//�������� ��������� �� ������� ����������������� ������� �����
		left++;
	} while (!the_end);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int N = 7;
	int a[N] = { 1, 1, 4, 12, 6, 2,3532 };

	ShakerSort(a, N);

	return 0;
}