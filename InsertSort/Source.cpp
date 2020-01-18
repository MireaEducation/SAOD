#include <iostream>
#include <Windows.h>

using namespace std;

/// <summary>
/// Сортирует массив чисел mass с помощью метода "Сортироввка вставками"
/// </summary>
/// <param name="mass">Массив чисел</param>
/// <param name="length">Размер массива</param>
void InsertSort(int* mass, int length)
{
	//Пробегаемся по всем элементам для сортировки
	for (int i = 0; i < length-1; i++)
	{
		//Берем самый близжайший к отсортированным элементам item
		// item = mass[i + 1];

		//Сравниваем item с отсортированными элементами
		for (int j = i + 1; j > 0; j--)
		{
			//Если текущий элемент меньше предыдущего
			if (mass[j] < mass[j - 1])
				//меняем их местами
				swap(mass[j], mass[j - 1]);
			else
				//Останавливаем сортировку данного элемента
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