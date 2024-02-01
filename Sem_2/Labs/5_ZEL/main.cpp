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

/*  результат работы программы:
 
19 12 10 25 33
11 47 21 19 38
24 27 33 16 30
25 16 18 16 36
29 19 34 36 23
начальная матрица

19 11 24 25 29
12 47 27 16 19
10 21 33 18 34
25 19 16 16 36
33 38 30 36 23
транспонированная матрица

38 23 34 50 62
23 94 48 35 57
34 48 66 34 64
50 35 34 32 72
62 57 64 72 46
результат сложения

--------------------------------

27 13 17 32 26
13 42 38 38 11
38 41 24 14 16
24 39 24 21 38
10 10 15 12 45
начальная матрица

27 13 38 24 10
13 42 41 39 10
17 38 24 24 15
32 38 14 21 12
26 11 16 38 45
транспонированная матрица

54 26 55 56 36
26 84 79 77 21
55 79 48 38 31
56 77 38 42 50
36 21 31 50 90
результат сложения

--------------------------------

49 12 22 38 23
38 34 24 24 17
44 16 39 45 36
12 40 17 17 12
28 44 14 43 42
начальная матрица

49 38 44 12 28
12 34 16 40 44
22 24 39 17 14
38 24 45 17 43
23 17 36 12 42
транспонированная матрица

98 50 66 50 51
50 68 40 64 61
66 40 78 62 50
50 64 62 34 55
51 61 50 55 84
результат сложения

*/


