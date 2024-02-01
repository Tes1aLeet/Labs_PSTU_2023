#include <iostream>

using namespace std;

int main()
{
	int N,sum;
	sum = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (i % 3 == 1)
		{
			sum -= -i; 
		}
		else
		{
			sum += i;
		}
	}

	cout << sum << endl;

	return 0;
}
