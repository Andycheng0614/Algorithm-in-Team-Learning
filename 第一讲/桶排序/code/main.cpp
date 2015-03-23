#include <iostream>
#include <vector>
#include <time.h>

#include "GenRandN.h"
#include "BucketSort.h"
#include "IsOrder.h"

using namespace std;

const int N(200000); // ���峣��
const int maxNum(0x7FFFFFFF); // ���峣��

int main()
{
	vector<int> dataA(N, 0);
	GenRandN(&dataA[0], N, maxNum); // �����������

	clock_t startTime, endTime;
	startTime = clock();

	BucketSort(&dataA[0], N); // Ͱ����

	endTime = clock();
	cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

	cout << IsOrder(&dataA[0], N) << endl; // �ж�����Ƿ�����
	cout << dataA[N-1] << endl;

	return 0;
}