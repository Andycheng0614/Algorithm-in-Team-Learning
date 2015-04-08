#include <iostream>

using namespace std;

/**
 * [trap description]
 * @param  A 数组A头指针
 * @param  n 数组A的元素个数
 * @return   int
 */
int trap(int A[], int n)
{
    int iMax = 0; // 标记最高处
    for (int i = 0; i < n; i++)
    {
        if (A[iMax] < A[i])
        {
            iMax = i;
        }
    }

    int iWater = 0; // 统计水量
    int iLeftMax = 0; // 标记左侧最高处
    for (int i = 1; i < iMax; i++)
    {
        if (A[i] < A[iLeftMax])
        {
            iWater += A[iLeftMax] - A[i];
        }
        else
        {
            iLeftMax = i;
        }
    }

    int iRightMax = n - 1; // 标记右侧最高处
    for (int i = n - 2; i > iMax; i--)
    {
        if (A[i] < A[iRightMax])
        {
            iWater += A[iRightMax] - A[i];
        }
        else
        {
            iRightMax = i;
        }
    }

    return iWater;
}

int main()
{
    const int N(3);
    int A[N] = {4,2,3};

    cout << trap(A, N) << endl;

    return 0;
}
