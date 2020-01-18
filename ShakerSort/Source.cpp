#include <iostream>
#include <Windows.h>

using namespace std;


/// <summary>
/// Сортирует массив чисел mass с помощью алгоритма сортировки "Шэйкер"
/// </summary>
/// <param name="mass">Массив чисел</param>
/// <param name="length">Размер массива</param>
void ShakerSort(int* mass, int length)
{
	bool the_end;//флаг завершения сортировки массива
	int left = 0,//указатель на неотсортированный крайний слева элемент
		right = length-1;//указатель на неотсортированный крайний справа элемент
	do
	{
		the_end = true;

		//Берем 2 соседних элемента
		//шагая с слева - направо
		for (int i = left; i < right; i++) {
			//Если текущий элемент больше следующего
			if (mass[i] > mass[i + 1]){
				//Меняем их местами
				swap(mass[i + 1], mass[i]);
				the_end = false;
			}
		}
		//Сдвигаем указатель на крайний неотсортированный элемент справа
		right--;

		//Берем 2 соседних элемента
		//шагая с право - налево
		for (int i = right; i > left; i--) {
			//Если текущий элемент больше следующего
			if (mass[i] < mass[i - 1]) {
				//Меняем их местами
				swap(mass[i - 1], mass[i]);
				the_end = false;
			}
		}
		//Сдвигаем указатель на крайний неотсортированный элемент слева
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