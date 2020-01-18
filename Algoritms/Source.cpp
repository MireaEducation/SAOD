#include <iostream>
#include <Windows.h>

using namespace std;

/// <summary>
/// Ќаходит индекс числа num в отсортированном массиве mass с помощью бинарного поиска
/// </summary>
/// <param name="mass">Ќабор чисел</param>
/// <param name="num">»скомое числа в наборе чисел mass</param>
/// <param name="length">–азмер массива mass</param>
int BinarySearch(int* mass, int num, int length)
{
	int left = 0,
		right = length - 1;

	//пока не вышли за пределы массива
	do
	{
		int mid = (right + left) / 2;//находим средний индекс с заданном интервале [left, right]

		if (mass[mid] == num)
			return mid;
		else if (mass[mid] > num)
			right = mid - 1;
		else if (mass[mid] < num)
			left = mid + 1;
	} while (left <= right);

	return -1;//указываем, что элемент не найден
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