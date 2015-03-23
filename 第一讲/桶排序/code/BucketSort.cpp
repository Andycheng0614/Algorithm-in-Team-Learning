#include "BucketSort.h"
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int value; // 值
	Node *next; // 指向Node的指针

	Node(int val) // 析构函数
	{
		this->value = val;
		this->next = NULL;
	}
};


/************************************************************************/
/*函数名：BucketSort()
/*功  能：桶排序
/*返回值：无
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

		if (NULL == p) // 为空，插入
		{
			pNode[numWithShift] = pNewNode;
		}
		else if (A[i] <= p->value) // 不为空但小于等于第一个节点，插入
		{
			pNode[numWithShift] = pNewNode;
			pNewNode->next = p;
		}
		else // 不为空，且大于第一个节点
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
