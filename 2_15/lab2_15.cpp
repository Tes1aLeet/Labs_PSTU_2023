#include <iostream>

using namespace std;

int main()
{
	int N;
	bool foundNumber = false;

	cin >> N;

	while(N > 0 && !foundNumber)
	{
		if (N % 10 == 5)
		{
			foundNumber = true;
		}
		N /= 10;
	}

	if (foundNumber)
	{
		cout << "Цифра " << S << " найдена" << endl;
	}
	else
	{
		cout << "Цифра " << S << " не найдена" << endl;
	}
	
	return 0;
}
