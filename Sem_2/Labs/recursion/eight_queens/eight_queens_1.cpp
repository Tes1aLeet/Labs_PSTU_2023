#include <iostream>
#include <time.h>

using namespace std;

void print(int* a, const int size);

bool conflicts(int* a, int pos, const int size);

bool place_queens(int* a, char* field, int current, const int size);

int main()
{
  const int SIZE = 8;

  // массив позиций ферзей (индекс - номер строки, значение - позиция (порядковый номер - 1, если считать фигуры слева направо сверху вниз) ) 
  // всегда должен быть упорядочен от меньшего к большему (от самого маленького значения позиции к самому большому)
  // если значение = -1, то клетка пустая
  int queens[SIZE] = {};

  for(int i = 1; i < SIZE; i++)
  {
    queens[i] = -1;
  }

  srand(time(NULL));
  queens[0] = rand() % SIZE;

  print(queens, SIZE);

  return 0;
}

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
        cout << '*' << ' ';
        current_queen++;
      }
      else
      {
        cout << '_' << ' ';
      }
    }
    cout << endl;
  }
  cout << endl;
}

// true:  если в массиве a, размером size, в диапазоне [0;n] есть ферзь, который конфликтует с ферзем, с позицией pos
// false: если конфликтующих ферзей нет
bool conflicts(int* a, int pos, const int size)
{
  int a_pos, a_col, a_row, row, col;
 
  row = pos / size; // строка ферзя, конфликты с которым мы ищем
  col = pos % size; // его столбец
  
  for(int i = 0; i <= size; i++)
  {
    if(a[i] == -1) // если клетка пустая, ферзей больше нету, следовательно конфилктов не будет. прерываем цикл
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
      cout << "conflict: (" << a_row + 1 << "; " << a_col + 1 << ") and (" << row + 1 << "; " << col + 1 << ") a_pos: " << a_pos << " pos: " << pos << endl;
      return true;
    }
    if(a_col - col == a_row - row || a_col - col == row - a_row)  // если на одной диагонали
    {
      cout << "conflict: (" << a_row + 1 << "; " << a_col + 1 << ") and (" << row + 1 << "; " << col + 1 << ") a_pos: " << a_pos << " pos: " << pos << endl;
      return true;
    }
  }

  return false;
}


bool place_queens(int* a, int current_line, const int size)
{
  if(current_line == 0)
  {
    return true;
  }
  
  for(int i = 0; i < size; i++)
  {
    
  }

  return false;
}


// доходим до самой нижней строки
