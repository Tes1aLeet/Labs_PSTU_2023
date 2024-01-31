#include <iostream>
#include <time.h>

using namespace std;

void move_left(int* a, int position, int size)
{
  for (int i = position; i < size - 1; i++)
  {
    a[i] = a[i + 1];
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
  const int SIZE = 10;

  int a[SIZE];

  int counter = 0;

  srand(time(NULL));
  
  for (int i = 0; i < SIZE; i++)
  {
    a[i] = rand() % 90 + 10;
  }
  print(a, SIZE);
  cout << endl;

  for (int i = 0; i < SIZE - counter; i++)
  {
    if (a[i] % 2 == 1)
    {
     move_left(a, i, SIZE);
     //print(a, SIZE);
     counter++;
     i--; 
    }
  }
  //cout << endl;

  print(a, SIZE - counter);
  
  return 0;
}
