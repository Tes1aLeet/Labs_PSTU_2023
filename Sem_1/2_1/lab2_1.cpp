#include <iostream>

using namespace std;

int main()
{
	int N, res, temp;
	
	cin >> N;
	res = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		res += temp;
	}
	
	cout << res << endl;
	
	return 0;
}
