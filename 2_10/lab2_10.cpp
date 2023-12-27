#include <iostream>

using namespace std;

int main()
{
	int a,max,quantity;
	
	cin >> quantity;
	
	max = -2147483648;
	for (int i = 0; i < quantity; i++)
	{
		cin >> a;
		if (a > max)
		{
			max = a;
		}
	}

	cout << max << endl;

	return 0;
}
