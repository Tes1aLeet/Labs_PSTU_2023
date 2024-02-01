#include <iostream>

using namespace std;

int main()
{
  const int SIZE = 5;

  bool organized = true;

  int a[SIZE] = {1,2,3,4,5};

  for (int i = 0; i < SIZE - 1; i++)
  {
    if (a[i] >= a[i + 1])
    {
      organized = false;
      break;
    }
  }
  if (organized)
  {
    cout << "массив упорядочен по возрастанию" << endl;
  }
  else
  {
    cout << "массив не упороядочен по возрастанию" << endl;
  }

  return 0;
}
