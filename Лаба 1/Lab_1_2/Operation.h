#pragma once
#include "Telephone.h"
#include <malloc.h>

//Создает список из n узлов
Telephone* createList(Telephone* head, int n);

//Выводит на экран список list из n узлов
void showList(Telephone* list);

//Находит узел с заданынм номером отправтеля
Telephone* findNode(Telephone* current, int phoneFrom);

//Возвращает указатель на последний элемент списка
Telephone* getLastNode(Telephone* current);

//Добавляет в конец списка новый узел
void addNode(Telephone* lastNode, Telephone* nodeNew);

//Возвращает первые 4 цифры телефона
int getNum(int phone);

//Меняет значения элементов списка
void swapDataNode(Telephone* node1, Telephone* node2);

//Сортирует список по первым четырем цифрам телефона
void sortList(Telephone* head);

//Возвращает ссылку на последний узел, содержащий соответствующий номер отправителя
Telephone* getLastNodeForDelete(Telephone* head, int phoneFrom);

//Удаляет выбранный узел
void deletChoosenNode(Telephone* head);

//Возвращает суммарную длиельность разговора по указанному номеру отправителя
int sumTimeTell(Telephone* head, int phoneFrom);