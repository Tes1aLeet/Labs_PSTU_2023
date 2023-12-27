#include <iostream>

using namespace std;

int main()
{
	int a,b;
	bool isOrganized = true;

	cin >> a;

	while (a != 0)
	{
		b = a;
		cin >> a;
		if (a <= b && a != 0)
		{
			isOrganized = false;
		}
	}

	if (isOrganized)
	{
		cout << "Последовательность возрастает" << endl;
	}
	else
	{
		cout << "Последовательность не возрастает" << endl;
	}

	return 0;
}
