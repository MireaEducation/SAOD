#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

#include "BankAccount.h"
#include "HashTable.h"

void PrintHeaderTable(string h1, string h2, string h3);

void CreateTable(HashTable<int, BankAccount*> *table, int n);

void Print(HashTableNodePair <int, BankAccount*> *mass, int n);
