#include "BucketSort.h"
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int value; // ֵ
	Node *next; // ָ��Node��ָ��

	Node(int val) // ��������
	{
		this->value = val;
		this->next = NULL;
	}
};


/************************************************************************/
/*��������BucketSort()
/*��  �ܣ�Ͱ����
/*����ֵ����
/************************************************************************/
bool BucketSort(int *A, const int SIZE)
{
	Node **pNode = (Node **)malloc(sizeof(Node *) * 256);
	if (NULL == pNode)
		return false;

	memset(pNode, 0, sizeof(Node *) * 256);

	int numWithShift = 0;
	Node *p = NULL;
	Node *pLast = NULL;
	Node *pNewNode = NULL;

	for (int i = 0; i < SIZE; ++i)
	{
		numWithShift = A[i] >> 24;
		p = pNode[numWithShift];

		pNewNode = new Node(A[i]);
		if (NULL == pNewNode)
			return false;

		if (NULL == p) // Ϊ�գ�����
		{
			pNode[numWithShift] = pNewNode;
		}
		else if (A[i] <= p->value) // ��Ϊ�յ�С�ڵ��ڵ�һ���ڵ㣬����
		{
			pNode[numWithShift] = pNewNode;
			pNewNode->next = p;
		}
		else // ��Ϊ�գ��Ҵ��ڵ�һ���ڵ�
		{
			while (NULL != p->next)
			{
				if (A[i] > p->next->value)
					p = p->next;
				else
					break;
			}
			pNewNode->next = p->next;
			p->next = pNewNode;
		}
	}

	for (int i = 0, k = 0; i < 256; ++i)
	{
		p = pNode[i];

		while (NULL != p)
		{
			A[k++] = p->value;
			p = p->next;
		}
	}

	return true;
}
