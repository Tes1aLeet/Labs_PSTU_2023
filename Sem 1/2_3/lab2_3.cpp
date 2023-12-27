#include <iostream>

using namespace std;

int main()
{
	int N,S,temp;

	cin >> N;

	S = 0;

	for (int a = 1; a <= N ; a++)
	{
		temp = a;
		for (int b = a + 1; b <= a * 2; b++)
		{
			temp *= b;
		}
		S += temp;
	}
	
	cout << S << endl;

	return 0;
}
