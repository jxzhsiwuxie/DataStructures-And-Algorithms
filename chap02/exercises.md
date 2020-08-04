# 第二章

## 练习

1\. 给出两种以上的原因说明程序分析员为什么对程序的空间复杂度感兴趣？

- 如果一个程序要运行在一个多用户计算机系统中，我们需要知道该程序所需的内存的大小。

- 在任何一个计算机系统上运行程序，都需要知道是否有足够的内存来运行程序。

- 一个问题可能有若干个解决方案，它们对内存的需求各不相同。比如，对于你的计算机来说，某个 C++ 编译器仅需要 1MB 的空间，而另一个 C++ 编译器可能需要 4MB 的空间。如果你的计算机内存少于 4MB，你只能选择 1MB 的编译器。如果较小的编译器和较大的编译器有相同的作用，那么即使用户计算机有更多内存，他也宁愿使用较小的编译器，以便把更多的内存留作它用。

- 利用空间复杂度，我们可以估算一个程序所能解决的问题最大可以是什么规模。例如，一个电路模拟程序需要模拟具有 c 个原件和 w 个连线的电路。需要 $10^6 + 100(c+w)$ 字节的内存。如果可用内存的总量是 $5.01 \times 10^8$ 字节，那么最大可以模拟 $c+w \leq 5\,000\,000$ 的电路。

2\. 给出两种以上的原因说明程序分析员为什么对程序的时间复杂度感兴趣？

- 有些计算机需要用户提供程序运行时间的上限，一旦达到这个上限，程序将被强制结束。你可以简单的指定时间上限为几千年，但是你的程序如果因为数据问题陷入死循环，你可要为机时付出巨额资金。因此我们希望时间上限稍大于所期望的运行时间。

- 正在开发的程序可能需要一个令人满意的响应时间。例如，所有交互式程序都必须如此。

- 如果一个问题有多种解决方案，那么具体采用哪一种方案，主要根据这些方案的性能差异。

3\. 如果采用两种 C++ 编译器编译一个程序，那么生成的代码长度相同还是不同？

很大概率上来说是不同的。

4\. 可能还有很多因素影响程序的空间复杂度，请列举出来。

例如编写程序时采用何种数据结构来存储数据。

5\. 使用图 2-2 的数据来计算以下的数组所需要的字节数：
1）double y[3]
2）int matrix[10][100]
3）double x[100][5][20]
4）float z[10][10][10][5]
5）bool a[2][3][4]
6）long b[3][3][3][3]

- 图 2-2 在 32 位计算机上 C++ 数据类型通常占用的空间

|类型 |空间大小（字节数）|范围|
|:---|:---|:---|
|bool          |1   |${\rm \{true, false\}}$               |
|char          |1   |$[-128, 127]$                         |
|unsigned char |1   |$[0, 255]$                            |
|short         |2   |$[-2^{15}, 2^{15} - 1]$               |
|unsigned short|2   |$[0, 2^{16} - 1]$                     |
|long          |4   |$[-2^{31}, 2^{31} - 1]$               |
|unsigned long |4   |$[0, 2^{32} - 1]$                     |
|int           |4   |$[-2^{31}, 2^{31} - 1]$               |
|unsigned int  |4   |$[0, 2^{32} - 1]$                     |
|float         |4   |$\pm 3.4 E \pm38$（7 位）              |
|double        |8   |$\pm 1.7 E \pm308$（15 位）            |
|long double   |10  |$\pm 1.2 E \pm 4392$（19 位）          |
|pointer       |2   |（near， \_cs， \_ds， \_es，\_ss 指针）|
|pointer       |4   |（far，huge 指针）                      |

1）24 字节
2）4000 字节
3）80000 字节
4）20000 字节
5）24 字节
6）324 字节

6\. 程序 2-2 是在数组元素 a[0:n-1] 中查找元素 x 的递归函数 rSequentialSearch。如果找到 x 则返回 x 在 a 中的位置，否则返回 -1。计算 $S_p(n)$ 和 $S_{\rm rSequentialSearch}(n)$。

- 程序 2-2 顺序查找的递归算法

```c++
    template <typename T>
    int rSequentialSearch(T a[], int n, const T &x)
    {
        //在数组 a[0:n-1] 中查找元素 x
        //如果找到则返回该元素的位置，否则返回 -1
        if (n < 1)
            return -1;
        if (a[n - 1] == x)
            return n - 1;
        return rSequentialSearch(a, n - 1, x);
    }
```

程序 rSequentialSearch 是一个递归函数，递归深度为 $max\{1, n\}$，每一层递归，函数需要保存数组 a（4 字节）、变量 n（4 字节），所以 $S_{\rm rSequentialSearch}(n) = 8*max\{1, n\}$。

7\. 编写一个非递归函数来计算 $n!$（见例 1-1）.并和程序 1-29 的递归函数比较空间复杂度。
>例 1-1 就是程序 1-29？？？

```c++
    int rFactorial(int n)
    {
        if (n <= 1)
            return 1;
        return n * rFactorial(n - 1);
    }

    int factorial(int n)
    {
        if (n <= 1)
            return 1;
        int res = 1;
        for (int i = 1; i <= n; ++i)
            res *= i;
        return res;
    }
```

递归版本，其递归深度为 $max\{1, n\}$，每层递归需要占用空间 8 字节，所以 $S_r(n) = 8*max\{1, n\}$；非递归版本只需要保存 8 字节（i 与 res）。

8\. 根据例 2-8 的分析，要计算多项式 $3x^4 + 4x^3 + 5x^2 + 6x + 7$，程序 2-3 需要做 4 次加法和 8 次乘法，程序 2-4 需要做 4 次加法和 4 次乘法。请在 $x = 2$ 的情况下把这些加法和乘法一一表示出来，而且把每次的加数和乘数也显示出来。

对于多项式 $3x^4 + 4x^3 + 5x^2 + 6x + 7$，数组 coeff 为 [7,6,5,4,3]。按照程序 2-3

|进入 for 循环测次数|运算|y 的值|value 的值|
|:--|:--|--:|--:|
|0  |y = 1; value = 7                 |1    |7     |
|1  |y = 1 \* 2; vaule = 7 + 2 \* 6   |2    |19    |
|2  |y = 2 \* 2; value = 19 + 4 \* 5  |4    |39    |
|3  |y = 4 \* 2; value = 39 + 8 \* 4  |8    |71    |
|4  |y = 8 \* 2; value = 71 + 16 \* 3 |16   |119   |

按照程序 2-4
|进入 for 循环测次数|运算|value 的值|
|:--|:--|--:|
|0  |value = 3            |3     |
|1  |vaule = 3 \* 2 + 4   |10    |
|2  |value = 10 \* 2 + 5  |25    |
|3  |value = 25 \* 2 + 6  |56    |
|4  |value = 56 \* 2 + 7  |119   |

9\. 对于数组 a[0:8] = [3,2,6,,5,9,4,7,1,8]，计算所有元素的名次，并存于数组 r（见例 2-9）。

```c++
    #include <iostream>
    #include <cstddef>

    using std::cout;
    using std::endl;
    using std::size_t;

    template <typename T>
    void rank(T a[], size_t n, size_t r[])
    {
        for (size_t i = 0; i < n; ++i)
            r[i] = 0;

        for (size_t i = 1; i < n; ++i)
        {
            for (size_t j = 0; j < i; ++j)
                if (a[j] > a[i])
                    ++r[j];
                else
                    ++r[i];
        }
    }

    int main()
    {

        const size_t N = 9;
        size_t r[N];
        int a[N] = {3, 2, 6, 5, 9, 4, 7, 1, 8};

        rank(a, N, r);

        for (size_t i = 0; i < N; ++i)
            cout << r[i] << " ";
        cout << endl;

        return 0;
    }
```

10\. 假设对数组 a[0:6]=[3,2,6,5,9,4,8] 实施程序 2-7 的选择排序，请画出类似于图 2-4a 的图。

11\. 假设对数组 a[0:6]=[3,2,6,5,9,4,8] 实施程序 2-8 的冒泡排序，请画出类似于图 2-4b 的图。

12\. 假设对数组 a[0:6]=[3,2,6,5,9,4,8] 实施程序 2-9 的冒泡排序，请画出类似于图 2-4c 的图。

13\. 假设在有序数组 a[0:6]=[1,2,4,6,7,8,9] 中插入 3，请画出类似于图 2-5a 的图，显示程序 2-10 的插入过程。

14\. 数组 a[0:8]=[g,h,i,f,c,a,d,b,e]，按名次排序结果 r[0:8]=[6,7,8,5,2,0,3,1,4]，请画出类似于图 2-5b 和 2-5c 的图，显示原地重排函数（见程序 2-11）的排序过程。

15\. 1）使用及时终止选择排序（见程序 2-12），对数组 a[0:9]=[9,8,7,6,5,4,3,2,1,0] 排序，画出类似于图 2-6a 的图，显示排序过程。
2）对数组 a[0:8]=[8,4,5,2,1,6,7,3,0] 重复过程 1）

16\. 使用及时终止冒泡排序（见程序 2-13），对数组 a[0:9]=[4,2,6,7,1,0,9,8,5,3] 排序，画出类似于 2-6b 的图，显示排序过程。

17\. 使用插入排序（见程序 1-14），对数组 a[0:9]=[4,2,6,7,1,0,9,8,5,3] 排序，画出类似于图 2-6c 的图，显示排序过程。

18\. 在函数 sum（见程序 1-30）的 for 循环中，执行了多少次加法（即调用 increment）?
n 次（程序 1-30 中没有 increment）

19\. 函数 factorial（见程序 1-29）执行了多少次乘法？
n-1 次。

20\. 创建一个输入数组 a，是函数 rearrange（见程序 2-11）执行 n-1 次元素交换和 n-1 次名次交换。

a[3] = [1,2,0]  
a[4] = [1,2,3,0]
a[n] = [1,2,...,n-1,0]

21\. 函数 matrixAdd（见程序 2-21）对数组元素执行了多少次加法？

- 程序 2-21 矩阵的加法

```c++
    template <typename T>
    void matrixAdd(T **a, T **b, T **c, int numberOfRows, int numberOfColumns)
    {
        //将矩阵 a 和 b 相加得到矩阵 c
        for (int i = 0; i < numberOfRows; i++)
            for (int j = 0; j < numberOfColumns; j++)
                c[i][j] = a[i][j] + b[i][j];
    }
```

共执行 ${\rm numberOfRows \times numberOfColumns}$ 次加法。

22\. 函数 transpose（见程序 2-19）共执行了多少次交换？

$$
\sum_{i=0}^{i=rows-1}(rows-i-1) = \frac{rows(rows-1)}{2}
$$

次交换。

23\. 试确定函数 squareMatrixMultiply（见程序 2-22）在两个 $n\times n$ 矩阵相乘时执行了多少次乘法？

- 程序 2-22 两个 nxn 的矩阵的乘法

```c++
    template <typename T>
    void squareMatrixMultiply(T **a, T **b, T **c, size_t n)
    {
        //将 nXn 矩阵 a 和 b 相乘得到矩阵 c
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                T sum = 0;
                for (size_t k = 0; k < n; ++k)
                    sum += a[i][k] * b[k][j];
                c[i][j] = sum;
            }
        }
    }
```

执行了 $n^3$ 次的乘法。

24\. 试确定函数 matrixMultiply（见程序 2-23）在实现一个 mxn 矩阵与一个 nxp 矩阵相乘时执行了多少次乘法？

- 程序 2-23 mxn 矩阵与 nxp 矩阵的乘法

```c++
    template <typename T>
    void matrixMultiply(T **a, T **b, T **c, size_t m, size_t n, size_t p)
    {
        //将一个 mxn 矩阵 a 和一个 nxp 矩阵 b 相乘得到矩阵 c
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < p; ++j)
            {
                T sum = 0;
                for (size_t k = 0; k < n; ++k)
                    sum += a[i][k] * b[k][j] c[i][j] = sum;
            }
        }
    }
```

执行了 $(m \times n \times p)$ 次乘法，

25\. 确定函数 permutations（见程序 1-32）执行了多少次交换操作？
令 $n = m - k$，此时执行交换的次数为 $C_n$，可得到 $C_0 = 0$ 以及下面的递推公式：

$$
\begin{aligned}
C_n &= \left. (n+1)(C_{n-1} + 2)   \right.\\
    &= \left. (n+1)C_{n-1} + 2(n+1)    \right.\\
    &= \left. (n+1)(nC_{n-2} + 2n) + 2(n+1)    \right.\\
    &= \left. (n+1)nC_{n-2} + 2(n+1)n + 2(n+1)    \right.\\
    &= \left. \cdots    \right.  \\
    &= \left. (n+1)n\times\cdots\times 3C_1 + 2(n+1)n\times\cdots\times3 + \cdots + 2(n+1)    \right.\\
    &= \left. (n+1)n\times\cdots\times 3\times 2 C_0 + (n+1)n\times\cdots\times 3\times 4 + 2(n+1)n\times\cdots\times3 + \cdots + 2(n+1)    \right.\\
    &= \left. 2(n+1)n\times\cdots\times 3\times 2 + 2(n+1)n\times\cdots\times3 + \cdots + 2(n+1)n + 2(n+1)    \right.\\
    &= \left. 2(n+1)!\big(\frac{1}{1!} + \frac{1}{2!} + \cdots + \frac{1}{n!} \big)    \right.
\end{aligned}
$$

最终得到交换的次数与特征值 $n = m - k$ 的关系 $C_n = 2(n+1)!(\frac{1}{1!} + \frac{1}{2!} + \cdots + \frac{1}{n!}) $。

26\. 函数 minmax（见程序 2-24）是查找数组 a 的最大元素和最小元素。令 n 为实例特征。试问 a 的元素之间有多少次元素比较？程序 2-25 是另一个查找方法。在最好和最坏的情况下的比较次数分别是多少？试分析两个函数之间的相对性能。

- 程序 2-14 查找最大和最小元素

```c++
    template <typename T>
    bool minmax(T a[], size_t n, size_t &indexOfMin, size_t &indexOfMax)
    {
        //在 a[0:n-1] 中确定最小和最大的元素的位置
        if (n < 1)
            return false;

        indexOfMin = indexOfMax = 0;
        for (size_t i = 1; i < n; ++i)
        {
            if (a[indexOfMin] > a[i])
                indexOfMin = i;
            if (a[indexOfMax] < a[i])
                indexOfMax = i;
        }

        return true;
    }
```

- 程序 2-25 查找最大和最小元素的另一个函数

```c++
template <typename T>
bool minmax(T a[], size_t n, size_t &indexOfMin, size_t &indexOfMax)
    {
        //在 a[0:n-1] 中确定最小和最大的元素的位置
        if (n < 1)
            return false;

        indexOfMin = indexOfMax = 0;
        for (size_t i = 1; i < n; ++i)
        {
            if (a[indexOfMin] > a[i])
                indexOfMin = i;
            else if (a[indexOfMax] < a[i])
                indexOfMax = i;
        }

        return true;
    }
```

程序 2-24 只要 $n\geq 1$ 则需要比较 $2(n-1)$ 次。  
程序 2-25 最好的情况下也就是数组按照降序排列的话，只需要比较 $(n-1)$ 次，最差的情况也就是数组按照升序排列，则也需要比较 $2(n-1)$ 次。

27\. 在递归函数 rSequentialSearch（见程序 2-2）中，数组 a 的元素与 x 有多少次比较？

在数组 a 非空的时候，最好的情况下，只需要做一次比较；最差的情况下需要做 n 次比较。

28\. 程序 2-26 是另一个迭代式顺序搜索函数。在最坏情况下，x 与 a 的元素有多少次比较？与程序 2-1 的比较次数对比，哪一个函数运行得更快？为什么？

- 程序 2-26 另一个顺序搜索函数

```c++
    template <typename T>
    size_t sequentialSearch(T a[], size_t n, const T &x)
    {
        //在无序表 a[0:n-1] 中查找 x
        //如果找到，返回位置，否则返回 -1
        a[n] = x;
        size_t i;
        for (i = 0; a[i] != x; i++)
            ;
        if (i == n)
            return -1;
        return i;
    }
```

相比于程序 2-1 for 循环的条件部分每次需要比较两次，程序 2-26 的 for 循环条件部分每次只需要比较一次，显然程序 2-26 更快。

29\.1）在程序 2-27 的所有需要的位置插入 stepCount 的计数语句。  
&emsp; 2）删除不必要的语句，简化 1）的程序。简化后的程序和 1）的程序所计算出的 stepCount 值相同。  
&emsp; 3）假设 stepCount 的初始值为 0，当程序结束时它的值为多少？
&emsp; 4）采用频率方法分析程序 2-27 的步数，列出步数表。

|语句|s/e|频率|总步数|
|:--|:--:|:--:|:--:|
|void d(int x[], int n)        |0   |0   |0     |
|{                             |0   |0   |0     |
|    int i = 0;                |1   |1   |1     |
|    for (i = 0; i < n; i += 2)|3   |n+1 |3(n+1)|
|        x[i] += 2;            |1   |n   |n     |
|    i = 1;                    |1   |1   |1     |
|    while (i <= n / 2)        |1   |n/2 |n/2   |
|    {                         |0   |0   |0     |
|        x[i] += x[i + 1];     |1   |n/2 |n/2   |
|        i++;                  |1   |n/2 |n/2   |
|    }                         |0   |0   |0     |
|}                             |0   |0   |0     |
|总计                          |    |    |15n/2 + 5|

30\. ~ 33\. 略

34\. 试比较在最坏情况下，函数 selectionSort（见程序 2-12），函数 insertionSort（见程序 2-15）以及函数 bubbleSort（见程序 2-13）的元素移动次数。利用程序（2-11）完成按名次排序。

程序 2-12 在最坏情况下的元素移动次数为：n-1
程序 2-13 在最坏情况下的元素移动次数为：n(n-1)/2
程序 2-15 在最坏情况下的元素移动次数为：n(n+1)/2

```c++
    #include <iostream>
    #include <cstddef>
    #include <chrono>
    #include <algorithm>
    #include <random>

    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    using std::chrono::steady_clock;

    using std::cout;
    using std::endl;
    using std::size_t;
    using std::swap;

    //给数组填充随机数
    template <typename T>
    void randomFill(T arr[], size_t n, const T &min, const T &max)
    {
        static std::uniform_int_distribution<T> u(min, max);
        static std::default_random_engine e(steady_clock::now().time_since_epoch().count());
        for (size_t i = 0; i < n; ++i)
            arr[i] = u(e);
    }
    template <typename T>
    void rank(T a[], size_t n, size_t r[])
    {
        //给数组 a[0:n-1] 的 n 个元素排名次
        //结果在 r[0:n-1] 中返回
        for (size_t i = 0; i < n; i++)
            r[i] = 0; //初始化

        //比较所有元素对
        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (a[j] <= a[i])
                    r[i]++;
                else
                    r[j]++;
            }
        }
    }

    template <typename T>
    void rerange(T a[], size_t n, size_t r[])
    {
        //原地重排使数组有序
        size_t t = 0;
        for (size_t i = 0; i < n; i++)
            while (r[i] != i)
            { //交换对应位置的元素到正确的位置
                t = r[i];
                swap(a[i], a[t]);
                swap(r[i], r[t]);
            }
    }

    int main(int argc, char **argv)
    {
        size_t N = 0;
        if (argc == 2)
        {
            N = std::atoi(argv[1]);
        }
        else
        {
            N = 1000 * 10;
        }
        int *a = new int[N];
        size_t *r = new size_t[N];
        const int min = 0, max = N * 10;
        randomFill(a, N, min, max);

        steady_clock::time_point start, end;
        duration<double> timeSpan;
        start = steady_clock::now();

        rank(a, N, r);

        rerange(a, N, r);

        cout << "a[0] = " << a[0]
            << ", a[" << N / 3 << "] = " << a[N / 3]
            << ", a[" << N / 2 << "] = " << a[N / 2]
            << ", a[" << 2 * N / 3 << "] = " << a[2 * N / 3]
            << ", a[" << N - 1 << "] = " << a[N - 1]
            << endl;

        end = steady_clock::now();
        timeSpan = duration_cast<milliseconds>(end - start);
        cout << "----------------" << endl;
        cout << "Used time: " << timeSpan.count() << " ms" << endl;
        delete[] a;
        delete[] r;
        return 0;
    }
```

35\. 在最坏的情况下，一个程序所需要的运行时间和内存一定同时都是最大的吗？证明你的结论。
显然不是的。具体要看最坏与最好的定义，例如

```c++
    vector<int>getNumbersBigger(int a[], int n, int sz){
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            if(a[i] > sz)
                tmp.push_back(a[i]);
        }
        return tmp;
    }
```

如果说最坏的情况是数组 a 中所有元素都不满足条件，则所需的内存是最小的。

36\. 重复替换以求解下列方程（见例 2-20）。

1）$t(n) =
    \begin{cases}
        2          &n=0 \\
        2 + t(n-1) &n\gt 0
    \end{cases}
$  

2）$t(n) =
    \begin{cases}
        0          &n=0 \\
        1          &n=1 \\
        1 + t(n-2) &n\gt 1
    \end{cases}
$  

3）$t(n) =
    \begin{cases}
        0           &n=0 \\
        2n + t(n-1) &n\gt 0
    \end{cases}
$  

4）$t(n) =
    \begin{cases}
        1           &n=0 \\
        2*t(n-1)    &n\gt 0
    \end{cases}
$  

5）$t(n) =
    \begin{cases}
        1           &n=0 \\
        3*t(n-1)    &n\gt 0
    \end{cases}
$  

1）$t(n) = 2(n+1)$  
2）$t(n) =
    \begin{cases}
        n/2           &n\mod 2 = 0 \\
        (n+1)/2       &n\mod 2 = 1
    \end{cases}
$
3）$t(n) = n^2 + n + 2$
4）$t(n) = 2^n$
5）$t(n) = 3^n$
