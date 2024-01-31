#include <iostream>
#include <time.h>

using namespace std;

int main()
{
  const int SIZE = 5;

  int a[SIZE];

  srand(time(NULL));

  for (int i = 0; i < SIZE; i++)
  {
    a[i] = rand() % 900 + 100;
    cout << a[i] << ' ';
  }
  cout << endl;

  int max = a[0];
  int min = a[0];

  for (int i = 1; i < SIZE; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
    else if (a[i] < min)
    {
      min = a[i];
    }
  }

  cout << "наибольший элемент массива: " << max << endl
       << "наименьший элемент массива: " << min << endl;

  return 0;
}
