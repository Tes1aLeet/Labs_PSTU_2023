#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	if (N >= 4)
	{
		N = sqrt(N);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << '*';
			}
			cout << endl;
		}
	}

	return 0;
}
