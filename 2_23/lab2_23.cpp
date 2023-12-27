#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int max_i,matches;
	float n,max;

	max = 0x80000000;			// int32 min value
	matches = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (sin(n + i / n) > max)
		{
			max = sin(n + i / n);
			max_i = i;
		}
	}


	for (int i = 1; i <= n; i++)
	{
		if (sin(n + i / n) == max)
		{
			matches++;
		}
	}

	cout << "Количество элементов, равных максимальному: " << matches 
	     << endl;

	return 0;
}
