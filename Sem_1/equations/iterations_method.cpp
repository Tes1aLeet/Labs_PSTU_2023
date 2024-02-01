/*
  f(x)  = 3sin(x) * sqrt(x) + 0.35x - 3.8
  f'(x) = 3sin(x)/2*sqrt(x) + 3sqrt(x)*cos(x) + 0.35

  a = 1 -> f'(a) =  3.23311 
  b = 2 -> f'(b) = -0.451106

  r = max( f'(a), f'(b) ) = 3.23311

  f'(x) > 0  ->  -1/r < lambda < 0 
                -0.30 < lambda < 0
  lambda = -0.25
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float currentIteration, previousIteration;

    double lambda = -0.25;
    double precision = 0.000001;
    
    currentIteration = 2;
    previousIteration = 0;

    while (abs(currentIteration - previousIteration) > precision)
    {
        previousIteration = currentIteration;
        
        currentIteration = lambda * ( 3*sin(previousIteration) * sqrt(previousIteration) + 0.35 * previousIteration - 3.8 ) + previousIteration;
    }
    cout << "x = " << currentIteration << endl;

    return 0;
}
