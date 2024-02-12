#include <iostream>
#include <stdarg.h>

using namespace std;

int sum(int k, ...)
{
  int temp = 0;
  int sum = 0;

  va_list ptr;

  va_start(ptr, k);
  
  for(int i = 0; i < k / 2 + k % 2; i++)
  {
    temp = va_arg(ptr, int);
    
    if(i == k - 1)
    {
      sum += temp;
    }
    else
    {
      sum += temp * va_arg(ptr, int);
    }
  }
  va_end(ptr);

  return sum;
}

int main()
{
  cout << "sum(5, 1, 2, 3, 4, 5) = ";
  cout << sum(5, 1, 2, 3, 4, 5) << endl;
  cout << "sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = ";
  cout << sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
  cout << "sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) = ";
  cout << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;


  return 0;
}
