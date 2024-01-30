#include <iostream>
#include <time.h>

using namespace std;

int main () 
{
  int n, temp, zeros;
  zeros = 0;

  bool evenFound = false;

  int a[100];
  //int a[100] = {6,0,8,0,7,2,0,9,6,8};

  cin >> n;
  //n = 10;

  srand(time(NULL));  // зерно генератора случ. чисел - текущее время

  // заполняем массив и выводим его в первый раз
  for (int i = 0; i < n; i++)
  {
    a[i] = rand() % 10;
    cout << a[i] << " ";
  }

  cout << endl;

  // убираем нули
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] == 0)
    {
      zeros++;
      for (int j = i; j < n - 1; j++)
      {
        a[j] = a[j + 1]; 
      }
    }
  }

  // ищем четное число, добавляем после него элемент
  for (int i = 0; i < n - zeros; i++)
  {
    if (a[i] % 2 == 0 && !evenFound)
    {
      evenFound = true;

      for (int j = n - zeros - 1; j > i; j--)
      {
        a[j + 1] = a[j];
      }

      a[i + 1] = a[i] + 2;
    }
  }

  // выводим конечный массив
  for (int i = 0; i < n - zeros + evenFound; i++)       // если нашли четное, выводим на 1 элемент больше
  {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}


/* тесты
 *  
 * int a[100] = {0,0,1,0,0,2,0,0,0,0}
 * вывод:
 * 0 0 1 0 0 2 0 0 0 0
 * 1 2 4
 * 
 * int a[100] = {0,0,0,0,0,0,0,0,0,0}
 * вывод:
 * 0 0 0 0 0 0 0 0 0 0
 * 
 *
 * int a[100] = {2,2,2,0,2,2,0,4,6,8}
 * вывод:
 * 2 2 2 0 2 2 0 4 6 8
 * 2 4 2 2 2 2 4 6 8
 *
 * int a[100] = {6,0,8,0,7,2,0,9,6,8}
 * вывод:
 * 6 0 8 0 7 2 0 9 6 8
 * 6 8 8 7 2 9 6 8
 *
 * */

