# 第二章

## 例题

**例 2-8【多项式求值】** 考虑多项式 $P(x) = \sum\limits_{i=0}^n c_i x^i$。如果 $c_i \neq 0$，那么 $P(x)$ 是一个 $n$ 阶多项式。对于给定的 $x$ 的值来计算 $P(x)$ 的值。

- 程序 2-3 多项式计算

```c++
    template <typename T>
    T polyEval(T coeff[], int n, const T &x)
    {
        //计算 n 阶多项式在点 x 处的值，系数为 coeff[0:n]
        T y = 1, value = coeff[0];
        for (int i = 1; i <= n; i++)
        {
            y *= x;
            value += y * coeff[i];
        }

        return value;
    }
```

这个程序进入 for 循环的次数为 $n$，每次循环执行 1 次加法和 2 次乘法。总共执行了 $n$ 次加法和 $2n$ 次乘法。  
利用 Horner 法则的分解式计算一个多项式：
$$P(x) = (\cdots (((c_n*x + c_{n-1})*x + c_{n-2})*x + c_{n-3})*x \cdots)*x + c_0$$

- 程序 2-4 利用 Horner 法则的多项式计算

```c++
    template <typename T>
    T horner(T coeff[], int n, const T &x)
    {
        //计算 n 阶多项式在点 x 处的值，系数为 coeff[0:n]
        T value = coeff[n];
        for (int i = 1; i <= n; i++)
        {
            value = value * x + coeff[n - i];
        }

        return value;
    }
```

程序 2-4 的时间复杂度是 $n$ 次加法和 $n$ 次乘法，因此应该比程序 2-3 更快。

**例 2-9【名次计算（ranking）】** 一个元素在一个序列中的 **名次（rank）** 是所有比它小的元素的个数加上在它左边出现的与它相等的元素的个数。程序 2-5 的函数 rank 计算数组 a 的各个元素的名次。

- 程序 2-5 名次计算

```c++
    template <typename T>
    void rank(T a[], int n, int r[])
    {
        //给数组 a[0:n-1] 的 n 个元素排名次
        //结果在 r[0:n-1] 中返回
        for (int i = 0; i < n; i++)
            r[i] = 0; //初始化

        //比较所有元素对
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[j] <= a[i])
                    r[i]++;
                else
                    r[j]++;
            }
        }
    }
```

rank 函数的时间复杂度根据 a 的元素的比较次数来估算，总的比较次数为 $1+2+3+\cdots+n-1=n(n-1)/2$。

**例 2-10【按名次排序（rank sort）】** 数组 a 的元素一旦由程序 2-5 计算出名次，就可以按照名次来排序。  

- 程序 2-6 利用附加数组的计数排序

```c++
    template <typename T>
    void rerange(T a[], int n, int r[])
    {
        //使用一个附加数组 u 将数组排序
        T *u = new T[n];

        //把 a 中的元素移到 u 中正确的位置
        for (int i = 0; i < n; i++)
            u[r[i]] = a[i];

        //把 u 中元素移回 a
        for (int i = 0; i < n; i++)
            a[i] = u[i];

        delete[] u;
    }
```

**例 2-11【选择排序（selection sort）】** 首先找到最大的元素，把它移动到 a[n-1]。然后在剩下的 n-2 个元素中找到最大的，把它移动到 a[n-2]。如此进行下去，直到剩下一个元素。这种排序方法称为 **选择排序**。

- 程序 2-7 选择排序

```c++
    template <typename T>
    int indesOfMax(T a[], int n)
    {
        //查找数组 a[0:n-1] 的最大元素
        if (n <= 0)
            throw "n must be > 0";
        int indexOfMax = 0;
        for (int i = 1; i < n; i++)
            if (a[indexOfMax] < a[i])
                indexOfMax = i;

        return indexOfMax;
    }

    template <typename T>
    void selectionSort(T a[], int n, int T[])
    {
        //给数组 a[0:n-1] 的 n 个元素排序
        for (int size = n; size > 1; size--)
        {
            int j = indesOfMax(a, size);
            std::swap(a[j], a[size - 1]);
        }
    }
```

**例 2-12【冒泡排序（bubble sort）】** 这是一种简单的排序方法。

- 程序 2-8 一次冒泡过程

```c++
    template <typename T>
    void bubble(T a[], size_t n)
    {
        //把 a[0:n-1] 中最大的元素移到右边
        for (size_t i = 0; i < n - 1; i++)
            if (a[i] > a[i + 1])
                std::swap(a[i], a[i + 1]);
    }
```

- 程序 2-9 冒泡排序

```c++
    template <typename T>
    void bubbleSort(T a[], size_t n)
    {
        //对 a[0:n-1] 使用冒泡排序
        for (size_t i = n; i > 1; i--)
            bubble(a, i);
    }
```

- 测试程序

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
    void bubble(T a[], size_t n)
    {
        //把 a[0:n-1] 中最大的元素移到右边
        for (size_t i = 0; i < n - 1; i++)
            if (a[i] > a[i + 1])
                std::swap(a[i], a[i + 1]);
    }

    template <typename T>
    void bubbleSort(T a[], size_t n)
    {
        //对 a[0:n-1] 使用冒泡排序
        for (size_t i = n; i > 1; i--)
            bubble(a, i);
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
            N = 1000;
        }
        int *a = new int[N];
        const int min = -100, max = 100;
        randomFill(a, N, min, max);

        steady_clock::time_point start, end;
        duration<double> timeSpan;
        start = steady_clock::now();

        bubbleSort(a, N);

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
        return 0;
    }
```

**例 2-15【再看按名次排序】** 不使用额外的数组进行按名次排序

- 程序 2-11 原地重排数组元素

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

**例 2-16【再看选择排序】** 当序列已经有序时，及时终止程序

- 程序 2-12 及时终止的选择排序

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
    void selectionSort(T a[], size_t n)
    {
        bool sorted = false;
        for (size_t size = n; !sorted && (size > 1); size--)
        {
            size_t indexOfMax = 0;
            sorted = true;

            //查找最大元素
            for (size_t i = 1; i < size; i++)
            {
                if (a[indexOfMax] <= a[i])
                    indexOfMax = i;
                else
                    sorted = false; //无序
            }
            swap(a[indexOfMax], a[size - 1]);
        }
    }

    //测试相应函数
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
        const int min = 0, max = N * 10;
        randomFill(a, N, min, max);

        steady_clock::time_point start, end;
        duration<double> timeSpan;
        start = steady_clock::now();

        selectionSort(a, N);

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

        return 0;
    }
```

**例 2-17【再看冒泡排序】** 如果在一次冒泡过程中没有发生元素交换，则说明数组已经有序，应该改及时终止排序。

- 程序 2-13 及时终止的冒泡排序

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
    bool bubble(T a[], size_t n)
    {
        //把数组 a[0:-1] 中的最大元素移到最右边

        bool swapped = false; //到目前为止未交换
        for (size_t i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        return swapped;
    }

    template <typename T>
    void bubbleSort(T a[], size_t n)
    {
        for (size_t i = n; i > 1 && bubble(a, i); i--);
    }

    //测试相应函数
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
        const int min = 0, max = N * 10;
        randomFill(a, N, min, max);

        steady_clock::time_point start, end;
        duration<double> timeSpan;
        start = steady_clock::now();

        bubbleSort(a, N);

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

        return 0;
    }
```

**例 2-18【插入排序】** 对于有 $n$ 个元素的数组，可以从由第一个元素构成的单元素数组开始，不断实施插入操作。

- 程序 2-15 一种插入排序

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
    //----------------------------------------------------------------

    template <typename T>
    void insertionSort(T a[], size_t n)
    {
        //对数组 a[0:n-1] 实施插入排序
        for (size_t i = 1; i < n; ++i)
        {
            T t = a[i];
            size_t j;
            for (j = i - 1; j >= 0 && t < a[j]; --j)
                a[j + 1] = a[j];
            a[j + 1] = t;
        }
    }

    //----------------------------------------------------------------
    //测试相应函数
    int main(int argc, char **argv)
    {
        size_t N = 0;
        if (argc == 2)
        {
            //从传入的参数设定数组大小
            N = std::atoi(argv[1]);
        }
        else
        {
            //默认数组大小
            N = 1000 * 10;
        }
        int *a = new int[N];
        const int min = 0, max = N * 10;
        randomFill(a, N, min, max);

        steady_clock::time_point start, end;
        duration<double> timeSpan;
        start = steady_clock::now();

        insertionSort(a, N);

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

        return 0;
    }
```
