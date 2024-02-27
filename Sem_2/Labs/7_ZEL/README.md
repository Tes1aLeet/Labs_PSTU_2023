Анисимов Дмитрий Александрович 

ИВТ-23-1б

# 1 Вариант задания

Лабораторная работа № 7.1, вариант 3 

**Перегрузка функций в C++**

Задание:

Написать перегруженные функии и основную программу, которая их вызывает:

а) для умножения целых чисел
б) для умножения комплексных чисел

# 2 Код программы

```c++
#include <iostream>
#include <complex>

using namespace std;

complex<double> multiply(complex<double> n1, complex<double> n2)
{
  return n1 * n2;
}

int multiply(int n1, int n2)
{
  return n1 * n2;
}

int main()
{
  complex<double> n1 = 1.0 + 2i, n2 = 1.0 - 2i;

  cout << "(1 + 2i) * (1 - 2i) = " << multiply(n1, n2) << endl;

  cout << "7 * 8 = " << multiply(7,8) << endl;

  return 0;
}
```

# 3 Тесты

<image src="test_1.png">

<br/><br/>

# 1 Вариант задания

Лабораторная работа № 7.2, вариант 3

**Функции с переменным числом параметров**

Задание:

Написать функцию sum с переменным числом параметров,
которая находит сумму чисел типа int по формуле:
S=a1\*a2+a2\*a3+a3\*a4+. . . . .
Написать вызывающую функцию main, которая обращается к
функции sum не менее трех раз с количеством параметров 5,
10, 12.

# 2 Код программы

```c++
#include <iostream>
#include <stdarg.h>

using namespace std;

int sum(int k, ...)
{
  int temp = 0;
  int sum = 0;

  va_list ptr;

  va_start(ptr, k);

  for(int i = 0; i < k / 2 + k % 2; i++)
  {
    temp = va_arg(ptr, int);

    if(i == k - 1)
    {
      sum += temp;
    }
    else
    {
      sum += temp * va_arg(ptr, int);
    }
  }
  va_end(ptr);

  return sum;
}

int main()
{
  cout << "sum(5, 1, 2, 3, 4, 5) = ";
  cout << sum(5, 1, 2, 3, 4, 5) << endl;
  cout << "sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = ";
  cout << sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
  cout << "sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) = ";
  cout << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;


  return 0;
}
```

# 3 Тесты

<image src="test_2.png">
