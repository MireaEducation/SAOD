#include "Operation.h"

void PrintHeaderTable(string h1, string h2)
{
	cout << ".";
	for (size_t i = 0; i < 40; i++) cout << "_";
	cout << ".";

	cout << endl << "|" << setw(20) << left << h1 << setw(20) << left << "|" + h2 << setw(20) << "|" << endl;

	cout << ".";
	for (size_t i = 0; i < 40; i++) cout << "_";
	cout << "."<<endl;
}

void CreateTable(HashTable<int, BankAccount*> *table, int n)
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
	PrintHeaderTable("KEY", "VALUE");

	for (size_t i = 0; i < n; i++)
	{
		if (!mass[i].GetIsVoid())
		{
			cout << "|" << setw(20) << left << mass[i].GetKey() << setw(20) << left << "|" + mass[i].GetValue()->FIO << setw(20) << "|" << endl;
			cout << ".";  for (size_t i = 0; i < 40; i++) cout << "_"; cout << ".";
			cout << endl;
		}
		else {
			cout << "|" << setw(20) << left << "NULL" << setw(20) << left << "|NULL" << setw(20) << "|" << endl;
			cout << ".";  for (size_t i = 0; i < 40; i++) cout << "_"; cout << ".";
			cout << endl;
		}
	}
}
