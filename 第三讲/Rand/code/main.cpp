#include <iostream>

using namespace std;

/**
* 产生[0, N) 的随机数
* N ：unsigned int 输入
*   ：unsigned int 输出
*/
unsigned int RandN(unsigned int N)
{
    return 0 == N ? 0 : rand() % N;
}

/**
* 根据能产生随机数[0, N) 的函数设计能产生随机数[0, m) 的函数
* M ：unsigned int 输入
* N ：unsigned int 输入
* func：函数句柄，输入 unsigned int，输出 unsigned int
* ：unsigned int 输出
*/
unsigned int RandmUsingRandn(unsigned int M, unsigned int N, unsigned int(*func)(unsigned int))
{
    if (0 == M)
    {
        return 0;
    }

    if (0 == N)
    {
        return 0;
    }

    if (M <= N)
    {
        // 取小于 N 的 M 的最大倍数，提高效率
        int iNDivM = N / M;
        int iTimesM = iNDivM * M;

        int iRandN = func(N); // 截尾能保证前面的概率依然相同
        while (iRandN >= iTimesM)
        {
            iRandN = func(N);
        }
        return iRandN % M;
    }
    if (M > N)
    {
        // 取小于 N^2 的 M 的最大倍数，提高效率
        int iN2DivM = N * N / M;
        int iTimesM = iN2DivM * M;

        // 有 Rand(N * N) = Rand(N) * N + Rand(N)
        // 同理可以推出 Rand(N^3), Rand(N^4)
        int iRandN2 = func(N) * N + func(N); // 截尾能保证前面的概率依然相同
        while (iRandN2 >= iTimesM)
        {
            iRandN2 = func(N) * N + func(N);
        }

        return iRandN2 % M;
    }
}
int main()
{
    const int M(15);
    int iCount[M] = { 0 };
    for (int i = 0; i < 1500000; i++)
    {
        iCount[RandmUsingRandn(M, 7, RandN)]++;
    }

    for (int i = 0; i < M; i++)
    {
        cout << iCount[i] << "  ";
    }

    return 0;
}
