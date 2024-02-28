#include <iostream>
#include <time.h>

using namespace std;

// удаляет в массиве а, размером size, элемент с индексом n и сдвигает все элементы после него влево на 1
void delete_element(int* a, int n, int size)
{
  for(int i = n + 1; i < size; i++)
  {
    a[i - 1] = a[i];
  }
}

int main()
{
  srand(time(NULL));

  int size, k, n, e, e_pos;

  cout << "Введите размер массива: " << endl;
  cin >> size;

  cout << "Удалить сколько элементов? " << endl;
  cin >> k;

  cout << "Удалить, начиная с какого элемента? " << endl;
  cin >> n;

  cout << "На какую позицию поместить новый элемент? " << endl;
  cin >> e_pos;

  cout << "Введите значение (целое число) нового элемента: " << endl;
  cin >> e;
  cout << endl;

  int *p = new int [size];

  // заполняем массив случайными числами
  for(int i = 0; i < size; i++)
  {
    p[i] = rand() % 10;
    cout << p[i] << ' ';
  }
  cout << endl;

  // удаляем k элементов, начиная с элемента с индексом n - 1
  for(int i = 0; i < k; i++)
  {
    delete_element(p, n - 1, size);
  }
  cout << endl;

  // создаем уменьшенный массив, в соответствии с тем, сколько элементов удалили
  int *p1 = new int [size - k];

  // переносим все в новый уменьшенный массив
  for(int i = 0; i < size - k; i++)
  {
    p1[i] = p[i];
    cout << p1[i] << ' ';
  }
  cout << endl << endl;

  // освобождаем память, выделенную под изначальный массив
  delete p;

  // если новый элемент находится вне массива
  if(e_pos > size - k)
  {
    // то создаем массив, размером e_pos
    p = new int [e_pos];

    // переносим туда новый элемент
    p[e_pos - 1] = e;

    // переносим все элементы из массива p1
    for(int i = 0; i < size - k; i++)
    {
      p[i] = p1[i];
    }
    
    // меняем для удобства
    size = e_pos;
  }
  else
  {
    // меняем для удобства
    size = size - k + 1;

    // увеличенный массив, чтобы вместить новый элемент
    p = new int [size];

    // переносим из массива p1 в массив p все элементы, которые идут до нового элемента
    for(int i = 0; i < e_pos - 1; i++)
    {
      p[i] = p1[i];
    }

    // переносим из массива p1 в массив p все элементы, которые идут после нового элеметна, сдвигаем их на 1 вправо
    for(int i = e_pos; i < size - 1; i++)
    {
      p[i] = p1[i - 1];
    }

    // переносим новый элемент
    p[e_pos - 1] = e;
  }

  delete p1;

  // выводим результат
  for(int i = 0; i < size; i++)
  {
    cout << p[i] << ' ';
  }
  cout << endl;

  delete p;

  return 0;
}
