#include <iostream>
#include <time.h>

using namespace std;

void printArray(int* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main()
{
  int n, temp, p, q;

  cin >> n >> p >> q;
  cout << endl;

  int a[150];

  srand(time(NULL));

  for (int i = 0; i < n; i++)
  {
    a[i] = rand() % 90 + 10;
  }
  printArray(a, n);
  
  for (int i = p - 1; i <= q / 2; i++)
  {
    temp = a[q - i];
    a[q - i] = a[i];
    a[i] = temp;
    //printArray(a, n);
  }
  
  printArray(a, n);

  return 0;
}
