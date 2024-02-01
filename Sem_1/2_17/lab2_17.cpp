#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N;
	float x, sum, factorial;
	sum = 1;
	factorial = 1;

	cin >> N >> x;

	for (int i = 1; i < N; i++)
	{
		factorial *= i;
		sum += pow(x,i) / factorial;
	}

	cout << sum << endl;

	return 0;
}
