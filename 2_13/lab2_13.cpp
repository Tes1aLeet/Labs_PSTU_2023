#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float x1,x2,a,b,c,D;

	cout << "[a]x^2 + bx + c = 0" << endl
	     << "Введите коэффициент a: ";
	cin >> a;

	cout << endl << "ax^2 + [b]x + c = 0" << endl
	     << "введите коэффициент b: ";
	cin >> b;

	cout << endl << "ax^2 + bx + [c] = 0" << endl
	     << "Введите коэффициент c: ";
	cin >> c;
	cout << endl;

	D = pow(b, 2) - 4 * a * c;

	if (D > 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);

		cout << "x1 = " << x1 << endl
		     << "x2 = " << x2 << endl;
	}
	else if (D == 0)
	{
		x1 = (-b) / (2 * a);

		cout << "x = " << x1 << endl;
	}
	else
	{
		cout << "Корней нет" << endl;
	}

	return 0;
}
