Анисимов Дмитрий Александрович

ИВТ-23-1б

# 1 Вариант задания

Лабораторная работа № 1, вариант 1

**Сумма ряда**

Задание:

1) Через сумму функционального ряда с помощью рекурсивной функции. Аргументы функции — n и x, где n — количество членов ряда, x — переменная. 
2) Через прямое вычисление значения функции. Аргумент функции — переменная x.

Сравнить полученные результаты

<img src="expression.png">

# 2.1 Код программы

```c++
// вариант 3
// S = x^3 / 3! + ... + (-1)^n * (x^(2n+1) / (2n+1)!)

#include <iostream>
#include <math.h>

using namespace std;

int factorial(int n)
{
  if(n <= 1)
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}

double find_sum(int x, int n)
{
  if(n == 0)
  {
    return x;
  }
  else
  {
    return pow(-1, n) * ((pow(x, (2 * n) + 1) / factorial((2 * n) + 1) )) + find_sum(x, n - 1);
  }
}

double solve(int x, int n)
{
  return pow(-1, n) * ((pow(x, (2 * n) + 1) / factorial((2 * n) + 1) ));
}

int main()
{
  int x, n;
  double sum = 0;

  cout << "x:";
  cin >> x;
  cout << "n:";
  cin >> n;

  cout.precision(15);

  cout << "S=" << find_sum(x, n) << " - рекурсия" << endl;

  for(int i = 0; i <= n; i++)
  {
    sum += solve(x, i);
  }

  cout << "S=" << sum << " - прямое вычисление функции" << endl;

  return 0;
}
```

# 2.2 Блок-схема

<image src="block_diagram.png">

# 3 Тесты

<image src="test.png">
