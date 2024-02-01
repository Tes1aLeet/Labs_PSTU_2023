#include <iostream>
#include <cmath>

using namespace std;

double get_value(double x)
{
  // y = 3sin(x) * sqrt(x) + 0.35x - 3.8
  return ( 3 * sin(x) * sqrt(x) ) + ( 0.35 * x ) - 3.8;
}
double get_derivative(double x)
{
  // y'= (1.5sin(x) + xcos(x)) / sqrt(x) + 0.35
  return ( ( 1.5 * sin(x) ) + ( x * cos(x) ) ) / sqrt(x) + 0.35;
}

int main()
{
  double currentIteration, lastIteration, precision;

  precision = 0.00001;

  currentIteration = 0.5;  //
  lastIteration    = 1.8;  //

  while(abs(currentIteration - lastIteration) > precision)
  {
    lastIteration = currentIteration;

    currentIteration = lastIteration - ( get_value(lastIteration) / get_derivative(lastIteration) );
  }

  cout.precision(10);   // 10 знаков после запятой

  cout << currentIteration << endl;

  return 0;
}
