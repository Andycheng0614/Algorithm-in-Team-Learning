#include <iostream>
#include <vector>
#include <time.h>

#include "GenRandN.h"
#include "BucketSort.h"
#include "IsOrder.h"

using namespace std;

const int N(200000); // 定义常数
const int maxNum(0x7FFFFFFF); // 定义常数

int main()
{
	vector<int> dataA(N, 0);
	GenRandN(&dataA[0], N, maxNum); // 产生随机数组

	clock_t startTime, endTime;
	startTime = clock();

	BucketSort(&dataA[0], N); // 桶排序

	endTime = clock();
	cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

	cout << IsOrder(&dataA[0], N) << endl; // 判断输出是否有序
	cout << dataA[N-1] << endl;

	return 0;
}