// 测试代码用

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