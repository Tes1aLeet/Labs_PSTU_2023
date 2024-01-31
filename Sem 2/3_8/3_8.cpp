#include <iostream>
#include <time.h>

using namespace std;

void move_right(int* a, int position, int size)
{
  for (int i = size - 2; i > position - 1; i--)
  {
    a[i + 1] = a[i];
  }
}

void print(int* a, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << a[i] << ' ';
  }
  cout << endl;
}

int main()
{
  const int SIZE = 5;

  int a[SIZE * 2];

  int counter = 0;

  srand(time(NULL));
  
  for (int i = 0; i < SIZE; i++)
  {
    a[i] = rand() % 90 + 10;
  }
  print(a, SIZE);

  for (int i = 0; i < SIZE + counter; i++)
  {
    if (a[i] % 2 == 1)
    {
      move_right(a, i, SIZE * 2);
      a[i] = -1;
      i++;
      counter++;
    }
  }

  print(a, SIZE + counter);
  
  return 0;
}
