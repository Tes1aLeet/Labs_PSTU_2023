# Двумерный массив (матрица)

Выше главной диагонали 0, главная диагональ и ниже - цифры по шаблону

```c++
#include <iostream>

using namespace std;

int main()
{
	const int n = 11;

	int number;
	int a[n][n] = {};

	for (int i = 0; i < n; i++)
	{
		number = 1;
		for (int j = n-1; j >= 0; j--)
		{
			if (j <= i)
			{
				a[i][j] = number;
				number++;
				if (number == 10)
        {
          number = 1;
        }
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
```
