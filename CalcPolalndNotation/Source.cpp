#include <iostream>
#include <Windows.h>
#include <stack>

using namespace std;

/// <summary>
/// Вычисляет мат. выражение записанное в прямой польской нотации
/// </summary>
/// <param name="expression">Мат. выражение записанна¤ в прямой польской нотации</param>
/// <returns></returns>
double CalculatePreFixNotation(string expression)
{
	stack<double> nums;//стек для хранения операндов (чисел)
	double length = expression.length();//длина строки

	//Пробегаемся по всех символам мат. выражения
	for (int i = length-1; i >= 0; i--)
	{
		//если это число
		if (isdigit(expression[i]))
			nums.push(expression[i] - '0');//добавляем его в стек
		else {
			//Если это знак операции
			double a = nums.top(); nums.pop();//вытаскиваем первый операнд из стека
			double b = nums.top(); nums.pop();//вытаскиваем второй операнд из стека

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

/// <summary>
/// Вычисляет мат. выражение записанное в обратной польской нотации
/// </summary>
/// <param name="expression">Мат. выражение записанна¤ в обратной польской нотации</param>
/// <returns></returns>
double CalculatePostFixNotation(string expression)
{
	stack<double> nums;//стек для хранения операндов (чисел)
	double length = expression.length();//длина строки

	//Пробегаемся по всех символам мат. выражения
	for (double i = 0; i < length; i++)
	{
		//если это число
		if(isdigit(expression[i]))
			nums.push(expression[i] - '0');//добавляем его в стек
		else {
			//Если это знак операции
			double a = nums.top(); nums.pop();//вытаскиваем первый операнд из стека
			double b = nums.top(); nums.pop();//вытаскиваем второй операнд из стека

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
	/*
	cout << "Введите мат. выражение в обратной польской нотации: ";
	cin >> exp;
	cout<<"Результат: "<<CalculatePostFixNotation(exp)<<endl;
	*/
	cout << "Введите мат. выражение в прямой польской нотации: ";
	cin >> exp;
	cout << "Результат: " << CalculatePreFixNotation(exp) << endl;

	return 0;
}