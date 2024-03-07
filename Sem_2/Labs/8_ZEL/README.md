Анисимов Дмитрий Александрович 

ИВТ-23-1б

# 1 Вариант задания

Лабораторная работа № 8, вариант 3

**Блоковый ввод-вывод**

Задание:

Структура "Государство":
- название;
- столица;
- численность населения;
- занимаемая площадь.
<br/>
Удалить все элементы, у которых численность меньше
заданной, добавить элемент после элемента с указанным номером.

# 2.1 Код программы

```c++
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node
{
  node* next = nullptr;
  node* prev = nullptr;

  string name;
  string capital;
  int population;
  float area;
};

struct list
{
  node* head = nullptr;
  node* tail = nullptr;
  int size = 0;

  // добавить элемент в конец списка
  void push(node* n);
  // удалить элемент index
  void remove(int index);
  // добавить элемент n после элемента index
  void add(node* n, int index);
  // записать список в файл
  void write(ofstream &out);
  // прочитать список из файла
  void read(ifstream &in);
  // вывести список
  void print();
};



void print_node(node* n)
{
  cout << n->name << endl
       << "    Столица:   " << n->capital << endl
       << "    Население: " << n->population << endl
       << "    Площадь:   " << n->area << endl << endl;
}

node* input_node()
{
  node* n = new node;

  string s;
  int i;
  float f;

  cout << "Название страны: ";
  cin >> s;
  n->name = s;

  cout << "Столица: ";
  cin >> s;
  n->capital = s;

  cout << "Население: ";
  cin >> i;
  n->population = i;

  cout << "Площадь: ";
  cin >> f;
  n->area = f;

  return n;
}



void list::push(node* n)
{
  if(size == 0)
  {
    head = n;
    tail = n;

    n->prev = nullptr;
    n->next = nullptr;

    size = 1;
  }
  else
  {
    n->prev = head;

    head->next = n;

    head = n;

    size++;
  }
}



void list::remove(int index)
{
  if(index > size || index < 1)
  {
    cout << "Элемента с таким номером нет!" << endl;
    return;
  }

  if(size == 1)
  {
    delete tail;
    tail == nullptr;
    head == nullptr;

    size = 0;

    return;
  }

  node* temp = tail;

  for(int i = 1; i < index; i++)
  {
    temp = temp->next;
  }

  if(temp->next == nullptr)
  {
    temp->prev->next = nullptr;
    head = temp->prev;
  }
  else
  {
    if(temp->prev != nullptr)
    {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
    }
  }

  if(temp->prev == nullptr)
  {
    temp->next->prev = nullptr;
    tail = temp->next;
  }
  else
  {
    if(temp->next != nullptr)
    {
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
    }
  }

  size--;

  delete temp;
}



void list::add(node* n, int index)
{

  node* temp = tail;

  for(int i = 1; i < index; i++)
  {
    temp = temp->next;
  }

  if(temp->next == nullptr)
  {
    head->next = n;

    n->prev = head;

    head = n;
  }
  else
  {
    n->prev = temp;
    n->next = temp->next;

    temp->next->prev = n;
    temp->next = n;

  }

  size++;
}



void list::print()
{
  if(size > 0)
  {
    node* temp = tail;
    cout << "1 ";
    print_node(temp);

    for(int i = 1; i < size; i++)
    {
      cout << i + 1 << ' ';
      temp = temp->next;
      print_node(temp);
    }
  }
  else
  {
    cout << "Список пуст!" << endl;
  }
}



void list::write(ofstream &out)
{
  if(size > 0)
  {
    node* temp = tail;
    out << temp->name << endl << "    Столица:   " << temp->capital << endl
        << "    Население: " << temp->population << endl << "    Площадь:   " << temp->area << endl << endl;

    for(int i = 1; i < size; i++)
    {
      temp = temp->next;
      out << temp->name << endl << "    Столица:   " << temp->capital << endl
          << "    Население: " << temp->population << endl << "    Площадь:   " << temp->area << endl << endl;
    }
  }
}



void list::read(ifstream &in)
{
  node* temp;

  string line;
  int i;
  float f;

  while(!in.eof() && in.peek() != -1)
  {
    temp = new node;

    // получаем название города
    in >> line;
    if(in.peek() == -1) break; // если конец файла - выходим из цикла
    temp->name = line;

    // получаем столицу
    in >> line >> line;
    temp->capital = line;

    // получаем население
    in >> line;
    in >> i;
    temp->population = i;

    // получаем площадь
    in >> line;
    in >> f;
    temp->area = f;

    // добавляем страну в список
    push(temp);
  }
}



int main()
{
  // открытие файла для чтения
  ifstream in;
  in.open("F1");

  if(!in)
  {
    cerr << "Cannot open file F1" << endl;
    return 1;
  }

  list countries;
  countries.read(in);
  countries.print();

  in.close();

  // все изменения списка стран происходят здесь

  // удалить все страны, насление которых меньше определенного значения
  cout << "Удалить страны, население которых меньше: ";

  int min_population;
  cin >> min_population;

  node* temp = countries.tail;

  for(int i = 1; temp != nullptr; i++)
  {
    if(temp->population < min_population)
    {
      temp = temp->next;
      countries.remove(i);
      i--;
    }
    else
    {
      temp = temp->next;
    }
  }

  countries.print();

  // добавить элемент после элемента с указанным номером
  cout << "После какого элемента вставить новый элемент: ";

  int index;
  cin >> index;

  if(index > countries.size || index < 1)
  {
    cout << "Нет такого элемента!" << endl;
  }
  else
  {
    countries.add(input_node(), index);
  }

  cout << endl << "Запись в файл F2: " << endl;
  countries.print();

  // открытие файла для записи
  ofstream out;
  out.open("F2");

  if(!out)
  {
    cerr << "Cannot open file F2" << endl;
    return 1;
  }

  countries.write(out);
  out.close();

  return 0;
}
```

# 2.2 Блок-схема

<image src="block_diagram.png">

# 3 Тесты

<image src="test_1.png">
<image src="test_2.png">
<image src="test_3.png">

F1
```
England
    Столица:   London
    Население: 56536419
    Площадь:   132930

Russia
    Столица:   Moscow
    Население: 146447424
    Площадь:   1.70982e+07

France
    Столица:   Paris
    Население: 62814233
    Площадь:   643801

Italy
    Столица:   Rome
    Население: 58853482
    Площадь:   301340

Japan
    Столица:   Tokyo
    Население: 125416877
    Площадь:   377975
```

F2
```
Russia
    Столица:   Moscow
    Население: 146447424
    Площадь:   1.70982e+07

Finland
    Столица:   Helsinki
    Население: 5568637
    Площадь:   338145

France
    Столица:   Paris
    Население: 62814233
    Площадь:   643801

Japan
    Столица:   Tokyo
    Население: 125416877
    Площадь:   377975
```
