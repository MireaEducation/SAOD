#include <iostream>
#include <Windows.h>

using namespace std;

/// <summary>
/// —ортирует массив mass с помощью алгортима быстрой сортировки
/// </summary>
/// <param name="mass">ћассив из целых чисел</param>
/// <param name="left">»ндекс левой границе сортирвоки массива</param>
/// <param name="right">»ндекс правой границе сортирвоки массива</param>
void QuickSort(int* mass, int left, int right)
{
	int item = mass[(left + right)/2];//текущий сортируемый элемент (может быть любой, не о€зательно брать по середке)
	int i = left, 
		j = right;
	do {
		//Ќаходим индекс первого элемента, который будет больше item
		//в пределах интервала [left, right]
		while (mass[i] < item) i++;

		//Ќаходим индекс первого элемента, который будет меньше item
		//в пределах интервала [left, right]
		while (mass[j] > item) j--;

		//≈сли элемент, который больше item расположен
		//левее элемента, который меньше item
		if (i < j) {
			//ћен€ем эти элементы местами
			int copy = mass[i];
			mass[i] = mass[j];
			mass[j] = copy;
		}
		else {
			i++;
			j--;
		}
	} while (i < j);//повтор€ем цикл до тех пор, пока оба указател€ (i и j) не перескочат через друг друга
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