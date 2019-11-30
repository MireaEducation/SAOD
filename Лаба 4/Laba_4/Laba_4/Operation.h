#pragma once

#include <iostream>
#include "RedBlackTree.h"

using namespace std;

void CreateTree(RedBlackTree* root, int n);

void PrintTree(BinaryTreeNode* p, int level);

/// <summary>
/// С помощью симметричного обхода дерева - возвращает сумму всех значений узлов
/// </summary>
int InOrderTravelRL(BinaryTreeNode* root, int sum);

/// <summary>
/// Возвращает указаетль на максимальный элемент дерева
/// </summary>
/// <param name="root">Корень дерева</param>
/// <returns></returns>
BinaryTreeNode* FindMax(BinaryTreeNode* root);