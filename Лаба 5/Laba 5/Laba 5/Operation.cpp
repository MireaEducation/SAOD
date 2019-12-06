#include "Operation.h"
#include <string>

void PrintHeaderTable(string h1, string h2, string h3)
{
	cout << ".";
	for (size_t i = 0; i < 60; i++) cout << "_";
	cout << ".";

	cout << endl << "|" << setw(20) << left 
		<< h1 << setw(20) << left 
		<< "|" + h2 << setw(20) 
		<<"|" + h3 << setw(20) << "|" << endl;

	cout << ".";
	for (size_t i = 0; i < 60; i++) cout << "_";
	cout << "."<<endl;
}

void CreateTable(HashTableOpenAddress *table, int n)
{
	BankAccount* account = nullptr;
	for (size_t i = 0; i < n; i++)
	{
		account = new BankAccount();
		table->Add(account->account_number, account);
	}
	cout << "Хэш-таблицу сформирована" << endl;
}

void Print(HashTableNodePair<int, BankAccount*> *mass, int n)
{
	PrintHeaderTable("INDEX", "KEY", "VALUE");

	for (size_t i = 0; i < n; i++)
	{
		if (!mass[i].GetIsVoid())
		{
			cout << endl << "|" << setw(20) << left
				<< i << setw(20) << left
				<< "|" + to_string(mass[i].GetKey()) << setw(20)
				<< "|" + mass[i].GetValue()->FIO << setw(20) << "|" << endl;
			cout << ".";  for (size_t i = 0; i < 60; i++) cout << "_"; cout << ".";
			cout << endl;
		}
		else {
			cout << endl << "|" << setw(20) << left
				<< i << setw(20) << left
				<< "|NULL" << setw(20)
				<< "|NULL" << setw(20) << "|" << endl;
			cout << ".";  for (size_t i = 0; i < 60; i++) cout << "_"; cout << ".";
			cout << endl;
		}
	}
}
