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