Анисимов Дмитрий Александрович

ИВТ-23-1б

# 1 Вариант задания

Лабораторная работа №5, вариант 3

**Функции и массивы** 

Задание:

Написать процедуру для суммирования матриц. С ее
помощью сложить исходную матрицу и транспонированную
(т. е. полученную поворотом исходной на 90 ).

# 2.1 Код программы

```cpp
#include <iostream>
#include <time.h>

using namespace std;

// a - исходная матрица, b - матрица, в которую записываем результат транспонирования
void transpose(int* a, int* b, const int height, const int width)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      b[(i*width) + j] = a[(j*width) + i];
    }
  }
}

// a, b - исходные матрицы, c - матрица, в которую записываем результат сложения
void sum(int* a, int* b, int* c, const int height, const int width)
{
  for (int i = 0; i < height * width; i++)
  {
    c[i] = a[i] + b[i];
  }
}

void printMatrix(int* m, const int height, const int width)
{
  for (int i = 0; i < height * width; i++)
  {
    if (i % width == 0 && i != 0)
    {
      cout << endl;
    }
    cout << m[i] << ' ';
  }
  cout << endl;
}

int main()
{
  const int HEIGHT = 5;
  const int WIDTH  = 5;

  int a[HEIGHT][WIDTH];
  int b[HEIGHT][WIDTH];
  int c[HEIGHT][WIDTH];

  srand(time(NULL));  // зерно генератора случ. чисел - текущее время

  // заполняем матрицу случайными числами
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      a[i][j] = rand() % 40 + 10;
    }
  }

  transpose(*a, *b, HEIGHT, WIDTH);
  sum(*a, *b, *c, HEIGHT, WIDTH);

  printMatrix(*a, HEIGHT, WIDTH);
  cout << "начальная матрица" << endl << endl;
  printMatrix(*b, HEIGHT, WIDTH);
  cout << "транспонированная матрица" << endl << endl;
  printMatrix(*c, HEIGHT, WIDTH);
  cout << "результат сложения" << endl;

  return 0;
}
```

# 2.2 Блок-схема

<image src="block_diagram.png">

# 3 Тесты

<image src="test_1.png">
<image src="test_2.png">
<image src="test_3.png">
