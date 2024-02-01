#include <iostream>
#include <time.h>

using namespace std;

int main()
{
  const int SIZE = 10;

  int a[SIZE];

  srand(time(NULL));

  for (int i = 0; i < SIZE; i++)
  {
    a[i] = rand() % 900 + 100;
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

  cout << "наибольший элемент массива: " << max << endl;

  return 0;
}
