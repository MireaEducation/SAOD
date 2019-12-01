#include "Operation.h"

void CreateTable(HashTable<int, BankAccount*> *table, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		BankAccount* account = new BankAccount();
		table->Add(account->account_number, &account);
	}
	cout << "Хэш-таблицу сформирована" << endl;
}
