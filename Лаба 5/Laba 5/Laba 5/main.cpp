#include <windows.h>
#include "Operation.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;
	int n_old = 0, n_new = 0;
	HashTableOpenAddress *table = nullptr;

	while (answer != 0) {
		system("cls");
		cout << "Лабораторная работа №5 Бикеева А. И. Вариант 2\n\n";
		cout << "Тема: Хеширование для организации быстрого поиска данных\n";
		cout << "Цель: Получить навыки по разработке хеш таблиц\n";
		cout << "\nМеню\n";
		cout << "1) Сформировать/пересоздать хэш-таблицу из n элементов\n";
		cout << "2) Вывести данные клиента по номеру карты\n";
		cout << "3) Вывести хэш-таблицу\n";
		cout << "4) Добавить инф. о новом клиенте хэш-таблицу\n";
		cout << "5) Удалить инф. о клиенте с указанным номером карты\n";
		cout << "6) Произвести рэхэширвоание\n";
		cout << "0) Выход\n";
		cout << "\nВаш выбор: ";
		while ((!(cin >> answer)) || cin.get() != '\n') {     //делаем проверку на ввод букв   
			cout << "ERROR\n";
			cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
			cin.sync();//Удалим данные из буффера
			cout << "Повторите ввод : ";
		}
		system("cls");
		cout << "Лабораторная работа №5 Бикеева А. И. Вариант 2\n\n";
		try
		{

			switch (answer)
			{
			case 1: {
				cout << "Укажите размер хэш-таблицы: ";
				cin >> n_old;
				table = new HashTableOpenAddress(n_old);
				cout << "Таблица успешно создана\n";
				system("pause");
				break;
			}
			case 2: {
				if (table)
				{
					cout << "Введите номер карты клиента: ";
					int num = 0;
					cin >> num;
					int i = table->FindNode(num);
					if (i != -1) {
						HashTableNodePair<int, BankAccount*>* mass = table->GetMass();
						cout << "ФИО: " << mass[i].GetValue()->FIO << endl;
						cout << "Адрес: " << mass[i].GetValue()->address << endl;
					}
					else {
						cout << "Клиента с указанным номером - нет в таблице\n";
					}
				}
				else {
					cout << "Хэш-таблица пустая" << endl;
				}
				system("pause");
				break;
			}
			case 3: {
				if (table)
				{
					Print(table->GetMass(), n_old);
				}
				else {
					cout << "Хэш-таблица пустая" << endl;
				}
				system("pause");
				break;
			}
			case 4: {
				if (table && table->GetVoidCount())
				{
					BankAccount* account = nullptr;
					account = new BankAccount();
					table->Add(account->account_number, account);

					Print(table->GetMass(), n_old);

					cout << "Данные успешно добавлены" << endl;
				}
				else {
					cout << "Хэш-таблица полностью заполнена\nДля повтора требуется пересоздать её" << endl;
				}
				system("pause");
				break;
			}
			case 5: {
				if (table && table->GetVoidCount() != n_old)
				{
					cout << "Введите номер карты клиента: ";
					int num = 0;
					cin >> num;
					if (table->Remove(num))
						cout << "Информация о клиенте успешно удалена" << endl;
					else
						cout << "Данного клиента нет в хэш-таблице" << endl;
				} else {
					cout << "Хэш-таблица пустая" << endl;
				}
				system("pause");
				break;
			}
			case 6: {
				if (table && table->GetVoidCount() != n_old)
				{
					cout << "Укажите новый размер хэш-таблицы: ";
					cin >> n_new;
					HashTableOpenAddress *tableNew = new HashTableOpenAddress(n_new);
					tableNew->CopyMass(table->GetMass(), n_old);

					table = tableNew;

					cout << "Рэхэширование проведено успешно\n";
					n_old = n_new;
					system("pause");
					break;
				}
				else {
					cout << "Хэш-таблица пустая" << endl;
				}
				system("pause");
				break;
			}
			case 0: {
				system("pause");
				break;
			}
			default:
				break;
			}
		}
		catch (const std::exception& exc)
		{
			cout << "ERROR: " << exc.what() << endl;
			system("pause");
		}
	}
	return 0;
}