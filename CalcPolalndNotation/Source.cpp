#include <iostream>
#include <Windows.h>
#include <stack>

using namespace std;

/// <summary>
/// Вычисл¤ет мат. выражение записанное в обратной польской нотации
/// </summary>
/// <param name="expression">Мат. выражение записанна¤ в обратной польской нотации</param>
/// <returns></returns>
double CalculatePostFixNotation(string expression)
{
	stack<int> nums;//стек для хранения операндов (чисел)
	int length = expression.length();//длина строки

	//Пробегаемся по всех символам мат. выражения
	for (int i = 0; i < length; i++)
	{
		//если это число
		if(isdigit(expression[i]))
			nums.push(expression[i] - '0');//добавляем его в стек
		else {
			//Если это знак операции
			int a = nums.top(); nums.pop();//вытаскиваем первый операнд из стека
			int b = nums.top(); nums.pop();//вытаскиваем второй операнд из стека

			switch (expression[i])//узнаем какой знак операции нам дан и на основе этого проводим вычисления и добавляем результат в стек
			{
				case '+':
					nums.push(a + b);
					break;
				case '-':
					nums.push(a - b);
					break;
				case '*':
					nums.push(a * b);
					break;
				case '/':
					nums.push(a / b);
					break;
				default:
					break;
			}
		}

	}
//последний элеметн в стеке и будет окончательным резултатом вычисленного мат. выражения
	return nums.top();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string exp;
	cout << "Введите мат. выражение в обратной польской нотации: ";
	cin >> exp;
	cout<<"Результат: "<<CalculatePostFixNotation(exp)<<endl;

	return 0;
}