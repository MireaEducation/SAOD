#include <iostream>
#include <Windows.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*
		Представление графа

		0	-	1		2	-	3
								
		|	\		\/			|
		
		4	-	5		6		7

			\	|	\		\/

		8	-	9	-	10		11
								
			\/				\/	
		
		12		13	-	14		15
	*/



	//Каждый вектор (индекс которого в Graph - номер текущей вершины) представлен подвектором (смежные вершины)
	vector<vector<int>> Graph{
		{1, 4, 5}, {0, 6}, {3, 5}, {2, 7},
		{0, 5, 9}, {0, 2, 4, 9, 10}, {1, 11}, {3, 10},
		{9, 13}, {4, 5, 10, 12}, {5, 7, 9, 15}, {6, 14},
		{9}, {8, 14}, {11, 13}, {10}
	};

	return 0;
}