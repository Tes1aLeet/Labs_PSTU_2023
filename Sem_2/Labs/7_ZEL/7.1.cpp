#include <iostream>
#include <complex>

using namespace std;

complex<double> multiply(complex<double> n1, complex<double> n2)
{
  return n1 * n2;
}

int multiply(int n1, int n2)
{ 
  return n1 * n2;
}

int main()
{
  complex<double> n1 = 1.0 + 2i, n2 = 1.0 - 2i;

  cout << "(1 + 2i) * (1 - 2i) = " << multiply(n1, n2) << endl;

  cout << "7 * 8 = " << multiply(7,8) << endl; 

  return 0;
}
