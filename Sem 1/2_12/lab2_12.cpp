#include <iostream>

using namespace std;

int main()
{
	int N,max,min,a;
	max = 0x80000000;			// min int32 value
	min = 0x7fffffff;			// max int32 value

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}

	cout << max + min << endl;

	return 0;
}
