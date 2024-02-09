#include <iostream>

using namespace std;

int fibonacci(int n)
{
  if(n == 1)
  {
    return 1;
  }
  else if(n == 0)
  {
    return 0;
  }
  else
  {
    return fibonacci(n - 2) + fibonacci(n - 1);
  }
}

int main()
{
  int a;

  cin >> a;

  cout << fibonacci(a) << endl;  

  return 0;
}
