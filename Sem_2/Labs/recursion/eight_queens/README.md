# Задача о расстановке 8 ферзей

На стандартной шахматной доске 8х8 необходимо разместить 8 ферзей так, чтобы ни один из них не был под ударом другого.

Ферзь бьет все клетки по вертикалям, горизонталям и обеим диагоналям.

Первый ферзь ставится случайно.

# Код программы

```c++
#include <iostream>
#include <time.h>

using namespace std;

void print(int* a, const int size);

bool conflicts(int* a, int pos, const int size);

bool place_queens(int* a, int current_line, const int size);

int main()
{
  const int SIZE = 8;

  // массив позиций ферзей (индекс - номер строки, значение - позиция (порядковый номер - 1, если считать фигуры слева направо сверху вниз) ) 
  // массив всегда должен быть упорядочен от меньшего к большему (от самого маленького значения позиции к самому большому)
  // если значение = -1, то клетка пустая, все клетки после нее не обрабатываются
  int queens[SIZE] = {};

  for(int i = 1; i < SIZE; i++)
  {
    queens[i] = -1;
  }

  srand(time(NULL));
  queens[0] = rand() % SIZE;
  

  if(!place_queens(queens, 1, SIZE))
  {
    cout << "Решения не существует" << endl;
  }

  return 0;
}

// выводит игровое поле, с ферзями из массива a, размером size
// если массив a не отсортирован, работает некорректно
void print(int* a, const int size)
{
  int current_queen = 0;
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(a[current_queen] == j + (i * size) )
      {
        cout << '@' << ' ';
        current_queen++;
      }
      else
      {
        cout << '-' << ' ';
      }
    }
    cout << endl;
  }
  cout << endl;
}

// true:  если в массиве a, размером size, есть ферзь, который конфликтует с ферзем, с позицией pos
// false: если конфликтующих ферзей нет
bool conflicts(int* a, int pos, const int size)
{
  int a_pos, a_col, a_row, row, col;
 
  row = pos / size; // строка ферзя, конфликты с которым мы ищем
  col = pos % size; // его столбец
  
  for(int i = 0; i <= size; i++)
  {
    if(a[i] == -1) // если клетка пустая, то ферзей больше нету, следовательно конфилктов не будет. прерываем цикл
    {
      break;
    }
    else if(a[i] == pos) // если ищем конфликты ферзя самим с собой, пропускаем 1 итерацию цикла
    {
      continue;
    }

    a_pos = a[i];         // позиция ферзя, уже стоящего на поле
    a_row = a_pos / size; // его строка
    a_col = a_pos % size; // его столбец

    if(a_row == row || a_col == col) // если в одной строке или в одном столбце
    {
      return true;
    }
    if(a_col - col == a_row - row || a_col - col == row - a_row)  // если на одной диагонали
    {
      return true;
    }
  }
  return false;
}

// true:  если с текущей расстановкой ферзей возможно заполнить все строки до current_line
// false: если невозможно
bool place_queens(int* a, int current_line, const int size)
{
  if(current_line == size) // если все ферзи расставлены
  {
    return true;
  }
  
  // i - номер столбца, в которую пробуем ставить ферзя
  for(int i = 0; i < size; i++)
  {
    // если в клетке (current_line + 1, i + 1) на доске можно поставить ферзя
    if(!conflicts(a, (current_line * size) + i, size))
    {
      // то ставим ферзя
      a[current_line] = i + (current_line * size);
      print(a, size);

      // если при текущей расстановке ферзей, можно расставить все оставшиеся ферзи
      if(place_queens(a, current_line + 1, size))
      {
        // то оставляем все как есть
        return true;    
      }
      
      // если нет - то, убираем ферзя в текущей клетке, и пробуем следующую
      a[current_line] = -1;
    }
  }
  
  // если невозможно заполнить доску, при текущей расстановке, возвращаем false
  return false;
}
```
