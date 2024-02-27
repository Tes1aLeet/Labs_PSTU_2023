Анисимов Дмитрий Александрович 

ИВТ-23-1б

# 1 Вариант задания

Лабораторная работа №6, вариант 3

**Работа с одномерными массивами**

Задание:

Напечатать все слова, которые не содержат гласных букв.

# 2 Код программы 

```c++
#include <iostream>
#include <string.h>
#define SIZE 255

using namespace std;

void Gets(char* s)
{
  char temp;

  for(int i = 0; i < SIZE; i++)
  {
    cin.get(temp);

    if(temp == '.')
    {
      s[i] = ' ';
      break;
    }

    s[i] = temp;
  }
}

bool isVowel(char ch)
{
  switch(ch)
  {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
      return true;
    default:
      return false;
  }
}

void print(char* s, int start, int end)
{
  for(int i = start; i <= end; i++)
  {
    cout << s[i];
  }
  cout << endl;
}

int main()
{
  char s[SIZE] = {};

  int start = 0;
  bool hasVowels = false;

  Gets(s);

  for(int i = 0; i < SIZE - 1; i++)
  {
    if(s[i] == ' ')
    {
      start = i + 1;
      hasVowels = false;
    }
    else if(s[i + 1] == ' ')
    {
      if(isVowel(s[i]))
      {
        hasVowels = true;
      }
      if(!hasVowels)
      {
        print(s, start, i);
      }
    }
    else
    {
      if(isVowel(s[i]))
      {
        hasVowels = true;
      }
    }
  }

  return 0;
}
```

# 3 Тесты

<image src="test.png">
