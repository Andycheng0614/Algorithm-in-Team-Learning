#include <iostream>
using namespace std;

/**
 * 查找两个有序数组中的第k小的数
 * @param  a 数组a头指针
 * @param  m 数组a的元素个数
 * @param  b 数组b的头指针
 * @param  n 数组b的元素个数
 * @param  k 查找第k小的数
 * @return   输出第k小的数
 */
double findKth(int a[], int m, int b[], int n, int k)
{
    // 假设m小于n，如果大于，交换即可
    if (m > n)
        return findKth(b, n, a, m, k);
    if (m == 0)
        return b[k - 1];
    if (k == 1)
        return min(a[0], b[0]);

    // 把k分成两部分
    int pa = min(k / 2, m);
    int pb = k - pa;
    if (a[pa - 1] < b[pb - 1]) // a中所有值必定都小于第k小的数
        return findKth(a + pa, m - pa, b, pb, pb);
    else if (a[pa - 1] > b[pb - 1]) // b中所有值必定小于第k小的数
        return findKth(a, pa, b + pb, n - pb, pa);
    else
        return a[pa - 1];
}

/**
 * [findMedianSortedArrays description]
 * @param  A 数组A头指针
 * @param  m 数组A的元素个数
 * @param  B 数组B的头指针
 * @param  n 数组B的元素个数
 * @return   两个有序数组的中值
 */
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int total = m + n;
    if (total & 0x1) // 如果有奇数个数，中值就是中间值
        return findKth(A, m, B, n, total / 2 + 1);
    else // 如果有偶数个数，中值就是中间两个值的平均值
        return (findKth(A, m, B, n, total / 2)
                + findKth(A, m, B, n, total / 2 + 1)) / 2;
}

int main()
{
    const int m(13); // 定义常数
    const int n(4); // 定义常数

    int A[m] = {1, 2, 3, 6, 8, 9, 11, 12, 13, 14, 15, 16, 17};
    int B[n] = {4, 5, 7, 10};

    cout << findMedianSortedArrays(A, m, B, n) << endl;

    return 0;
}
