#pragma once
#include "HashTable.h"
#include "BankAccount.h"

void CreateTable(HashTable<int, BankAccount*> *table, int n);