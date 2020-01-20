#include <iostream>
#include <Windows.h>
#include <queue>
#include <vector>

using namespace std;

/// <summary>
/// Обходит весь граф в ширину
/// </summary>
/// <param name="Graph">Граф</param>
/// <param name="start">Номер вершины, с которой начинается погружение</param>
void TraversWidth(vector<vector<int>> Graph, int start)
{
	int N = Graph.size();//запоминаем кол-во вершин в графе
	queue<int> Q;//Очередь для хранения номеров вершин, посещенных на i-ом шаге
	
	// Индекс вектора - номер вершины графа
	// true - если вершину посетили
	vector<bool>is_visited(N, false);

	Q.push(start);
	cout << "Посетили вершину " << start << endl;
	//Q.pop();//Удаляем из очереди вершину, с которой начали поиск в глубину
	is_visited[start] = true;//Помечаем вершину как посещенную
	int count_neighboring;//кол-во соседей (смежных вершин)
	int current_index;//текущая рассматриваемая вершина
	int current_neighboring;//Текущий рассматриваемый сосед (номер вершины)
	
	while (!Q.empty())//Пока все вершины не будут посещены и не обнаружился цикл
	{	
		current_index = Q.front();//Запоминаем следующий индекс вершины для поиска в ширину
		Q.pop();//Удаляем из очереди вершину, с которой начали поиск в глубину
		count_neighboring = Graph[current_index].size();//Для новой вершины - возвразаем кол-во её соседей

		//Пробегаемся по всем соседям
		for (int i = 0; i < count_neighboring; i++)
		{
			current_neighboring = Graph[current_index][i];
			// Если вершина не была посещена 
			if (!is_visited[current_neighboring]) {
				Q.push(current_neighboring);//добавляем в очередь
				is_visited[current_neighboring] = true;//Помечаем вершину как посещенную
				cout << "Посетили вершину " << current_neighboring << endl;
			}
		}
	} 
}


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

	TraversWidth(Graph, 0);

	return 0;
}