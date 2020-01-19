#pragma once

/// <summary>
/// ��������� ������ ���������� B-������ 
/// </summary>
template<typename T>
struct B2Tree
{
	/// <summary>
	/// ���-�� ������������
	/// </summary>
	int N;

	/// <summary>
	/// ��������� �� ���. ������ ������������
	/// </summary>
	B2Tree* inherits;

	/// <summary>
	/// �������������� ����� ����
	/// </summary>
	T data;
};