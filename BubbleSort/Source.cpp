#include <iostream>
#include <Windows.h>

using namespace std;

/// <summary>
/// Сортирует массив чисел mass с помощью метода Пузырька
/// </summary>
/// <param name="mass">Массив чисел</param>
/// <param name="length">Размер массива</param>
void BubbleSort(int* mass, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length-1; j++)
		{
			//Если текущий элемент больше следующего
			if (mass[j] > mass[j + 1])
				//меняем их местами
				swap(mass[j], mass[j + 1]);
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int N = 8;
	int a[N] = { 1,23,13,6,2,16,4,65 };

	BubbleSort(a, N);

	return 0;
}