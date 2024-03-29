// вариант 3 
// S = x^3 / 3! + ... + (-1)^n * (x^(2n+1) / (2n+1)!)

#include <iostream>
#include <math.h>

using namespace std;

int factorial(int n)
{
  if(n <= 1)
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}

double find_sum(int x, int n)
{
  if(n == 0)
  {
    return x;
  }
  else
  {
    return pow(-1, n) * ((pow(x, (2 * n) + 1) / factorial((2 * n) + 1) )) + find_sum(x, n - 1);
  }
}

double solve(int x, int n)
{
  return pow(-1, n) * ((pow(x, (2 * n) + 1) / factorial((2 * n) + 1) ));
}

int main()
{
  int x, n;
  double sum = 0;

  cout << "x:";
  cin >> x;
  cout << "n:";
  cin >> n;

  cout.precision(15);

  cout << "S=" << find_sum(x, n) << " - рекурсия" << endl;

  for(int i = 0; i <= n; i++)
  {
    sum += solve(x, i);
  }

  cout << "S=" << sum << " - прямое вычисление функции" << endl;

  return 0;
}
