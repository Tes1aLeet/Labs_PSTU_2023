#include <iostream>
#include <cmath>

using namespace std;

double get_y(double x)  // получить значение функции в точке x
{
  // y = arcsin^2(x) - sin(x) - 1
  return ( 3 * sin(x) * sqrt(x) ) + ( 0.35 * x ) - 3.8; 
}

int main()
{
  double intervalStart, intervalEnd, intervalMedian;
// (intervalStart; IntervalEnd) - монотонный промежуток функции, в котором ТОЧНО есть решение уравнения
// intervalMedian - середина промежутка (intervalStart; intervalEnd)
  float Fs, Fe, Fm;
// Fs - значение функции в точке intervalStart, Fe - в intervalEnd, Fm - в intervalMedian
  double precision = 0.00001;
// точность вычислений (погрешность не больше, чем precision)
  intervalStart = 1.0;
  intervalEnd   = 1.9;

  cout.precision(10);   // вывод 10 знаков после запятой 

  cout << "Уравнение                          : 3sin(x)*sqrt(x) + 0.35x - 3.8" << endl
       << "Промежуток поиска решений уравнения: [" << intervalStart << "; " << intervalEnd << ']' << endl;

  while(intervalEnd - intervalStart > precision)
  {
    intervalMedian = (intervalEnd + intervalStart) / 2;

    Fs = get_y(intervalStart);
    Fe = get_y(intervalEnd);
    Fm = get_y(intervalMedian);

    if(Fs * Fm < 0)
    {
      intervalEnd = intervalMedian;
    }
    else if(Fe * Fm < 0) 
    {
      intervalStart = intervalMedian;
    }
    else 
    {
      cout << "Отрезок не содержит решения!" << endl;
      break;
    }
  }

if(intervalEnd - intervalStart < precision)  // если на выбранном отрезке есть решение (т.е. цикл закончился не с помощью break)
{
  cout << "Решение находится в промежутке     : [" << intervalStart << "; " << intervalEnd << ']' << endl;
}

  return 0;
}
