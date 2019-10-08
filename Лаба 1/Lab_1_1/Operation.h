#pragma once
#include "Telephone.h"
#include <malloc.h>

//Создает список из n узлов
Telephone* createList(Telephone* head, int n);

//Выводит на экран список list из n узлов
void showList(Telephone* list);

//Находит узел с заданынм номером отправтеля
Telephone* findNode(Telephone* current, int phoneFrom);