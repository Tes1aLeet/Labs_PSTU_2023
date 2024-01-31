#include <iostream>
#include <time.h>

using namespace std;

int main()
{
  const int SIZE = 12;

  int a[SIZE];

  int count = 0;

  srand(time(NULL));

  for (int i = 0; i < SIZE; i++)
  {
    a[i] = rand() % 10;
    cout << a[i] << ' ';
  }
  cout << endl;

  int max = a[0];

  for (int i = 1; i < SIZE; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
  }

  for (int i = 0; i < SIZE; i++)
  {
    if (a[i] == max)
    {
      count++;
    }
  }

  cout << "наибольший элемент массива: " << max << endl;
  cout << "количество элементов массива, совпадающих с наибольшим: " << count << endl;

  return 0;
}
