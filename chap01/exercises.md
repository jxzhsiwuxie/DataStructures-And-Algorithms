# 第一章

## 练习

1\. 解释程序 1.7 的交换函数没有把形参 x 和 y 所对应的实参的值交换。如何修改代码使得实参的值得到交换？

* 因为该函数的参数是按值传递的，所以不会改变实参的值。
* 改为按引用传递即可

```c++
    void swap(int &x, int &y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
```

2\. 编写一个模板函数 count，返回值是数组 a[0:n-1] 中 value 出现的次数。测试你的代码。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    template <typename T, unsigned N>
    unsigned count(const T (&arr)[N], const T &value)
    {
        unsigned con = 0;

        for (T t : arr)
            if (t == value)
                ++con;

        return con;
    }

    int main()
    {

        int iarr[] = {3, 2, 1, 13, 2, 2, 13, 3, 12, 21, 3, 2};
        char carr[] = {'q', 'f', 'k', 's', 'a', 's', 's', 'n', 'a'};

        cout << count(iarr, 2) << endl;
        cout << count(carr, 'a') << endl;

        return 0;
    }
```

3\. 编写一个模板函数 fill，给数组 a[start:end-1] 赋值 value，测试你的代码。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    template <typename T>
    void fill(T *arr, unsigned start, unsigned end, T value)
    {
        for (auto it = arr + start; it != arr + end; ++it)
            *it = value;
    }

    int main()
    {
        int iarr[10] = {0};

        for (const int &i : iarr)
            cout << i << " ";
        cout << endl;

        fill(iarr, 2, 5, 100);

        for (const int &i : iarr)
            cout << i << " ";
        cout << endl;

        return 0;
    }
```

4\. 编写一个模板函数 inner_product，返回值是 $\sum_{i=0}^{n-1}a[i]*b[i]$，测试你的代码。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    template <typename T, unsigned N>
    unsigned inner_product(const T (&arr1)[N], const T (&arr2)[N]) {
        unsigned res = 0;
        for (auto i = 0; i != N; ++i)
            res += arr1[i] * arr2[i];

        return res;
    }

    int main() {
        int iarr1[] = {1, 2, 3, 4}, iarr2[] = {2, 3, 4, 5};

        cout << inner_product(iarr1, iarr2) << endl;

        return 0;
    }
```

5\. 编写一个模板函数 iota，使 a[i] = value + i；0 << i < n，测试你的代码。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    template <typename T, unsigned N>
    void iota(T (&arr)[N], T value) {
        for (auto i = 0; i < N; ++i)
            arr[i] = value + i;
    }

    int main() {
        int ia[10] = {0};

        for (const auto &i : ia)
            cout << i << " ";
        cout << endl;

        iota(ia, 10);

        for (const auto &i : ia)
            cout << i << " ";
        cout << endl;

        return 0;
    }
```

6\. 编写一个模板函数 is_sorted，，当且仅当 a[0:n-1] 有序时，返回值是 true。测试你的代码。

```c++
    #include <iostream>

    using std::boolalpha;
    using std::cout;
    using std::endl;
    using std::noboolalpha;

    template <typename T, unsigned N>
    bool is_sorted(const T (&arr)[N]) {
        for (unsigned i = 0; i != N - 1; ++i)
            if (arr[i] > arr[i + 1])
                return false;

        return true;
    }

    int main() {
        int ia1[] = {1, 3, 5, 6, 7, 8};
        int ia2[] = {5, 3, 2, 5, 7, 21, 1};

        cout << boolalpha << is_sorted(ia1) << endl;
        cout << is_sorted(ia2) << noboolalpha << endl;

        return 0;
    }
```

7\. 编写一个函数 mismatch，返回值是使不等式 a[i] != b[i] 成立的最小索引 i， 0 <= i < n。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    template <typename T, unsigned N>
    int mismatch(const T (&arr1)[N], const T (&arr2)[N]) {
        for (unsigned i = 0; i != N - 1; ++i)
            if (arr1[i] != arr2[i])
                return i;

        if (arr1[N - 1] != arr2[N - 1])
            return N - 1;

        return -1;
    }

    int main() {
        int ia1[] = {1, 2, 3, 4, 5, 6};
        int ia2[] = {1, 2, 3, 4, 5, 6};
        int ia3[] = {1, 2, 3, 4, 5, 7};

        cout << mismatch(ia1, ia2) << endl;
        cout << mismatch(ia1, ia3) << endl;

        return 0;
    }
```

8\. 下面的函数头使具有不同签名的函数么？为什么？

* 1） int abc(int a, int b,, int c);
* 2） float abc(int a, int b, int c);

不是。  
函数签名指的是函数的形参列表，包括形参数量、类型或者排列的不同。  
返回值不同但是签名相同的同名函数在同一个作用域下会造成编译错误。  

9\. 假设有一个程序包含了程序 1-1 和程序 1-2 的 abc 函数。下面的语句分别调用了哪一个 abc 函数？哪一条语句会出现编译错误？为什么？

* 1）cout << abc(1, 2, 3) << endl;
* 2）cout << abc(1.0F, 2.0F, 3.0F) << endl;
* 3）cout << abc(1, 2, 3.0F) << endl;
* 4）cout << abc(1.0, 2.0, 3.0) << endl;

1）调用 int abc(int a, int b, int c);
2）调用 float abc(float a, float b, float c);
3）二义性错误
4）1.0、2.0、3.0 默认都是 double 类型，从 double 转换成 float 与 从 double 转换为 int 的优先级是一样的，所以也会造成二义性错误。

10\. 修改程序 1-8，使抛出的异常类型是整型。如果 a、b、c 都小于 0，那么抛出的异常值是 1；如果 a、b、c 都等于 0，那么抛出的异常值是 2。否则没有异常。编写一个主函数，应用修改后的代码；若有异常抛出，则捕获异常；根据异常值输出信息。测试你的代码。  

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    int abc(int a, int b, int c) {
        if (a < 0 && b < 0 && c < 0)
            throw 1;
        if (a == 0 && b == 0 && c == 0)
            throw 2;

        return a + b * c;
    }

    int main() {
        try {
            cout << abc(1, 2, 3) << endl;
            cout << abc(-1, -2, -3) << endl;
        } catch (int e) {
            if (e == 1) {
                cout << "a、b、c 三个参数不能都小于 0" << endl;
            } else if (e == 2) {
                cout << "a、b、c 三个参数不能都等于 0" << endl;
            }
            return 1;
        }

        return 0;
    }
```

11\. 重做练习 2。不过当 n < 1 时，抛出类型为 char* 的异常。测试你的代码。

```c++
    #include <iostream>

    template <typename T, unsigned N>
    unsigned count(const T (&arr)[N], const T &value) {
        if (N < 1)
            throw "数组不能为空";

        unsigned con = 0;

        for (T t : arr)
            if (t == value)
                ++con;

        return con;
    }

    int main() {
        using std::cout;
        using std::endl;

        //没办法创建一个元素数量少于 1 的数组。

        int iarr[] = {3, 2, 1, 13, 2, 2, 13, 3, 12, 21, 3, 2};

        cout << count(iarr, 2) << endl;

        return 0;
    }
```

12\. 为 程序 make2dArray（程序 1-11）编写一个通用型算法，它的第三个参数不是一个整数 numberOfColumns，而是一维数组 rowSize，它创建一个二维数组，第 i 行的列数是 rowSize[i]。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    template <typename T>
    void make2dArray(T **&x, int numberOfRows, const int *rowSize) {
        //创建行指针
        x = new T *[numberOfRows];

        //为每一行分配空间
        for (int i = 0; i < numberOfRows; ++i)
            x[i] = new T[rowSize[i]];
    }

    template <typename T>
    void delete2dArray(T **&x, int numberOfRows) {
        //删除行数组空间
        for (int i = 0; i < numberOfRows; ++i)
            delete[] x[i];

        //删除行指针
        delete[] x;

        x = nullptr;
    }

    int main() {
        int **X;
        const int numberOfRows = 4;
        int rowSize[numberOfRows] = {1, 2, 3, 4};

        make2dArray(X, numberOfRows, rowSize);

        for (int i = 0; i < numberOfRows; ++i) {
            for (int j = 0; j < rowSize[i]; ++j)
                cout << X[i][j] << " ";

            cout << endl;
        }

        delete2dArray(X, numberOfRows);

        return 0;
    }
```

13\. 编写一个模板函数 changeLength1D，它将一个一维数组的长度从 oldLength 变为 newLength。函数首先分配一个新的、长度为 newLength 的数组，然后把原数组的前 ${\rm min\{oldLength, newLength\}}$ 个元素复制到新数组中，最后释放原数组所占用的空间。测试你的代码。

```c++
    #include <iostream>
    using std::cout;
    using std::endl;

    template <typename T>
    T *changeLength1D(T *&arr, int oldLength, int newLength) {
        T *newArr = new T[newLength];

        int len = oldLength < newLength ? oldLength : newLength;

        for (int i = 0; i < len; ++i)
            newArr[i] = arr[i];

        delete[] arr;
        arr = nullptr;

        return newArr;
    }

    int main() {
        int *ia1 = new int[3]{1, 2, 3};
        int *ia2 = new int[5]{1, 2, 3, 4, 5};

        cout << *(ia1 + 2) << ", " << *(ia1 + 3) << endl;
        cout << *(ia2 + 3) << ", " << *(ia2 + 4) << endl;

        ia1 = changeLength1D(ia1, 3, 4);
        ia2 = changeLength1D(ia2, 5, 4);

        cout << *(ia1 + 2) << ", " << *(ia1 + 3) << endl;
        cout << *(ia2 + 3) << ", " << *(ia2 + 4) << endl;

        return 0;
    }
```

14\. 编写一个函数 changeLength2D，它改变一个二维数组的大小（参见练习 13）.测试你的代码。

```c++
    #include <iostream>
    using std::cout;
    using std::endl;

    template <typename T>
    void make2dArray(T **&x, int numberOfRows, int numberOfColumns) {
        x = new T *[numberOfRows];

        for (int i = 0; i < numberOfRows; ++i)
            x[i] = new T[numberOfColumns];
    }

    template <typename T>
    void delete2dArray(T **&x, int numberOfRows) {
        for (int i = 0; i < numberOfRows; ++i)
            delete[] x[i];

        delete[] x;

        x = nullptr;
    }

    template <typename T>
    void changeLength2D(T **&arr, int oldRows, int oldColumns, int newRows, int newColumns) {
        int rows = oldRows < newRows ? oldRows : newRows;
        int cols = oldColumns < newColumns ? oldColumns : newColumns;

        T **newArr = new T *[newRows];
        make2dArray(newArr, newRows, newColumns);

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                newArr[i][j] = arr[i][j];

        delete2dArray(arr, oldRows);

        arr = newArr;
    }

    int main() {
        int **ia1;
        const int olr = 2, olc = 3, nr = 3, nc = 4;

        make2dArray(ia1, olr, olc);
        for (int i = 0; i < olr; ++i)
            for (int j = 0; j < olc; ++j)
                ia1[i][j] = i * j + i + j;

        for (int i = 0; i < olr; ++i) {
            for (int j = 0; j < olc; ++j)
                cout << ia1[i][j] << " ";
            cout << endl;
        }
        cout << "-------------------------" << endl;

        changeLength2D(ia1, olr, olc, nr, nc);

        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j)
                ia1[i][j] = i * j + i + j;

        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j)
                cout << ia1[i][j] << " ";
            cout << endl;
        }

        return 0;
    }
```

15\. 1）假设无符号长整型、无符号整型都占用 4 字节（所以这些类型的对象范围是 0~2^32 - 1），那么在程序 1-13 中，可容许的货币最大和最小值是多少？
2）在程序 1-13 中，假设美元和美分都改为整型，那么可容许的最大和最小值是多少？
3）在程序 1-16 的 add 中，为了确保从 currency 类型转换成 long int 类型时不会发生错误，a1 和 a2 最大可能的值应该是多少？

* 1）最大值是 $(2^{32} - 1)$  美元 $(2^{32} - 1)$ 美分，最小值是 $-(2^{32} - 1)$ 美元 $(2^{32} - 1)$ 美分
* 2）有符号整型范围 $-2^{31} \sim +2^{31}-1$，对于程序 1-13 来说，最大值是 $(2^{31} - 1)$ 美元 $(2^{31} - 1)$ 美分，最小值是 $-(2^{31} - 1)$ 美元 $(2^{31} - 1)$ 美分
* 3）如果 a1 和 a2 符号不同，只要 a1 和 a2 本身是 long 类型，则计算之后肯定还是 long；如果 a1 和 a2 都是负数，则 a1 和 a2 的绝对值之和不能超过 2^31；如果 a1 和 a2 都是正数，则 a1 和 a2 的和不能超过 $(2^{31} - 1)$

16\. 扩展程序 1-13 的类 currency，添加下列成员函数：
&emsp;&emsp;1）input() 从标准输入流中读取 currency 的值，然后赋给调用对象
&emsp;&emsp;2）subtract(x) 从调用对象中减去参数对象 x 的值，然后返回结果
&emsp;&emsp;3）percent(x) 返回一个 currency 类的对象，它的值是调用对象的 x%。x 的数据类型为 double。
&emsp;&emsp;4）multiply(x) 返回一个 currency 类的对象，它的值是调用对象和 double 型数 x 的乘积。
&emsp;&emsp;5）divide(x) 返回一个 currency 类的对象，它的值是调用对象除以 double 型数 x 的结果。
&emsp;&emsp;实现所有的函数，用适当的数据检验它们的正确性。

```c++
    //currency_v1.h
    #include <iostream>
    #include <string>

    class illegalParameterValue {
    public:
        illegalParameterValue() : message("Illegal parameter value") {}
        illegalParameterValue(const char *theMessage) : message(theMessage) {}
        void outputMessage() const { std::cout << message << std::endl; }

    private:
        std::string message;
    };

    enum signType { plus,
                    minus };

    class currency {
    public:
        currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);
        ~currency() {}

        void setValue(signType, unsigned long, unsigned int);
        void setValue(double);
        signType getSign() const { return sign; }
        unsigned long getDollars() const { return dollars; }
        unsigned int getCents() const { return cents; }
        currency add(const currency &) const;
        currency increment(const currency &);
        void output() const;

        void input();
        currency subtract(const currency &) const;
        currency percent(double) const;
        currency multiply(double) const;
        currency divide(double) const;

    private:
        signType sign;
        unsigned long dollars;
        unsigned int cents;
    };

    currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents) {
        setValue(theSign, theDollars, theCents);
    }

    void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
        if (theCents > 99)
            throw illegalParameterValue("Cents should be < 100");

        sign = theSign;
        dollars = theDollars;
        cents = theCents;
    }

    void currency::setValue(double theAmount) {
        if (theAmount < 0) {
            sign = minus;
            theAmount = -theAmount;
        }

        else
            sign = plus;
        dollars = (unsigned long)theAmount;
        cents = (unsigned int)((theAmount + 0.01 - dollars) * 100);
    }

    currency currency::add(const currency &x) const {
        long a1, a2, a3;
        currency result;

        a1 = dollars * 100 + cents;
        if (sign == minus)
            a1 = -a1;

        a2 = x.dollars * 100 + x.cents;
        if (x.sign == minus)
            a2 = -a2;

        a3 = a1 + a2;

        if (a3 < 0) {
            result.sign = minus;
            a3 = -a3;
        } else
            result.sign = plus;

        result.dollars = a3 / 100;
        result.cents = a3 - result.dollars * 100;

        return result;
    }

    currency currency::increment(const currency &x) {
        *this = add(x);
        return *this;
    }

    void currency::output() const {
        if (sign == minus)
            std::cout << "-";
        std::cout << "$" << dollars << ".";
        if (cents < 10)
            std::cout << "0";
        std::cout << cents;
    }

    void currency::input() {
        double amount;

        if (std::cin >> amount) {
            setValue(amount);
        } else
            throw illegalParameterValue("input error.");
    }

    currency currency::subtract(const currency &x) const {
        currency tmp = x;
        if (tmp.sign == plus)
            tmp.sign = minus;
        else
            tmp.sign = plus;

        return add(tmp);
    }

    currency currency::percent(double per) const {
        long amount = dollars * 100 + cents;
        currency result;

        if (sign == minus)
            amount = -amount;

        amount *= (per / 100);

        result.setValue(amount / 100);

        return result;
    }

    currency currency::multiply(double mult) const {
        long amount = dollars * 100 + cents;
        currency result;

        if (sign == minus)
            amount = -amount;

        amount *= mult;

        result.setValue(amount / 100);

        return result;
    }

    currency currency::divide(double div) const {
        if (div == 0.0)
            throw illegalParameterValue("divider must be not 0.");

        long amount = dollars * 100 + cents;
        currency result;

        if (sign == minus)
            amount = -amount;

        amount /= div;

        result.setValue(amount / 100);

        return result;
    }
```

```c++
    #include <iostream>

    #include "currency_v1.h"

    using std::cin;
    using std::cout;
    using std::endl;

    int main() {
        currency g, h;

        cout << "输入一个小数：";
        g.input();

        cout << "输入一个小数：";
        h.input();

        g.output();
        cout << "\n------------------------\n";

        h.output();
        cout << "\n------------------------\n";

        g.subtract(h).output();
        cout << "\n------------------------\n";

        g.percent(80.5).output();
        cout << "\n------------------------\n";

        g.multiply(3.8).output();
        cout << "\n------------------------\n";

        g.divide(6.7).output();

        return 0;
    }
```

17\. 使用程序 1-19 的代码完成练习 16。

```c++
    //currency_v2.h
    #include <iostream>
    #include <string>

    class illegalParameterValue {
    public:
        illegalParameterValue() : message("Illegal parameter value") {}
        illegalParameterValue(const char *theMessage) : message(theMessage) {}
        void outputMessage() const { std::cout << message << std::endl; }

    private:
        std::string message;
    };

    enum signType { plus,
                    minus };

    class currency {
    public:
        currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);
        ~currency() {}

        void setValue(signType, unsigned long, unsigned int);
        void setValue(double);
        signType getSign() const {
            if (amount < 0)
                return minus;
            else
                return plus;
        }
        unsigned long getDollars() const {
            if (amount < 0)
                return (-amount) / 100;
            else
                return amount / 100;
        }
        unsigned int getCents() const {
            if (amount < 0)
                return -amount - getDollars() * 100;
            else
                return amount - getDollars() * 100;
        }
        currency add(const currency &) const;
        currency increment(const currency &);
        void output() const;

        void input();
        currency subtract(const currency &) const;
        currency percent(double) const;
        currency multiply(double) const;
        currency divide(double) const;

    private:
        long amount;
    };

    currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents) {
        setValue(theSign, theDollars, theCents);
    }

    void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
        if (theCents > 99)
            throw illegalParameterValue("Cents should be < 100");

        amount = theDollars * 100 + theCents;

        if (theSign == minus)
            amount = -amount;
    }

    void currency::setValue(double theAmount) {
        if (theAmount < 0)
            amount = (long)((theAmount - 0.001) * 100);
        else
            amount = (long)((theAmount + 0.001) * 100);
    }

    currency currency::add(const currency &x) const {
        currency result;

        result.amount = amount + x.amount;

        return result;
    }

    currency currency::increment(const currency &x) {
        *this = add(x);
        return *this;
    }

    void currency::output() const {
        long theAmount = amount;
        if (theAmount < 0) {
            std::cout << "-";
            theAmount = -theAmount;
        }

        long dollars = theAmount / 100;
        std::cout << "$" << dollars << ".";

        int cents = theAmount - dollars * 100;
        if (cents < 10)
            std::cout << "0";
        std::cout << cents;
    }

    void currency::input() {
        double amount;

        if (std::cin >> amount) {
            setValue(amount);
        } else
            throw illegalParameterValue("input error.");
    }

    currency currency::subtract(const currency &x) const {
        currency tmp = x;
        tmp.amount = -tmp.amount;

        return add(tmp);
    }

    currency currency::percent(double per) const {
        currency result;

        result.setValue(amount * per / 100);

        return result;
    }

    currency currency::multiply(double mult) const {
        currency result;

        result.setValue(amount * mult);

        return result;
    }

    currency currency::divide(double div) const {
        if (div == 0.0)
            throw illegalParameterValue("divider must be not 0.");

        currency result;

        result.setValue(amount / div);

        return result;
    }
```

```c++
    #include <iostream>

    #include "currency_v2.h"

    using std::cin;
    using std::cout;
    using std::endl;

    int main() {
        currency g, h;

        cout << "输入一个小数：";
        g.input();

        cout << "输入一个小数：";
        h.input();

        g.output();
        cout << "\n------------------------\n";

        h.output();
        cout << "\n------------------------\n";

        g.subtract(h).output();
        cout << "\n------------------------\n";

        g.percent(80.5).output();
        cout << "\n------------------------\n";

        g.multiply(3.8).output();
        cout << "\n------------------------\n";

        g.divide(6.7).output();

        return 0;
    }
```

18\. 1）使用程序 1-22 完成练习 16。重载 >>、-、% 和 /。当重载 >> 时，将其声明为友元函数，不要定义公有输入函数来支持输入操作。
2）重载复制操作符 = 替代成员函数 setValue。形式为 operator=(int x) 的重载，把一个整数赋给一个 currency 类的对象，它替代了具有三个参数的成员函数 setValue，x 把符号、美元和美分都集中在一个整数里。形式为 operator=(double x) 的重载，替代的时仅有一个参数的成员函数 setValue。

```c++
    //currency_v3.h
    #include <iostream>
    #include <string>

    class illegalParameterValue {
    public:
        illegalParameterValue() : message("Illegal parameter value") {}
        illegalParameterValue(const char *theMessage) : message(theMessage) {}
        void outputMessage() const { std::cout << message << std::endl; }

    private:
        std::string message;
    };

    enum signType { plus,
                    minus };

    class currency {
        friend std::ostream &operator<<(std::ostream &, const currency &);
        friend std::istream &operator>>(std::istream &, currency &);

    public:
        currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);
        ~currency() {}

        signType getSign() const {
            if (amount < 0)
                return minus;
            else
                return plus;
        }
        unsigned long getDollars() const {
            if (amount < 0)
                return (-amount) / 100;
            else
                return amount / 100;
        }
        unsigned int getCents() const {
            if (amount < 0)
                return -amount - getDollars() * 100;
            else
                return amount - getDollars() * 100;
        }

        currency &operator=(int);
        currency &operator=(double);

        currency operator+(const currency &) const;
        currency operator+=(const currency &);

        currency operator-(const currency &) const;
        currency operator%(double) const;
        currency operator*(double) const;
        currency operator/(double) const;

    private:
        long amount;
    };

    currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents) {
        int x = theDollars * 100 + theCents;
        if (theSign == minus)
            x = -x;
        amount = x;
    }

    currency &currency::operator=(int x) {
        amount = x;
        return *this;
    }

    currency &currency::operator=(double theAmount) {
        if (theAmount < 0)
            amount = (long)((theAmount - 0.001) * 100);
        else
            amount = (long)((theAmount + 0.001) * 100);

        return *this;
    }

    currency currency::operator+(const currency &x) const {
        currency result;

        result.amount = amount + x.amount;

        return result;
    }

    currency currency::operator+=(const currency &x) {
        amount += x.amount;

        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const currency &item) {
        long theAmount = item.amount;
        if (theAmount < 0) {
            os << "-";
            theAmount = -theAmount;
        }

        long dollars = theAmount / 100;
        os << "$" << dollars << ".";

        int cents = theAmount - dollars * 100;
        if (cents < 10)
            os << "0";
        os << cents;

        return os;
    }

    std::istream &operator>>(std::istream &is, currency &item) {
        double amt;

        if (std::cin >> amt) {
            item = amt;
        } else
            throw illegalParameterValue("input error.");

        return is;
    }

    currency currency::operator-(const currency &x) const {
        currency tmp = x;
        tmp.amount = amount - tmp.amount;

        return tmp;
    }

    currency currency::operator%(double per) const {
        currency result;

        result.amount = amount * per / 100;

        return result;
    }

    currency currency::operator*(double mult) const {
        currency result;

        result.amount = amount * mult;

        return result;
    }

    currency currency::operator/(double div) const {
        if (div == 0.0)
            throw illegalParameterValue("divider must be not 0.");

        currency result;

        result.amount = amount / div;

        return result;
    }
```

```c++
    #include <iostream>

    #include "currency_v3.h"

    using std::cin;
    using std::cout;
    using std::endl;

    int main() {
        currency g, h;

        cout << "输入一个小数：";
        cin >> g;

        cout << "输入一个小数：";
        cin >> h;

        cout << g;
        cout << "\n------------------------\n";

        cout << h;
        cout << "\n------------------------\n";

        cout << g - h;
        cout << "\n------------------------\n";

        cout << g % 80.5;
        cout << "\n------------------------\n";

        cout << g * 3.8;
        cout << "\n------------------------\n";

        cout << g / 6.7;

        return 0;
    }
```

19\. 编写非递归程序计算 n!。测试你的代码。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    unsigned factorial(int n)
    {
        if (n <= 1)
            return 1;

        unsigned result = 1;
        for (int i = 1; i <= n; ++i)
            result *= i;

        return result;
    }

    int main()
    {

        cout << "-1! = " << factorial(-1) << endl;
        cout << "0! = " << factorial(0) << endl;
        cout << "10! = " << factorial(10) << endl;

        return 0;
    }
```

20\. 1）编写递归函数计算斐波那契数列（Fibonacci）F_n。测试你的代码。
2）证明对于 1）中编写的代码，当计算 F_n 且 n > 2 时，F_i 的计算多于一次。
3）编写非递归函数计算斐波那契数列（Fibonacci）F_n。对每一个斐波那契数，你的代码应该只计算一次。测试你的代码。

对于递归的情况，当 n > 2 时，最小取 n = 3，第一层计算了 fibonacciRecursive(1) 和 fibonacciRecursive(2)，第二层计算了 fibonacciRecursive(0) 和 fibonacciRecursive(1)，可以发现 fibonacciRecursive(1) 计算了两次。对于更一般的 F(n) = F(n - 2) + F(n - 1) = 2F(n-2) + F(n-3)，由于 n >= 3，所以递归至少要进行到这里才能结束，即 F(n-2) 至少要计算两次。

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    int fibonacciRecursive(int n)
    {
        if (n <= 1)
            return 1;

        return fibonacciRecursive(n - 2) + fibonacciRecursive(n - 1);
    }

    int fibonacciNonRecursive(int n)
    {
        int a = 0, b = 1, c = 1;
        if (n <= 1)
            return c;

        for (int i = 1; i < n; ++i)
        {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }


    int main()
    {

        cout << "F_0 = " << fibonacciRecursive(0) << "; " << fibonacciNonRecursive(0) << endl;
        cout << "F_1 = " << fibonacciRecursive(1) << "; " << fibonacciNonRecursive(1) << endl;
        cout << "F_2 = " << fibonacciRecursive(2) << "; " << fibonacciNonRecursive(2) << endl;
        cout << "F_3 = " << fibonacciRecursive(3) << "; " << fibonacciNonRecursive(3) << endl;
        cout << "F_4 = " << fibonacciRecursive(4) << "; " << fibonacciNonRecursive(4) << endl;
        cout << "F_5 = " << fibonacciRecursive(5) << "; " << fibonacciNonRecursive(5) << endl;

        return 0;
    }
```

21\. 考察在下面的公式（1-4）中定义的函数 f，其中 n 是非负整数。
$$
\textit{f}(n) =
\begin{cases}
    n/2                & n 是偶数 \\
    \textit{f}(3n + 1) & n 是奇数
\end{cases}\tag{1-4}
$$
&emsp;&emsp;1）使用公式（1-4）手算 f(5) 和 f(7)
&emsp;&emsp;2）确定函数的基础部分和递归部分。证明重复应用递归部分可以把等式右侧的 f 表达式转为基础部分。
&emsp;&emsp;3）编写一个 C++ 递归函数计算 f(n)。测试的代码。
&emsp;&emsp;4）使用 2）的证明编写 C++ 非递归函数计算 f(n)，不能使用循环。测试你的代码。

```c++
    #include <iostream>
    #include <cmath>

    using std::cout;
    using std::endl;
    using std::pow;

    long double Ackermann(long double i, long double j)
    {
        if (i < 1 || j < 1)
            throw "i and j must not less than 1.";

        if (i == 1 && j >= 1)
            return pow(2, j);

        if (i >= 2 && j == 1)
            return Ackermann(i - 1, 2);

        return Ackermann(i - 1, Ackermann(i, j - 1));
    }

    int main()
    {

        cout << Ackermann(1, 2) << endl;
        cout << Ackermann(2, 1) << endl;
        cout << Ackermann(2, 2) << endl;
        cout << Ackermann(3, 2) << endl;
        cout << Ackermann(2, 3) << endl;
        cout << Ackermann(2, 4) << endl;

        return 0;
    }
```

22\.[阿克曼函数（Ackermann's Function）] 公式（1-5）定义的是阿克曼函数。其中 i 和 j 是大于等于 1 的整数。
$$
A(i,j) =
\begin{cases}
    2^j                 & i = 1 和 j \ge 1  \\
    A(i-1, 2)           & i \ge 2 和 j = 1  \\
    A(i-1, A(i, j-1))   & i,j \ge 2
\end{cases}\tag{1-5}
$$
&emsp;&emsp;1）使用公式（1-5）手算 A(1,2)、A(2,1) 和 A(2,2)。
&emsp;&emsp;2）确定函数定义中的基础部分和递归部分。
&emsp;&emsp;3）编写 C++ 递归函数计算 A(i,j)。测试你的代码。

```c++
    #include <iostream>
    #include <cmath>

    using std::cout;
    using std::endl;
    using std::pow;

    long double Ackermann(long double i, long double j)
    {
        if (i < 1 || j < 1)
            throw "i and j must not less than 1.";

        if (i == 1 && j >= 1)
            return pow(2, j);

        if (i >= 2 && j == 1)
            return Ackermann(i - 1, 2);

        return Ackermann(i - 1, Ackermann(i, j - 1));
    }

    int main()
    {

        cout << Ackermann(1, 2) << endl;
        cout << Ackermann(2, 1) << endl;
        cout << Ackermann(2, 2) << endl;
        cout << Ackermann(3, 2) << endl;
        cout << Ackermann(2, 3) << endl;
        cout << Ackermann(2, 4) << endl;

        return 0;
    }

```

23\.[最大公约数（Greatest Common Divisor,GCD）] 当两个非负整数 x 和 y 都是 0 的时候，它们的最大公约数是 0。当两者至少有一个不为 0 的时候，它们的最大公约数是可以除尽二者的最大的整数。因此 gcd(0,0)=0，gcd(10,0)=gcd(0,10)=10，而 gcd(20,30)=10。求最大公约数的欧几里得算法（Euclid's Algorithm）是一个递归算法，据说出现在公元前 375 年，或许是最早的而递归算法实例。它的定义由下面的公式（1-6）给出
$$
gcd(x,y)=
\begin{cases}
    x                       & y = 0 \\
    gcd(y, x\, mod \,y)     & y \gt 0
\end{cases}\tag{1-6}
$$
在公式（1-6）中，mod 是模数运算子（modulo operator），它相当于 C++ 的求余操作符 %。x mod y 是 x/y 的余数。
&emsp;&emsp;1）用公式（1-6）手工计算 gcd(20,30) 和 gcd(112,42)。  
&emsp;&emsp;2）确定函数定义的基础部分和递归部分。证明反复应用递归部分何以把公式右侧的 gcd 表达式转变为基础部分的表达式。  
&emsp;&emsp;3）编写一个 C++ 递归函数计算 gcd(x,y)。测试你的代码。  

1. 手动计算 gcd(20,30) 与 gcd(112,42)

    $$
    \begin{aligned}
        gcd(20,30)=gcd(30,20)=gcd(20,10)=gcd(10,0)=10 \\
        gcd(112,42)=gcd(42,28)=gcd(28,14)=gcd(14,0)=14
    \end{aligned}
    $$

2. 基础部分是 $gcd(x,0)=x$，递归部分是 $gcd(x,y)=gcd(y, x\, mod \,y)$。

3. C++ 代码：

```c++
    #include <iostream>

    using std::cout;
    using std::endl;

    unsigned long gcd(unsigned long x, unsigned y)
    {
        if (x == 0 || y == 0)
            return x + y;

        return gcd(y, x % y);
    }

    int main()
    {
        cout << "gcd(0, 0) = " << gcd(0, 0) << endl;
        cout << "gcd(10, 0) = " << gcd(10, 0) << endl;
        cout << "gcd(0, 10) = " << gcd(0, 10) << endl;
        cout << "gcd(20, 30) = " << gcd(20, 30) << endl;
        cout << "gcd(112, 42) = " << gcd(112, 42) << endl;
        cout << "gcd(42, 112) = " << gcd(42, 112) << endl;

        return 0;
    }
```

24\.编写一个递归模板函数，确定元素 x 是否属于数组 a[0:n-1]。

```c++
    #include <iostream>
    #include <string>

    using std::cout;
    using std::endl;
    using std::string;

    template <typename T>
    bool inArray(const T *arr, const T &item, int start, int end)
    {
        if (start == end)
            return item == *(arr + start);

        return inArray(arr, item, start, (start + end) / 2) ||
            inArray(arr, item, (start + end) / 2 + 1, end);
    }

    int main()
    {
        int ia[] = {8, 3, 1, 80, 4, 80, 18, 10};
        string sa[] = {"abc", "bcd", "def", "fgh", "ijk"};

        cout << std::boolalpha;

        cout << "3 in ia: " << inArray(ia, 3, 0, 7) << endl;
        cout << "80 in ia: " << inArray(ia, 80, 0, 7) << endl;
        cout << "5 in ia: " << inArray(ia, 5, 0, 7) << endl;
        cout << "def in sa: " << inArray(sa, string("def"), 0, 4) << endl;
        cout << "aaa in sa: " << inArray(sa, string("aaa"), 0, 4) << endl;
        cout << std::noboolalpha;
        return 0;
    }
```

25\. [子集生成方法（Subset Generation）]编写一个 C++ 递归函数，输出 n 个元素的所有子集。例如，三个元素 {a, b, c} 的子集是 {}（空集），{a}，{b}，{c}，{ab}，{ac}，{bc}，{abc}。这些子集用 0/1 组成的代码序列来表示分别是 000，100，010，001，110，101，011，111（0 表示相应的元素不在子集中，1 表示相应的元素在子集中）。因此你的程序输出长度为 n 的 0/1 序列即可。

&emsp;&emsp;设 $E_n=\{e_1, e_2, ..., e_n\}$ 是 $n$ 个元素的集合，设 $S(E_n) = \Big\{\{\}, \{e_1\}, ..., \{e_1, e_2, ..., e_n\}\Big\}$ 是集合 $E_n$ 所有子集组成的集合。令 $S(E) \otimes e$ 表示单元素集合 $\{e\}$ 与集合 $E$ 所有的子集分别做并集得到的集合的集合（在 $S(E)$的每个元素，一个集合，中添加上元素 $e$）。例如 $S(E_2) \otimes e =\Big\{\{\}, \{e_1\}, \{e_2\}, \{e_1, e_2\}\Big\} \otimes  \{e\} = \Big\{\{e\}, \{e_1, e\}, \{e_2, e\}, \{e_1, e_2, e\}\Big\}$。  

&emsp;&emsp;当 $n = 0$ 时，$E_0 = \{\},\,S(E_0) = \Big\{\{\}\Big\}$，这是基础部分。当 $n \geq 1$ 时，$E_n=\{e_1, e_2, ..., e_n\},\,S(E_n) = S(E_{n-1}) \cup \big(S(E_{n-1}) \otimes e_n \big)$，这是递归部分。

&emsp;&emsp;另一方面，当 $n = 0$ 时，$E_0$ 元素个数为 $0$，$S(E_0)$ 的元素个数为 $1$，即空集的子集个数为 $1$，记为 $C_0 = 1$。当 $n \geq 1$ 时，由 $S(E_n) = S(E_{n-1}) \cup \big(S(E_{n-1}) \otimes e_n \big)$ 可以得到 $C_n = 2C_{n-1}$，这个关系明显可以得到 $S(E_n)$ 的元素个数 $C_n = 2^n$ 个。  

&emsp;&emsp;我们可以推论得到

1. $\otimes e$ 只能对集合的集合操作

2. 假设 $E_0$ 是一个空集，则 $S(E_0)\otimes e_1 \otimes e_2 = \big(S(E_0)\otimes e_1\big)\otimes e_2 $

3. 假设$E_m$ 和 $E_n$ 是两个分别含有 $n$ 和 $m$ 个元素的集合（$m,n \geq 0$），则有 $\big(S(E_m) \cup S(E_n) \big) \otimes e = \big(S(E_m) \otimes e \big)\cup \big(S(E_n) \otimes e \big)$

$$
S(E_n) =
\begin{cases}
    \big\{ \{\} \big\}                          & n = 0 \\
    \\
    S(E_{n-1}) \cup (S(e_{n-1}) \otimes e_n)    & n \geq 1
\end{cases}
$$

$$
\begin{aligned}
S(E_3) &= \left. S(E_2) \cup (S(E_2) \otimes e_3) \right. \\
       &= \left. (S(E_1) \cup (S(E_1) \otimes e_2)) \cup (S(E_1) \cup (S(E_1) \otimes e_2) \otimes e_3) \right. \\
       &= \left. (S(E_1) \cup (S(E_1) \otimes e_2)) \cup ((S(E_1) \otimes e_3) \cup (S(E_1) \otimes e_2 \otimes e_3)) \right. \\
       &= \left. \cdots \right. \\
       &= \left. S(E_0) \cup \big(S(E_0) \otimes e_1\big) \cup \big(S(E_0)\otimes e_2\big) \cup \big(S(E_0) \otimes e_1\otimes e_2\big) \cup \big(S(E_0)\otimes e_3\big) \right. \\
       &\quad\left. \cup \big(S(E_0)\otimes e_1 \otimes e_3\big) \cup \big(S(E_0)\otimes e_2 \otimes e_3\big) \cup \big(S(E_0)\otimes e_1 \otimes e_2 \otimes e_3\big)    \right.  \\
       &= \left. \Big\{\{\}, \{e_1\}, \{e_2\}, \{e_1, e_2\}, \{e_3\}, \{e_1, e_3\}, \{e_2, e_3\}, \{e_1, e_2, e_3\}\Big\}      \right.
\end{aligned}
$$

C++ 代码实现：

```c++
    #include <iostream>
    #include <bitset>
    #include <set>

    using std::bitset;
    using std::cout;
    using std::endl;
    using std::set;

    /*
    * @fullSet：元素个数为 N 的集合
    * @nth    ：每一层递归函数中集合中元素的个数（最外层情况下，nth == N）
    */
    template <unsigned long long N>
    void getSubset(bitset<N> &fullSet, unsigned long long nth)
    {
        //此时待分解的集合只剩下空集，将整个集合打印出来
        if (nth == 0)
        {
            cout << fullSet << endl;
            return;
        }
        else
        {
            //分解出第 n 个元素后剩下的集合的所有子集
            getSubset(fullSet, nth - 1);

            //分解出第 n 个元素后剩下的集合的所有子集每一个都添加了元素 e_n
            fullSet.set(nth - 1, true);
            getSubset(fullSet, nth - 1);

            //取消添加 e_n 对共享变量 set 的影响
            fullSet.set(nth - 1, false);
        }
    }

    /*
    * @fullSet  ：元素个数为 N 的集合
    * @nth      ：每一层递归函数中集合中元素的个数（最外层情况下，nth == N）
    * @container：用于存放排序后的子集的容器
    */
    template <unsigned long long N>
    void getSubset(
            bitset<N> &fullSet, unsigned long long nth, set<bitset<N>,
            bool (*)(const bitset<N> &, const bitset<N> &)> &container
        )
    {
        //此时待分解的集合只剩下空集，将整个集合打印出来
        if (nth == 0)
        {
            container.insert(fullSet);
            return;
        }
        else
        {
            //分解出第 n 个元素后剩下的集合的所有子集
            getSubset(fullSet, nth - 1, container);

            //分解出第 n 个元素后剩下的集合的所有子集每一个都添加了元素 e_n
            fullSet.set(nth - 1, true);
            getSubset(fullSet, nth - 1, container);

            //取消添加 e_n 对共享变量 set 的影响
            fullSet.set(nth - 1, false);
        }
    }

    //用于比较 bitset 的函数
    template <unsigned long long N>
    bool bitsetCompare(const bitset<N> &b1, const bitset<N> &b2)
    {
        if (b1.count() < b2.count())
            return true;
        else if (b1.count() == b2.count() && b1.to_ulong() < b2.to_ulong())
            return true;
        return false;
    }

    //将 bitset 数据转换为日常集合的形式
    template <typename T, unsigned long long N>
    void convertBitset(const T (&tArr)[N], const bitset<N> &bSet)
    {
        if (bSet.none())
            cout << "{}" << endl;
        else if (bSet.all())
        {
            cout << "{";
            for (int i = 0; i < N - 1; ++i)
                cout << tArr[i] << ", ";
            cout << tArr[N - 1] << "}" << endl;
        }
        else
        {
            auto total = bSet.count(), cnt = 0;
            cout << "{";
            for (int i = 0; i < N; ++i)
            {
                if (bSet.test(i))
                {
                    if (++cnt < total)
                        cout << tArr[i] << ", ";
                    else
                    {
                        cout << tArr[i] << "}" << endl;
                        break;
                    }
                }
            }
        }
    }

    int main()
    {
        const unsigned long long N = 4;
        bitset<N> iSet;
        set<bitset<N>, decltype(bitsetCompare<N>) *> setSet(bitsetCompare<N>);

        const char cArr[N] = {'a', 'b', 'c', 'd'};

        getSubset(iSet, N, setSet);

        for (const auto s : setSet)
            convertBitset(cArr, s);

        return 0;
    }
```

不使用模板的简化程序：

```c++
    using std::cout;
    using std::endl;

    void printBit(unsigned long long setInBit, unsigned num)
    {
        for (unsigned i = num; i > 0; --i)
        {
            cout << (setInBit & (1 << i - 1) ? 1 : 0);
        }
        cout << endl;
    }

    int main()
    {
        const unsigned N = 2;
        unsigned long long setInBit = 0;

        getSubset(setInBit, N, N);

        return 0;
    }
```

另外，由 $S(E_n)$ 的个数为 $2^n$ 个，恰好对应着 $n$ 个位置上 $0/1$ 可能出现的所有情况，可以得到一个不使用递归取巧的办法。

```c++
    #include <iostream>
    #include <ctime>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;

    void printBit(unsigned long long setInBit, unsigned num)
    {
        for (unsigned i = num; i > 0; --i)
        {
            cout << (setInBit & (1 << i - 1) ? 1 : 0);
        }
        cout << endl;
    }

    void getSubset(unsigned int num)
    {
        const unsigned long long setInBit = 1 << num;
        for (auto i = 0; i < setInBit; ++i)
            printBit(i, num);
    }

    int main()
    {
        const unsigned N = 2;

        clock_t start, end;
        start = clock();

        getSubset(N);

        end = clock();
        cout << "used time: " << (end - start) << "ms" << endl;

        return 0;
    }
```

26\. [格雷码（Gray Code）]两个代码之间的 ***海明距离***（Hamming distance）是对应位不等的数量。例如 $100$ 和 $010$ 的海明距离是 $2$。一个（二进制）格雷码是一个代码序列，其中任意相邻的两个代码之间的海明距离是 $1$。练习 25 的三位代码序列不是格雷码。而三位代码序列 $000, 100, 110, 010, 011, 111, 101, 001$ 是格雷码。这个代码序列也有一个特性，第一个代码和最后一个代码只有一个二进制位不同，即海明距离是 $1$。在代码序列的一些应用中，从一个代码到下一个代码的代价取决于它们的海明距离。因此我们希望这个代码序列是格雷码。格雷码可以用代码变化的位置序列简洁地表示。对上面的三位格雷码序列，这个位置序列是 $1, 2, 1, 3, 1, 2, 1$。令 $g(n)$ 是一个 $n$ 元素的格雷码的位置变化序列。公式（1-7）是 $g(n)$ 的递归定义。

$$
g(n) =
\begin{cases}
    1               & n = 1 \\
    g(n-1),n,g(n-1) & n \gt 1
\end{cases}\tag{1-7}
$$
&emsp;&emsp;1）使用公式（1-7）手算 $g(4)$。  
&emsp;&emsp;2）确定函数定义的基础部分和递归部分。证明反复应用递归部分可以把右侧的 $g$ 表达式转变为基础部分的表达式。  
&emsp;&emsp;3）编写一个 C++ 递归函数计算 $g(n)$。测试你的代码。  

&emsp;&emsp;手算 $g(4)$：

$$
\begin{aligned}
    g(4) &= \left. g(3),4,g(3)                                              \right. \\
         &= \left. g(2),3,g(2),4,g(2),3,g(2)                                \right. \\
         &= \left. g(1),2,g(1),3,g(1),2,g(1),4,g(1),2,g(1),3,g(1),2,g(1)    \right. \\
         &= \left. 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1              \right.
\end{aligned}
$$

另一方面，一个 $n$ 元素的格雷码，将会是一个包含一个 $2^n$ 个 $n$ 位二进制的代码序列，以代码位置变换序列表示的话将会是一个包含 $2^n - 1$ 个正整数的序列。  

&emsp;&emsp;基础部分是 $g(n) = 1$，递归部分是 $g(n) = g(n-1),n,g(n-1)$。当 $n \gt 1$ 时：

$$
\begin{aligned}
    g(n) &= \left. g(n-1),n,g(n-1)    \right. \\
         &= \left. g(n-2),n-1,g(n-2),n,g(n-2),n-1,g(n-2)    \right. \\
         &= \left. \cdots    \right. \\
         &= \left. g(1),2,g(1),\cdots ,g(n-2),n-1,g(n-2),n,g(n-2),n-1,g(n-2), \cdots ,g(1),2,g(1)    \right.
\end{aligned}
$$

&emsp;&emsp; C++ 递归函数以及测试（需要注意的是，题目中格雷码的序列每个一二进制代码左边是低位右边是高位，与这里 C++ 程序实现的效果恰好是相反的，即代码中的二进制右边是低位左边是高位）：

```c++
    #include <iostream>
    #include <ctime>
    #include <cmath>
    #include <vector>
    #include <iterator>
    #include <algorithm>

    using std::clock;
    using std::clock_t;
    using std::copy;
    using std::cout;
    using std::endl;
    using std::ostream_iterator;
    using std::pow;
    using std::vector;

    /*
    * 将非负整数的二进制形式的指定位翻转（0、1 变换）
    * number：非负整数
    * i：第 i 个位置（从 1 开始）
    */
    void flipBit(unsigned &number, unsigned i)
    {
        //获取第 i 个位置的值
        unsigned tmp = (number & (1 << (i - 1))) >> (i - 1);
        if (tmp)
            //将第 i 个位置变为 0
            number &= ~(1 << (i - 1));
        else
            //将第 i 个位置变为 1
            number |= 1 << (i - 1);
    }

    /*
    * 将非负整数以二进制形式输出
    * number：非负整数的数值
    * n：二进制的位数
    */
    void intToBit(unsigned number, unsigned n)
    {
        for (unsigned i = n; i > 0; --i)
        {
            cout << (number & (1 << i - 1) ? 1 : 0);
        }
        cout << endl;
    }

    /*
    * 得到格雷码的代码位置变换序列
    * container：存放变换位置的容器
    * n：元素个数
    */
    void getGrayCodePos(vector<unsigned> &container, unsigned n)
    {
        if (n == 1)
            container.push_back(n);
        else
        {
            getGrayCodePos(container, n - 1);
            container.push_back(n);
            getGrayCodePos(container, n - 1);
        }
    }

    /*
    * 将格雷码的位置变换序列转换为格雷码
    * positions：位置变换序列
    * n：元素个数
    */
    void convertToGrayCode(const vector<unsigned> &positions, unsigned n)
    {
        unsigned prev = 0;
        intToBit(prev, n);

        for (auto pos : positions)
        {
            flipBit(prev, pos);
            intToBit(prev, n);
        }
    }

    /*
    * 将所有函数综合起来得到的获取 n 元素的格雷码的函数
    * n：元素个数
    */

    void g(unsigned n)
    {
        const unsigned N = n;
        vector<unsigned> codePositions;
        codePositions.reserve(pow(2, N));
        ostream_iterator<unsigned> out(cout, ", ");

        getGrayCodePos(codePositions, N);

        cout << "the position translation is: " << endl;
        copy(codePositions.cbegin(), codePositions.cend(), out);
        cout << "\n-----------------" << endl;

        cout << "The complete Gray Code sequence is: " << endl;
        convertToGrayCode(codePositions, N);
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        g(3);
        cout << "-----------------------------------------" << endl;
        g(4);

        end = clock();
        cout << "used time: " << (end - start) << "ms" << endl;

        return 0;
    }
```

27\. 编写 C++ 代码实现三个参数的模板函数 accumulate。测试代码。

```cmd
    g++ -O2 -fexec-charset=gbk -o test .\test.cpp
```

```c++
    #include <iostream>
    #include <ctime>
    #include <numeric>
    #include <cstddef>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::accumulate;

    /*
    * 自定义 accumulate 函数
    * start：指向首元素的指针
    * end：指向尾后元素的指针
    * initialvalue：初始值
    */
    template <typename T>
    T customAccumulate(T *start, const T *end, T initialValue)
    {
        T theSum = initialValue;
        while (start != end)
            theSum += *start++;

        return theSum;
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 9;
        int ia[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int iInitialValue = 0;

        cout << "accumulate 模板函数得到的结果：" << accumulate(ia, ia + N, iInitialValue) << endl;
        cout << "自定义accumulate 模板函数得到的结果：" << customAccumulate(ia, ia + N, iInitialValue) << endl;
        cout << "-----------------------------------" << endl;

        double da[N] = {1.1, 1.2, 1.3, 1.4, 1.4, 1.6, 1.7, 1.8, 1.9};
        double dInitialValue = 0.0;

        cout << "accumulate 模板函数得到的结果：" << accumulate(da, da + N, dInitialValue) << endl;
        cout << "自定义accumulate 模板函数得到的结果：" << customAccumulate(da, da + N, dInitialValue) << endl;
        cout << "-----------------------------------" << endl;

        end = clock();
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

28\. 编写 C++ 代码实现四个参数的模板函数 accumulate。测试你的代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <numeric>
    #include <cstddef>
    #include <functional>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::accumulate;
    using std::multiplies;

    /*
    * 自定义 accumulate 函数
    * start：指向首元素的指针
    * end：指向尾后元素的指针
    * initialvalue：初始值
    * fn：对元素操作的可调用对象
    */
    template <typename T, typename ReduceFn>
    T customAccumulate(T *start, const T *end, T initialValue, ReduceFn fn)
    {
        T theSum = initialValue;
        while (start != end)
            theSum = fn(theSum, *start++);

        return theSum;
    }

    //测试小函数
    double multi(double d1, double d2)
    {
        return d1 * d2;
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 9;
        int ia[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int iInitialValue = 1;

        cout << "accumulate 模板函数得到的结果："
            << accumulate(ia, ia + N, iInitialValue, multiplies<int>())
            << endl;
        cout << "自定义accumulate 模板函数得到的结果："
            << customAccumulate(ia, ia + N, iInitialValue, multiplies<int>())
            << endl;
        cout << "-----------------------------------" << endl;

        double da[N] = {1.1, 1.2, 1.3, 1.4, 1.4, 1.6, 1.7, 1.8, 1.9};
        double dInitialValue = 1.0;

        cout << "accumulate 模板函数得到的结果："
            << accumulate(da, da + N, dInitialValue, multiplies<double>())
            << endl;
        cout << "自定义accumulate 模板函数得到的结果："
            << customAccumulate(da, da + N, dInitialValue, multiplies<double>())
            << endl;
        cout << "-----------------------------------" << endl;

        double (*fn)(double d1, double d2) = &multi;
        cout << "accumulate 模板函数得到的结果："
            << accumulate(da, da + N, dInitialValue, fn)
            << endl;
        cout << "自定义accumulate 模板函数得到的结果："
            << customAccumulate(da, da + N, dInitialValue, fn)
            << endl;
        cout << "-----------------------------------" << endl;

        end = clock();
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

29\. 编写 C++ 代码实现模板函数 copy。测试代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <algorithm>
    #include <iterator>
    #include <vector>
    #include <string>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::back_inserter;
    using std::copy;
    using std::insert_iterator;
    using std::ostream_iterator;
    using std::string;
    using std::vector;

    /*
    * 自定义 copy 函数
    * begin：源容器指向头元素的迭代器（或者指针）
    * end：源容器指向尾后的迭代器（或者指针）
    * dest：目标容器的具备插入操作的迭代器（或者指针）
    */
    template <typename SourceIt, typename DestinationIt>
    void customCopy(SourceIt begin, SourceIt end, DestinationIt dest)
    {
        SourceIt sTmpIt = begin;
        DestinationIt dTmpIt = dest;
        while (sTmpIt != end)
        {
            *dTmpIt = *sTmpIt;
            ++sTmpIt;
            ++dTmpIt;
        }
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 5;
        ostream_iterator<int> osIt(cout, " ");
        ostream_iterator<string> osStrIt(cout, " ");

        int ia0[N] = {1, 2, 3, 4, 5};
        int ia1[N], ia2[N];

        copy(ia0, ia0 + N, ia1);
        customCopy(ia0, ia0 + N, ia2);

        copy(ia0, ia0 + N, osIt);
        cout << "\n-----------------------" << endl;
        copy(ia1, ia1 + N, osIt);
        cout << "\n-----------------------" << endl;

        customCopy(ia0, ia0 + N, osIt);
        cout << "\n-----------------------" << endl;
        customCopy(ia2, ia2 + N, osIt);
        cout << "\n-----------------------------------------------" << endl;

        vector<string> vs0 = {"abc", "def", "ghi", "jkl"};
        vector<string> vs1, vs2;

        copy(vs0.begin(), vs0.end(), back_inserter(vs1));
        customCopy(vs0.begin(), vs0.end(), back_inserter(vs2));

        copy(vs0.begin(), vs0.end(), osStrIt);
        cout << "\n-----------------------" << endl;
        copy(vs1.begin(), vs1.end(), osStrIt);
        cout << "\n-----------------------" << endl;

        customCopy(vs0.begin(), vs0.end(), osStrIt);
        cout << "\n-----------------------" << endl;
        customCopy(vs2.begin(), vs2.end(), osStrIt);
        cout << "\n-----------------------" << endl;

        end = clock();
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

30\. 修改程序 1-35，输出所有元素的所有排列。在生成排列之前，把元素按升序排列。使用 STL 的排序算法  
$$sort(start, end)$$
它把 $[start, end)$ 之内的元素按升序排列。  

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <algorithm>
    #include <iterator>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::back_inserter;
    using std::copy;
    using std::insert_iterator;
    using std::next_permutation;
    using std::ostream_iterator;
    using std::sort;

    template <typename T>
    void permutations(T list[], int k, int m)
    {
        do
        {
            copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
            cout << endl;
        } while (next_permutation(list, list + m + 1));
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 3;
        char ca[N] = {'c', 'b', 'a'};

        //如果不事先排好序则输出会不完整
        sort(ca, ca + N);

        permutations(ca, 0, N - 1);

        end = clock();
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

31\. 修改程序 1-35，输出所有元素的所有不同排列。先用 STL 算法 next_permutation 生成比初始排列大的排列，再用 STL 算法 prev_permutation 生成比初始排列小的排列。测试你的代码。  

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <algorithm>
    #include <iterator>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::back_inserter;
    using std::copy;
    using std::insert_iterator;
    using std::next_permutation;
    using std::ostream_iterator;
    using std::prev_permutation;
    using std::sort;

    template <typename T>
    void permutations(T list[], int k, int m)
    {
        do
        {
            copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
            cout << endl;
        } while (next_permutation(list, list + m + 1));
        cout << "----------------------" << endl;

        //首先将 list 按照降序排列
        sort(list, list + m + 1, [](const T &t1, const T &t2) -> bool { return t1 < t2 ? false : true; });
        do
        {
            copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
            cout << endl;
        } while (prev_permutation(list, list + m + 1));
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 3;
        char ca[N] = {'c', 'b', 'a'};

        //如果不事先排好序则输出会不完整
        sort(ca, ca + N);

        permutations(ca, 0, N - 1);

        end = clock();
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

32\. 修改程序 1-35，输出所有元素的所有不同排列。注意，当 next_permutation 的返回值是 false 时，序列 $[start, end)$ 时最小序列。因此，调用 next_permutation 可以得到剩余的排列。测试的你代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <algorithm>
    #include <iterator>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::back_inserter;
    using std::copy;
    using std::insert_iterator;
    using std::next_permutation;
    using std::ostream_iterator;
    using std::sort;

    template <typename T>
    void permutations(T list[], int k, int m)
    {
        do
        {
            copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
            cout << endl;
        } while (next_permutation(list, list + m + 1));
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 3;
        char ca[N] = {'c', 'b', 'a'};

        //如果不事先排好序则输出会不完整
        sort(ca, ca + N);

        permutations(ca, 0, N - 1);

        end = clock();
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

33\. 使用 STL 算法 count 做练习 2。count 的语法是：
$${\rm count(start, end, value)}$$

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <algorithm>
    #include <iomanip>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;


    using std::copy;
    using std::count;
    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 12;
        int ia[N] = {3, 2, 1, 13, 2, 2, 13, 3, 12, 21, 3, 2};
        char ca[N] = {'q', 'f', 'k', 's', 'a', 's', 's', 'n', 'a', 'f', 'c', 'a'};

        cout << "ia 中元素 1 的数量为：" << count(ia, ia + N, 1) << endl;
        cout << "ia 中元素 3 的数量为：" << count(ia, ia + N, 3) << endl;
        cout << "ca 中元素 a 的数量为：" << count(ca, ca + N, 'a') << endl;
        cout << "ca 中元素 b 的数量为：" << count(ca, ca + N, 'b') << endl;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

34\. 使用 STL 算法 fill 做练习 3。fill 的语法是：
$${\rm fill(start, edn, value)}$$

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <algorithm>
    #include <iterator>
    #include <iomanip>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::ostream_iterator;
    using std::size_t;

    using std::fill;
    using std::copy;

    int main()
    {
        clock_t start, end;
        start = clock();

        ostream_iterator<int> iOsIt(cout, ", ");
        ostream_iterator<char> cOsIt(cout, ", ");
        const size_t N = 10;
        int ia[N] = {1};
        char ca[N] = {'a'};

        copy(ia, ia + N, iOsIt);
        cout << "\n";
        copy(ca, ca + N, cOsIt);
        cout << "\n";

        fill(ia, ia + N, 100);
        fill(ca, ca + N, 's');

        copy(ia, ia + N, iOsIt);
        cout << "\n";
        copy(ca, ca + N, cOsIt);
        cout << "\n";

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

35\. 使用 STL 算法 inner_product 做练习 4。inner_product 的语法是：
$${\rm inner_product(start1, end1, start2, initialValue)}$$

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <iomanip>
    #include <numeric>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::inner_product;

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 5;
        int ia[N] = {1, 3, 5, 7, 9}, ib[N] = {2, 4, 6, 8, 10};

        cout << "ia * ib = " << inner_product(ia, ia + N, ib, 0) << endl;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

36\. 使用 STL 算法 iota 做练习 5。iota 的语法是：
$${\rm iota(start, end, value)}$$

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <iomanip>
    #include <numeric>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::iota;

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 10;
        int ia[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        for (size_t i = 0; i < N; ++i)
            cout << ia[i] << " ";
        cout << endl;
        iota(ia, ia + N, 3);
        for (size_t i = 0; i < N; ++i)
            cout << ia[i] << " ";
        cout << endl;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

37\. 使用 STL 算法 is_sorted 做练习 6。is_sorted 的语法是：
$${\rm is_sorted(start, end)}$$

```c++
    #include <iostream>
    #include <ctime>
    #include <iomanip>
    #include <algorithm>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;

    using std::is_sorted;

    int main()
    {
        clock_t start, end;
        start = clock();

        int ia1[] = {1, 3, 5, 6, 7, 8};
        int ia2[] = {5, 3, 2, 5, 7, 21, 1};
        int ia3[] = {1, 2, 3, 6, 5, 4};

        cout << std::boolalpha;
        cout << "数组 ia1 是否排序：" << is_sorted(ia1, ia1 + 6) << endl;
        cout << "数组 ia2 是否排序：" << is_sorted(ia2, ia2 + 7) << endl;
        cout << "数组 ia3 前一半是否排序：" << is_sorted(ia3, ia3 + 3) << endl;
        cout << "数组 ia3 后一半是否排序：" << is_sorted(ia3 + 3, ia3 + 6) << endl;
        cout << std::noboolalpha;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

38\. 使用 STL 算法 mismatch 做练习 7。mismatch 的语法是：
$${\rm mismatch(start1, end1, start2)}$$

```c++
    #include <iostream>
    #include <ctime>
    #include <iomanip>
    #include <algorithm>
    #include <utility>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::pair;

    using std::mismatch;

    int main()
    {
        clock_t start, end;
        start = clock();

        int ia1[] = {1, 2, 3, 4, 5, 60};
        int ia2[] = {1, 2, 3, 4, 5, 60, 80, 3, 6, 8};
        int ia3[] = {1, 2, 3, 4, 5, 70, 30, 43, 67};

        pair<int *, int *> res12 = mismatch(ia1, ia1 + 6, ia2);
        pair<int *, int *> res13 = mismatch(ia1, ia1 + 6, ia3);
        pair<int *, int *> res23 = mismatch(ia2, ia2 + 6, ia3);
        cout << "数组 ia1 与数组 ia2 第一个不相等的元素是："
            << (*res12.first) << ", " << (*res12.second) << endl;
        cout << "数组 ia1 与数组 ia3 第一个不相等的元素是："
            << (*res13.first) << ", " << (*res13.second) << endl;
        cout << "数组 ia2 与数组 ia3 第一个不相等的元素是："
            << (*res23.first) << ", " << (*res23.second) << endl;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

39\. 编写 c++ 代码，实现练习 33 的 STL 模板函数 count。测试你的代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <algorithm>
    #include <iomanip>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::copy;
    using std::count;

    template <typename T, typename TIterator>
    unsigned customCount(TIterator start, TIterator end, const T &value)
    {
        unsigned con = 0;
        TIterator tmp = start;

        while (tmp != end)
            if (*tmp++ == value)
                ++con;

        return con;
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 12;
        int ia[N] = {3, 2, 1, 13, 2, 2, 13, 3, 12, 21, 3, 2};
        char ca[N] = {'q', 'f', 'k', 's', 'a', 's', 's', 'n', 'a', 'f', 'c', 'a'};

        cout << "ia 中元素 1 的数量为：" << count(ia, ia + N, 1) << endl;
        cout << "ia 中元素 3 的数量为：" << count(ia, ia + N, 3) << endl;
        cout << "ca 中元素 a 的数量为：" << count(ca, ca + N, 'a') << endl;
        cout << "ca 中元素 b 的数量为：" << count(ca, ca + N, 'b') << endl;

        cout << "-------------------------" << endl;
        cout << "ia 中元素 1 的数量为：" << customCount(ia, ia + N, 1) << endl;
        cout << "ia 中元素 3 的数量为：" << customCount(ia, ia + N, 3) << endl;
        cout << "ca 中元素 a 的数量为：" << customCount(ca, ca + N, 'a') << endl;
        cout << "ca 中元素 b 的数量为：" << customCount(ca, ca + N, 'b') << endl;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

40\. 编写 c++ 代码，实现练习 34 的 STL 模板函数 fill。测试你的代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <algorithm>
    #include <iterator>
    #include <iomanip>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::ostream_iterator;
    using std::size_t;

    using std::copy;
    using std::fill;

    template <typename T, typename TIterator>
    void customFill(TIterator start, TIterator end, T value)
    {
        for (auto it = start; it != end; ++it)
            *it = value;
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        ostream_iterator<int> iOsIt(cout, ", ");
        ostream_iterator<char> cOsIt(cout, ", ");
        const size_t N = 10;
        int ia[N] = {1};
        char ca[N] = {'a'};

        copy(ia, ia + N, iOsIt);
        cout << "\n";
        copy(ca, ca + N, cOsIt);
        cout << "\n";

        fill(ia, ia + N, 100);
        fill(ca, ca + N, 's');

        copy(ia, ia + N, iOsIt);
        cout << "\n";
        copy(ca, ca + N, cOsIt);
        cout << "\n";

        //.........................
        customFill(ia, ia + N, 11);
        customFill(ca, ca + N, 'A');

        copy(ia, ia + N, iOsIt);
        cout << "\n";
        copy(ca, ca + N, cOsIt);
        cout << "\n";

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

41\. 编写 c++ 代码，实现练习 35 的 STL 模板函数 inner_product。测试你的代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <iomanip>
    #include <numeric>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::inner_product;

    template <typename TIterator, typename T>
    unsigned customInnerProduct(TIterator start1, TIterator end1, TIterator start2, T initialValue)
    {
        T res = initialValue;
        TIterator tmp1 = start1, tmp2 = start2;
        while (tmp1 != end1)
            res += (*tmp1++) * (*tmp2++);

        return res;
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 5;
        int ia[N] = {1, 3, 5, 7, 9}, ib[N] = {2, 4, 6, 8, 10};

        cout << "ia * ib = " << inner_product(ia, ia + N, ib, 0) << endl;
        cout << "ia * ib = " << inner_product(ia, ia + N, ib, 3) << endl;
        cout << "-------------------------" << endl;
        cout << "ia * ib = " << customInnerProduct(ia, ia + N, ib, 0) << endl;
        cout << "ia * ib = " << customInnerProduct(ia, ia + N, ib, 3) << endl;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

42\. 编写 c++ 代码，实现练习 36 的 STL 模板函数 iota。测试你的代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <cstddef>
    #include <iomanip>
    #include <numeric>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::size_t;

    using std::iota;

    template <typename T, typename TIterator>
    void customIota(TIterator start, TIterator end, T value)
    {
        TIterator tmp = start;

        while (tmp != end)
            *tmp++ = value++;
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        const size_t N = 10;
        int ia[N] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 10};

        for (size_t i = 0; i < N; ++i)
            cout << ia[i] << " ";
        cout << endl;
        iota(ia, ia + N, 3);
        for (size_t i = 0; i < N; ++i)
            cout << ia[i] << " ";
        cout << endl;

        customIota(ia, ia + N, 3);
        for (size_t i = 0; i < N; ++i)
            cout << ia[i] << " ";
        cout << endl;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

43\. 编写 c++ 代码，实现练习 37 的 STL 模板函数 is_sorted。测试你的代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <iomanip>
    #include <algorithm>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;

    using std::is_sorted;

    template <typename TIterator>
    bool customIsSorted(TIterator start, TIterator end)
    {
        TIterator prev = start, next = start;
        ++next;
        while (next != end)
            if (!(*prev++ < *next++))
                return false;
        return true;
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        int ia1[] = {1, 3, 5, 6, 7, 8};
        int ia2[] = {5, 3, 2, 5, 7, 21, 1};
        int ia3[] = {1, 2, 3, 6, 5, 4};

        cout << std::boolalpha;
        cout << "数组 ia1 是否排序：" << is_sorted(ia1, ia1 + 6) << endl;
        cout << "数组 ia2 是否排序：" << is_sorted(ia2, ia2 + 7) << endl;
        cout << "数组 ia3 前一半是否排序：" << is_sorted(ia3, ia3 + 3) << endl;
        cout << "数组 ia3 后一半是否排序：" << is_sorted(ia3 + 3, ia3 + 6) << endl;

        cout << "-----------------------------------------" << endl;
        cout << "数组 ia1 是否排序：" << customIsSorted(ia1, ia1 + 6) << endl;
        cout << "数组 ia2 是否排序：" << customIsSorted(ia2, ia2 + 7) << endl;
        cout << "数组 ia3 前一半是否排序：" << customIsSorted(ia3, ia3 + 3) << endl;
        cout << "数组 ia3 后一半是否排序：" << customIsSorted(ia3 + 3, ia3 + 6) << endl;
        cout << std::noboolalpha;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```

44\. 编写 c++ 代码，实现练习 38 的 STL 模板函数 mismatch。测试你的代码。

```c++
    #include <iostream>
    #include <ctime>
    #include <iomanip>
    #include <algorithm>
    #include <utility>

    using std::clock;
    using std::clock_t;
    using std::cout;
    using std::endl;
    using std::pair;

    using std::mismatch;

    template <typename TIterator1, typename TIterator2>
    pair<TIterator1, TIterator2> customMismatch(TIterator1 start1, TIterator1 end1, TIterator2 start2)
    {
        TIterator1 t1 = start1;
        TIterator2 t2 = start2;
        while (t1 != end1)
        {
            if (*t1 != *t2)
                break;
            ++t1;
            ++t2;
        }

        return {t1, t2};
    }

    int main()
    {
        clock_t start, end;
        start = clock();

        int ia1[] = {1, 2, 3, 4, 5, 60};
        int ia2[] = {1, 2, 3, 4, 5, 60, 80, 3, 6, 8};
        int ia3[] = {1, 2, 3, 4, 5, 70, 30, 43, 67};

        pair<int *, int *> res12 = mismatch(ia1, ia1 + 6, ia2);
        pair<int *, int *> res13 = mismatch(ia1, ia1 + 6, ia3);
        pair<int *, int *> res23 = mismatch(ia2, ia2 + 6, ia3);
        cout << "数组 ia1 与数组 ia2 第一个不相等的元素是："
            << (*res12.first) << ", " << (*res12.second) << endl;
        cout << "数组 ia1 与数组 ia3 第一个不相等的元素是："
            << (*res13.first) << ", " << (*res13.second) << endl;
        cout << "数组 ia2 与数组 ia3 第一个不相等的元素是："
            << (*res23.first) << ", " << (*res23.second) << endl;

        cout << "-----------------------------" << endl;
        int cia1[] = {1, 2, 3, 4, 5, 60};
        int cia2[] = {1, 2, 3, 4, 5, 60, 80, 3, 6, 8};
        int cia3[] = {1, 2, 3, 4, 5, 70, 30, 43, 67};
        pair<int *, int *> cres12 = customMismatch(cia1, cia1 + 6, cia2);
        pair<int *, int *> cres13 = customMismatch(cia1, cia1 + 6, cia3);
        pair<int *, int *> cres23 = customMismatch(cia2, cia2 + 6, cia3);
        cout << "数组 cia1 与数组 cia2 第一个不相等的元素是："
            << (*cres12.first) << ", " << (*cres12.second) << endl;
        cout << "数组 cia1 与数组 cia3 第一个不相等的元素是："
            << (*cres13.first) << ", " << (*cres13.second) << endl;
        cout << "数组 cia2 与数组 cia3 第一个不相等的元素是："
            << (*cres23.first) << ", " << (*cres23.second) << endl;

        end = clock();
        cout << std::setw(16) << std::setfill('-') << "" << endl;
        cout << "用时：" << (end - start) << " 毫秒" << endl;
        return 0;
    }
```
