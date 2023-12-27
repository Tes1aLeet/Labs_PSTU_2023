#include <iostream>

using namespace std;

int main()
{
	float a,b;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "Деление на ноль!" << endl;
	}
	else
	{
		cout << a / b << endl;
	}
	return 0;
}
