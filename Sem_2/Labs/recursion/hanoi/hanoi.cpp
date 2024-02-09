#include <iostream>

using namespace std;

// высота башен
const int SIZE = 3;

int rod1[SIZE] = {};
int rod2[SIZE] = {};
int rod3[SIZE] = {};

void print(int* a, int* b, int* c, const int size);

void move_disk(int n, int* from, int* to, const int size);

void hanoi_tower(int n, int* from, int* to, int* aux, const int size);

int main()
{

  for(int i = 0; i < SIZE; i++)
  {
    rod1[i] = SIZE - i;
  }
  
  print(rod1, rod2, rod3, SIZE);
  
  hanoi_tower(SIZE, rod1, rod2, rod3, SIZE);

  return 0;
}

void print(int* a, int* b, int* c, int size)
{
  for(int i = size - 1; i >= 0; i--)
  {
    cout << a[i] << "  " << b[i] << "  " << c[i] << endl;
  }
  cout << endl;
}

void move_disk(int n, int* from, int* to, const int size)
{
  for(int i = 0; i < size; i++)
  {
    // ищем свободное место
    if(to[i] == 0)
    {
      to[i] = n + 1;

      // удаляем то, что передвинули
      for(int j = size - 1; j >= 0; j--)
      {
        if(from[j] == n + 1)
        {
          from[j] = 0;
        }
      }

      print(rod1, rod2, rod3, size);

      break;
    }
  }
  

}

void hanoi_tower(int n, int* from, int* to, int* aux, const int size)
{
  if(n == 0)
  {
    return;
  }

  hanoi_tower(n - 1, from, aux, to, size);

  move_disk(n - 1, from, to, size);

  hanoi_tower(n - 1, aux, to, from, size);
}
