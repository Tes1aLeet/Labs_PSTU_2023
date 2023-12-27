#include <iostream>

using namespace std;

int main()
{
	int a,quantity;
	bool firstIsNegative = false;
	bool firstIsPositive = false;

	cin >> quantity;

	for (int i = 0; i < quantity; i++)
	{
		cin >> a;
	
		if (!firstIsNegative && !firstIsPositive)
		{
			if (a > 0)
			{
				firstIsPositive = true;
			}
			else if (a < 0)
			{
				firstIsNegative = true;
			}
		}
	}

	if (firstIsPositive)
	{
		cout << "Первое - положительное" << endl;
	}
	else if (firstIsNegative)
	{
		cout << "Первое - отрицательное" << endl;
	}
	else
	{	
		cout << "Все нулевые" << endl;
	}

	return 0;
}
