#pragma once

#include <iostream>
#include "RedBlackTree.h"

using namespace std;

void CreateTree(RedBlackTree* root, int n);

void PrintTree(BinaryTreeNode* p, int level);

/// <summary>
/// � ������� ������������� ������ ������ - ���������� ����� ���� �������� �����
/// </summary>
int InOrderTravelRL(BinaryTreeNode* root, int sum);

/// <summary>
/// ���������� ��������� �� ������������ ������� ������
/// </summary>
/// <param name="root">������ ������</param>
/// <returns></returns>
BinaryTreeNode* FindMax(BinaryTreeNode* root);

/// <summary>
/// ���������� ��������� �� ������� � �������� data
/// </summary>
/// <param name="root">��������� �� ������ ������</param>
/// <param name="data">�������� �������� ���� ������</param>
/// <returns></returns>
BinaryTreeNode* FindNode(BinaryTreeNode* root, char data);