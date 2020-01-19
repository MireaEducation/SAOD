#include <iostream>
#include <Windows.h>
#include <stack>

using namespace std;

int priorOp(char c) {
	switch (c) {
	case '(': return 1;
	case '+': case '-': return 2;
	case '*': case '/': return 3;
	default: return 0;
	}
}

/// <summary>
/// Конвертируте мат. выражение в Обратную Польскую натацию 
/// </summary>
/// <param name="str">Строка с мат. выраженим</param>
/// <param name="delimiter">Разделитель операндов</param>
/// <returns></returns>
string ConvertToPostFixNotation(string str, char delimiter) {
	//флаги, показывающие наличие операторов и скобок
	bool is_oper = false;
	int np = 0;

	stack<char> opStack;    //стек с символами строки
	opStack.push('b');//Ставим некий флаг начала стека
	string outputStr = "";//Сформированная строка в обратной польской натации

	try
	{
		//Пробегаемся по всем символам мат. выражения
		for (int i = 0; str[i] != '\0'; i++) {
			//Если текущий символ - число
			if (isdigit(str[i])) {
				outputStr += str[i];
				is_oper = false;
				continue;
			}
			else if(!is_oper) outputStr += delimiter;//т.к. встретился символ не явл. числом - ставим разделитель

			//проверяем знак операции
			switch (str[i]) {
				case '(':
					opStack.push(str[i]);
					++np;
					is_oper = false;
					break;
				case '*': case '/': case '+': case '-':
					if (!is_oper) {
						is_oper = true;

						//Пока приоритет текущей операции меньше либо равен чем той, что лежит в стеке
						while (opStack.size() > 0 && priorOp(str[i]) <= priorOp(opStack.top())) {
							//Пишем, чтобы шло выполнение операции с наибольшим приоритетом
							outputStr += opStack.top();
							opStack.pop();
						}
						if (opStack.size() > 0) {
							opStack.push(str[i]);
						}
						break;
					}
					else cout << "Ошибка приоритета операции!\n";

				case ')':
					if (is_oper)
						cout << "Ошибка: неверно поставлена скобка!\n";
					else {
						char c = opStack.top(); opStack.pop();
						while ((str[i] = c) != '(' && np > 0) {
							outputStr += str[i];
							c = opStack.top(); opStack.pop();
						}
						np--;
					}
					break;
				default: {
					cout << "Error: неопознанный символ\n";
				}
			}
		}
		while (opStack.size() != 0) {
			outputStr += opStack.top();
			opStack.pop();
		}
		if (np)
			cout << "Error: неравное кол-во скобок!\n";
	}
	catch (const std::exception& exc)
	{
		cout << exc.what();
	}
	outputStr.pop_back();//удаляем флажок, добавленный в самом начале
	return outputStr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string exp;
	cout << "Введите мат. выражение: ";
	cin >> exp;
	cout << "Переведя данное выражение в обратную польскую натацию поулчим: " << ConvertToPostFixNotation(exp, '&') << endl;

	return 0;
}