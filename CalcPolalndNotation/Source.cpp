#include <iostream>
#include <Windows.h>
#include <stack>

using namespace std;

/// <summary>
/// Вычисляет мат. выражение записанное в прямой польской нотации
/// </summary>
/// <param name="expression">Мат. выражение записанна¤ в прямой польской нотации</param>
/// <param name="delimiter">Символ разделитель операндов</param>
/// <returns></returns>
double CalculatePreFixNotation(string expression, char delimiter)
{
	stack<double> nums;//стек для хранения операндов (чисел)
	double length = expression.length();//длина строки

	//Пробегаемся по всех символам мат. выражения
	for (int i = length-1; i >= 0; i--)
	{
		double a = 0,
			b = 0;
		int n = 0;//показывает разрядность числа

		//Формируем первый операнда
		while (expression[i] != delimiter) {
			a = a + (expression[i] - '0') * pow(10, n);
			i--; n++;
		}
		nums.push(a);
		i--;//перешагиваем раздлитель
		n = 0;//зануляем разрядность для следующего числа

		//Формируем второй операнда
		while (isdigit(expression[i])) {
			b = b + (expression[i] - '0') * pow(10, n);
			i--; n++;
		}
		nums.push(b);

		//Если это знак операции
		a = nums.top(); nums.pop();//вытаскиваем первый операнд из стека
		b = nums.top(); nums.pop();//вытаскиваем второй операнд из стека

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
	//последний элеметн в стеке и будет окончательным резултатом вычисленного мат. выражения
	return nums.top();
}

/// <summary>
/// Вычисляет мат. выражение записанное в прямой польской нотации
/// </summary>
/// <param name="expression">Мат. выражение записанна¤ в прямой польской нотации</param>
/// <param name="delimiter">Символ разделитель операндов</param>
/// <returns></returns>
double CalculatePostFixNotation(string expression, char delimiter)
{
	stack<double> nums;//стек для хранения операндов (чисел)
	double length = expression.length();//длина строки

	//Пробегаемся по всех символам мат. выражения
	for (double i = 0; i < length; i++)
	{
		double a = 0,
			   b = 0;

			//Формируем первый операнда
			while (expression[i] != delimiter) {
				a = a * 10 + (expression[i] - '0');
				i++;
			}
			nums.push(a);
			i++;//перешагиваем раздлитель

			//Формируем второй операнда
			while (isdigit(expression[i])) {
				b = b * 10 + (expression[i] - '0');
				i++;
			}
			nums.push(b);

			//Если это знак операции
			a = nums.top(); nums.pop();//вытаскиваем первый операнд из стека
			b = nums.top(); nums.pop();//вытаскиваем второй операнд из стека

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
	cout<<"Результат: "<<CalculatePostFixNotation(exp, '&')<<endl;	

	
	cout << "Введите мат. выражение в прямой польской нотации: ";
	cin >> exp;
	cout << "Результат: " << CalculatePreFixNotation(exp, '&') << endl;
	
	return 0;
}