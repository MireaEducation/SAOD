#include "Operation.h"

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
	cout << "KEY# " << setw(40) << left << "VALUE" << endl;

	for (size_t i = 0; i < n; i++)
	{
		if (!mass[i].GetIsVoid())
			cout << mass[i].GetKey() << setw(40) << left;
		else
			cout << "NULL" << setw(40) << left;
	}
	cout << endl;

	for (size_t i = 0; i < n; i++)
	{
		if (!mass[i].GetIsVoid()) {
			BankAccount* obj = mass[i].GetValue();
			cout << obj->FIO.c_str() << setw(40) << left;
		}
		else
			cout << "NULL" << setw(40) << left;
	}
	cout << endl;
	
}
