Анисимов Дмитрий Александрович

ИВТ-23-1б

# 1 Вариант задания

Лабораторная работа

**Числа Фибоначчи**

Функция, принимающая n, где n - порядковый номер нужного числа Фибоначчи

# 2.1 Код программы

```c++
#include <iostream>

using namespace std;

int fibonacci(int n)
{
  if(n == 1)
  {
    return 1;
  }
  else if(n == 0)
  {
    return 0;
  }
  else
  {
    return fibonacci(n - 2) + fibonacci(n - 1);
  }
}

int main()
{
  int a;

  cin >> a;

  cout << fibonacci(a) << endl;

  return 0;
}
```

# 2.2 Блок-схема

<image src="block_diagram.png">

# 3 Тесты

<image src="test.png">
