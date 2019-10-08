#pragma once
#include "Telephone.h"
#include <malloc.h>

//Создает список из n узлов
Node* createList(Node* head, int n);

//Выводит на экран список list из n узлов
void showList(Node* list);

//Находит узел с заданынм номером отправтеля
Node* findNode(Node* current, int phoneFrom);

//Возвращает указатель на последний элемент списка
Node* getLastNode(Node* current);

//Добавляет в конец списка новый узел
void addNode(Node* lastNode, Node* nodeNew);