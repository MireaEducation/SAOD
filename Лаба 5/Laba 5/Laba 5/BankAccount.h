#pragma once

/// <summary>
/// Структура, описывающая клиента банка
/// </summary>
typedef struct Node
{
	/// <summary>
	/// Номер счета в банке
	/// </summary>
	int account_number;

	/// <summary>
	/// ФИО - клиента банка
	/// </summary>
	string FIO;

	/// <summary>
	/// Адрес проживания клиента
	/// </summary>
	string address;

	Node()
	{
		cout << "Введите номер счета в банке: ";
		cin >> this->account_number;

		cout << "Введите ФИО: ";
		cin >> this->FIO;

		cout << "Введите адрес проживания: ";
		cin >> this->address;
	}

	Node(const Node& obj) {
		this->account_number = obj.account_number;
		this->address = obj.address;
		this->FIO = obj.FIO;
	}
}BankAccount;

