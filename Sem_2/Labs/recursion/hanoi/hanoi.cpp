#include <iostream>

using namespace std;

// вставить диск, размером n, в конец массива a, с размером size 
// если свободного места нет - возвращает false
bool push_back(int* a, int n, const int size)
{:
  for(int i = size - 1; i >= 0; i--)
  {
    if(a[i] == 0)
    {
      a[i] = n;
      return true;
    }
  }
  
  return false;
}

// убрать самый маленький диск
// false - если массив содержит только нули
bool pop_back(int* a, const int size)
{
  for(int i = 0; i < size; i++)
  {
    if(a[i] != 0)
    {
      a[i] = 0;
      return true;
    }
  }

  return false;
}

void print(int* a, int* b, int* c, int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << a[i] << "  " << b[i] << "  " << c[i] << endl;
  }
}

int main()
{
  const int SIZE = 3;

  int a[SIZE] = {};
  int b[SIZE] = {};
  int c[SIZE] = {};

  for(int i = 0; i < SIZE; i++)
  {
    a[i] = i + 1;
  }



  print(a, b, c, SIZE);

  return 0;
}
