#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N >= 3)
	{
		for (int i = 1; i <= N; i++)
		{
			cout << '*';
		}
		
		cout << endl;
		
		for (int i = 1; i <= N - 2; i++)
		{
			cout << '*';
			for (int j = 1; j <= N - 2; j++)
			{
				cout << ' ';
			}
			cout << '*' << endl;
		}

		for (int i = 1; i <= N; i++)
		{
			cout << '*';
		}

		cout << endl;
	}

	return 0;
}
