#include "CountingSort.h"
#include "RadixSort.h"

#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/*��������GetNumberDigit
/*��  �ܣ���ȡ������ÿ�����ֵĵ�iλ����
/*����ֵ����
/************************************************************************/
bool GetNumberDigit(int *A, int *B, const int SIZE, unsigned int digit)
{
	int pow10[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
	if (digit > 10 | digit == 0)
		return 0;

	for (int i = 0; i < SIZE; ++i)
		B[i] = (A[i] / pow10[digit - 1]) % 10;

	return 1;
}

/************************************************************************/
/*��������RadixSort
/*��  �ܣ���������
/*����ֵ����
/************************************************************************/
void RadixSort(int *A, int *B, const int SIZE)
{
	vector<int> C(SIZE, 0); // �����м����
	vector<int> D(SIZE, 0); // �����м����

	for (int i = 0; i < SIZE; ++i)
		B[i] = A[i];

	for (int i = 1; i < 11; ++i)
	{
		if (i & 0x01 == 1)
		{
			GetNumberDigit(&B[0], &C[0], SIZE, i);
			CountingSort(&B[0], &D[0], &C[0], SIZE);
		}
		else
		{
			GetNumberDigit(&D[0], &C[0], SIZE, i);
			CountingSort(&D[0], &B[0], &C[0], SIZE);
		}
	}
}


/************************************************************************/
/*��������GetNumberDigit
/*��  �ܣ���ȡ������ÿ�����ֵĵ�iλ����
/*����ֵ����
/************************************************************************/
bool GetNumberDigitOpt(int *A, int *B, const int SIZE, unsigned int digit)
{
	unsigned int shift = 8 * (digit - 1);

	if (shift % 4 != 0  | shift > 24)
		return 0;

	for (int i = 0; i < SIZE; ++i)
		B[i] = (A[i] >> shift) & 0xFF;

	return 1;
}

/************************************************************************/
/*��������RadixSort
/*��  �ܣ���������
/*����ֵ����
/************************************************************************/
void RadixSortOpt(int *A, int *B, const int SIZE)
{
	vector<int> C(SIZE, 0); // �����м����
	vector<int> D(SIZE, 0); // �����м����

	for (int i = 0; i < SIZE; ++i)
		B[i] = A[i];

	for (int i = 1; i < 5; ++i)
	{
		if (i & 0x01 == 1)
		{
			GetNumberDigitOpt(&B[0], &C[0], SIZE, i);
			CountingSortOpt(&B[0], &D[0], &C[0], SIZE);
		}
		else
		{
			GetNumberDigitOpt(&D[0], &C[0], SIZE, i);
			CountingSortOpt(&D[0], &B[0], &C[0], SIZE);
		}
	}
}