# 第一章

## 例题

**例 1-1** 阶乘程序

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    int factorial(int n) {
        if (n <= 1)
            return 1;
        else
            return n * factorial(n - 1);
    }
```

**例 1-2** 模板函数 sum 对数组元素 a[0] 至 a[n-1]（简记为 a[0:n-1]）求和。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    template <typename T>
    T sumV1(T a[], int n) {
        T theSum = 0;
        for (int i = 0; i < n; ++i)
            theSum += a[i];

        return theSum;
    }

    template <typename T>
    T sumV2(T a[], int n) {
        if (n < 1)
            return 0;

        return sumV2(a, n - 1) + a[n - 1];
    }

    int main() {
        const int N = 10;
        int ia[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        cout << sumV1(ia, N) << endl;
        cout << sumV2(ia, N) << endl;

        return 0;
    }
```

**例 1-3** 使用递归函数生成全排列。

```c++
    #include <algorithm>
    #include <iostream>
    #include <iterator>

    using std::copy;
    using std::cout;
    using std::endl;
    using std::ostream_iterator;
    using std::swap;

    template <typename T>
    void permutations(T list[], int k, int m) {
        //生成 list[k:m] 的所有排列
        if (k == m) {  //此时只有一个排列，输出它
            copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
            cout << endl;
            return;
        } else {  //此时 list[k:m] 有多个排列，递归地生成它们
            for (int i = k; i <= m; ++i) {
                swap(list[k], list[i]);
                permutations(list, k + 1, m);
                swap(list[k], list[i]);
            }
        }
    }
    //list[0:2] => k=0, m=2
    //list[1:2] => k=1,m=2

    int main() {
        const int NUM = 3;
        char ca[NUM] = {'a', 'b', 'c'};

        permutations(ca, 0, NUM - 1);

        return 0;
    }
```

**例 1-6【二次方程求解】** 一个 $x$ 的 **二次函数**（quadratic function）形式如下：
$$ax^2 + bx + c$$
其中 $a$、$b$、$c$ 的值是实数，而且 $a \neq 0$。每个二次函数都有两个 **根**，且按如下公式计算：
$$ \frac{-b \pm \sqrt{b^2 - 4ac}}{2a} $$

- 程序 1-36 计算并输出粗一个二次方程 $ax^2 + bx + c = 0$ 的根

```c++
    #include <iostream>
    #include <ctime>
    #include <iomanip>
    #include <cmath>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::sqrt;

    void outputRoots(const double &a, const double &b, const double &c)
    {
        double d = b * b - 4 * a * c;
        if (d > 0)
        {
            double sqrtd = sqrt(d);
            cout << "There are two real roots\n"
                << "x1 = " << (-b + sqrtd) / (2 * a) << "\n"
                << "x2 = " << (-b - sqrtd) / (2 * a) << endl;
        }
        else if (d == 0)
            cout << "There is only one distinct root\n"
                << "x = " << -b / (2 * a) << endl;
        else
            cout << "The roots are complex\n"
                << "x1 = " << -b / (2 * a) << " + " << sqrt(-d) / (2 * a) << "i \n"
                << "x2 = " << -b / (2 * a) << " - " << sqrt(-d) / (2 * a) << "i" << endl;

        cout << "-----------------------" << endl;
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        outputRoots(1, -5, 6);
        outputRoots(1, 6, 9);
        outputRoots(2, 4, 10);

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```
