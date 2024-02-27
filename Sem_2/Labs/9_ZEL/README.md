Анисимов Дмитрий Александрович 

ИВТ-23-1б

# 1 Вариант задания

Лабораторная работа № 9, вариант 3

**Строковый ввод-вывод**

Задание:

1. Создать текстовый файл F1 не менее, чем из 10 строк и
записать в него информацию
2. Скопировать в файл F2 только те строки из F1, которые
начинаются и заканчиваются на одну и ту же букву
3. Подсчитать количество символов в F2

# 2.1 Код программы

```c++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  string s;

  ifstream in;
  in.open("F2");

  ofstream out;
  out.open("F1");

  while(getline(in, s))
  {
    if(s == "")
    {
      continue;
    }
    if(s.front() == s.back())
    {
      out << s << endl;
    }
  }

  in.close();
  in.open("F2");

  int counter = 0;
  char c;

  while(in.get(c))
  {
    counter++;
  }

  cout << "символов в файле F2: " << counter << endl;

  return 0;
}
```

# 2.2 Блок-схема

<image src="block_diagram.png">

# 3 Тесты

<image src="test.png">
