#include <iostream>
#include <time.h>

using namespace std;

void print(int* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << ' ';
  }
  cout << endl;
}

void swap(int* array, int a, int b)
{
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}

int main()
{
  const int SIZE = 10;

  int temp, k;

  int a[SIZE];

  srand(time(NULL));

  cin >> k;

  for (int i = 0; i < SIZE; i++)
  {
    a[i] = rand() % 10; 
  }

  print(a, SIZE);
  cout << endl;

  for (int i = 0; i < k; i++)
  {
    for (int j = 0; j < SIZE - 1; j++) 
    {
      swap(a, j, ((SIZE - 1) + j) % SIZE);
    }
  }

  print(a, SIZE);

  return 0;
}
