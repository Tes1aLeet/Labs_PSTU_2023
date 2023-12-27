#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N > 2)
	{
		for (int i = 1; i <= N - 1; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << '*';
			}
			cout << endl;
		}
	}

	return 0;
}
