#include <iostream>
#include <time.h>

using namespace std;

void print(char* a, const int size);

void put_on_field(char* field, int pos, const int size);

bool conflicts(int* a, int pos, int n, const int size);

bool place_queens(int* a, char* field, int current, const int size);

int main()
{
  const int SIZE = 8;

  int queens[SIZE] = {};
  char field[SIZE][SIZE] = {};

  for(int i = 0; i < SIZE * SIZE; i++)
  {
    field[i / SIZE][i % SIZE] = '-';
  }

  srand(time(NULL));
  queens[0] = (rand() % SIZE) * SIZE;
  put_on_field(*field, queens[0], SIZE);

  print(*field, SIZE);
  place_queens(queens, *field, 0, SIZE);
  print(*field, SIZE);

  return 0;
}


void print(char* a, const int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      cout << a[(i * size) + j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}


void put_on_field(char* field, int pos, const int size)
{
  field[pos] = '@';
}


// true:  если в массиве a, размером size, в диапазоне [0;n] есть ферзь, который конфликтует с ферзем, с позицией pos
// false: если конфликтующих ферзей нет
bool conflicts(int* a, int pos, int n, const int size)
{
  int a_pos, a_col, a_row, row, col;
 
  row = pos / size;
  col = pos % size;
  
  for(int i = 0; i <= n; i++)
  {
    if(pos == a[i])
    {
      continue;
    }

    a_pos = a[i];
    a_row = a_pos / size;
    a_col = a_pos % size;

    if(a_row == row || a_col == col) // если в одной строке или в одном столбце
    {
      //cout << "conflict: (" << a_row + 1 << "; " << a_col + 1 << ") and (" << row + 1 << "; " << col + 1 << ") a_pos: " << a_pos << " pos: " << pos << endl;
      return true;
    }
    if(a_col - col == a_row - row || a_col - col == row - a_row)  // если на диагоналях
    {
      //cout << "conflict: (" << a_row + 1 << "; " << a_col + 1 << ") and (" << row + 1 << "; " << col + 1 << ") a_pos: " << a_pos << " pos: " << pos << endl;
      return true;
    }
  }

  return false;
}


bool place_queens(int* a, char* field, int current, const int size)
{
  static int pos;
  if(current == size - 1)
  {
    return true;
  }
  for(int i = 0; i < size; i++)
  {
    pos = (i * size) + current;
    if(!conflicts(a, pos + 1, current, size))
    {
      if(place_queens(a, field, current + 1, size))
      {
        a[current] = pos + 1;
        put_on_field(field, pos, size);
        print(field, size);
        cin.get();
      }
    }
  }

  return false;
}
