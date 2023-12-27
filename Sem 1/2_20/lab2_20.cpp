#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	bool numberFound = false;
	float n,s,precision;

	precision = 0.01;

	cin >> n >> s;

	for (int i = 1; (i <= n) && (!numberFound); i++)
	{
		if (abs(sin(n + i / n) - s) < precision)
		{
			numberFound = true;
			cout << "Номер первого подходящего элемента: "
			     << i << endl;
		}
	}

	if (!numberFound)
	{
		cout << "Элемент не найден" << endl;
	}

	return 0;
}
