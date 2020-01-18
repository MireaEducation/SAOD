#include <iostream>
#include <Windows.h>

using namespace std;

/// <summary>
/// Сортирует массив mass с помощью алгортима быстрой сортировки
/// </summary>
/// <param name="mass">Массив из целых чисел</param>
/// <param name="left">Индекс левой границе сортирвоки массива</param>
/// <param name="right">Индекс правой границе сортирвоки массива</param>
void QuickSort(int* mass, int left, int right)
{
	int item = mass[(left + right)/2];//текущий сортируемый элемент (может быть любой, не оязательно брать по середке)
	int i = left, 
		j = right;
	do {
		//Находим индекс первого элемента, который будет больше item
		//в пределах интервала [left, right]
		while (mass[i] < item) i++;

		//Находим индекс первого элемента, который будет меньше item
		//в пределах интервала [left, right]
		while (mass[j] > item) j--;

		//Если элемент, который больше item расположен
		//левее элемента, который меньше item
		if (i < j) {
			//Меняем эти элементы местами
			int copy = mass[i];
			mass[i] = mass[j];
			mass[j] = copy;
		}
		else {
			i++;
			j--;
		}
	} while (i < j);//повторяем цикл до тех пор, пока оба указателя (i и j) не перескочат через друг друга
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