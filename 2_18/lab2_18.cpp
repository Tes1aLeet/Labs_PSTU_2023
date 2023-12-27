#include <iostream>

using namespace std;

int main()
{
	int n,n_reversed;
	n_reversed = 0;

	cin >> n;

	while (n > 0)
	{
		n_reversed = n_reversed * 10 + n % 10;
		n /= 10;
	}

	cout << n_reversed << endl;

	return 0;
}
