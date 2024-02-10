#include <iostream>
#include <time.h>

using namespace std;

void print(int* a, const int size);

void place_queens(int* a, int pos, const int size);

int main()
{
  const int SIZE = 8;
  
  int field[SIZE][SIZE] = {};

  int row, col;

  srand(time(NULL));

  row = rand() % 8;
  col = rand() % 8;

  row = 4;
  col = 3;

  field[row][col] = 1;

  print(*field, SIZE);

  place_queens(*field, (row * SIZE) + col, SIZE);

  return 0;
}

void print(int* a, const int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      cout << a[(i * size) + j] << ' ';
    }
    cout << endl;
  }
  cout << "----------------" << endl;
}

bool conflicts(int* a, int row, int col, const int size)
{
  for(int i = 0; i < size; i++)
  {
    if(a[row * size + i] == 1)
    {
      return false;
    }
  }
  return true;
}

void place_queens(int* a, int pos, const int size)
{
  if(pos < 0 || pos == size * size)
  {
    return;
  }
  
  place_queens(a, pos - size - 1, size);
  a[pos] = 1;

  print(a, size);
}
