#include <iostream>

using namespace std;

int main()
{
  int n, temp;

  cin >> n;
  cout << endl;

  int a[150];

  for (int i = 0; i < n; i++)
  {
    a[i] = rand() % 100;
    cout << a[i] << endl;
  }
  
  cout << endl;

  for (int i = 0; i < n / 2; i++)
  {
    temp = a[n-i-1];
    a[n-i-1] = a[i];
    a[i] = temp;
  }

for (int i = 0; i < n; i++)
  {
    cout << a[i] << endl;
  }

  return 0;
}
