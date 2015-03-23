#include <iostream>
#include <vector>
#include <time.h>

#include "GenRandN.h"
#include "IsOrder.h"
#include "RadixSort.h"

using namespace std;

const int N(50000000); // 定义常数
const int maxNum(0x7FFFFFFF); // 定义常数

int main()
{
	vector<int> dataA(N, 0);
	vector<int> dataB(N, 0);
	vector<int> dataC(N, 0);

	GenRandN(&dataA[0], N, maxNum); // 产生随机数组

	clock_t startTime, endTime;

	startTime = clock();
	RadixSort(&dataA[0], &dataB[0], N); // 计数排序
	endTime = clock();
	cout<< "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

	startTime = clock();
	RadixSortOpt(&dataA[0], &dataC[0], N); // 计数排序
	endTime = clock();
	cout<< "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

	// 判断排序是否准确
	cout << IsOrder(&dataB[0], N) << endl;
	cout << IsOrder(&dataC[0], N) << endl;

	cout << dataB[N-1] << " " << dataC[N-1] << endl;
	return 0;
}