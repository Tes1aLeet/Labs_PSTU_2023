#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int max_i;
	float n,max;

	max = 0x80000000;			// int32 min value

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (sin(n + i / n) > max)
		{
			max = sin(n + i / n);
			max_i = i;
		}
	}

	cout.precision(24);
	cout << "Максимальный элемент последовательности: " << max
	     << endl << "  Его номер: " << max_i << endl;

	return 0;
}
