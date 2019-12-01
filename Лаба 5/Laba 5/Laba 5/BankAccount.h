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
}BankAccount;

