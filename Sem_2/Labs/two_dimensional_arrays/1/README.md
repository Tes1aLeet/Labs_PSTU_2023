Анисимов Дмитрий Александрович

ИВТ-23-1б

# 1 Вариант задания

Лабораторная работа

**Заполнение в шахматном порядке**

# 2.1 Код программы

```c++
#include <iostream>

using namespace std;

int main()
{
  const int ROWS    = 10;   // количество строк
  const int COLUMNS = 10;   // колчиество столбцов
  const int MAX     = 9;    // цифры - [1 ... MAX]

  int a[ROWS][COLUMNS];

  int current_number = 1;

  for(int i = 0; i < ROWS; i++)
  {
    for(int j = 0; j < COLUMNS; j++)
    {
      if( (i + j) % 2 == 0)
      {
        a[i][j] = current_number % (MAX + 1);
        current_number++;

        if(current_number % (MAX + 1) == 0)
        {
          current_number++;
        }
      }
      else
      {
        a[i][j] = 0;
      }
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
```

# 2.2 Блок-схема

# 3 Тесты

<image src="test.png">
