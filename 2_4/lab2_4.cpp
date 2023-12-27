#include <iostream>

using namespace std;

int main()
{
	int N;
	
	cin >> N;

	if (N > 3 && N % 2 == 1)
	{
		for (int a = 1; a <= N / 2; a ++)
		{
			cout << ' ';
		}
		cout << '*' << endl;
		
		for (int b = 2; b <= N / 2; b++)
		{
			for (int c = 1; c <= ((N / 2) + 1) - b; c++)
			{
				cout << ' ';
			}
			
			cout << '*';

			for (int d = 1; d <= (b * 2) - 3 ; d++)
			{
				cout << ' ';
			}

			cout << '*';

			cout << endl;
		}
		
		for (int f = 1; f <= N; f++)
		{
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}
