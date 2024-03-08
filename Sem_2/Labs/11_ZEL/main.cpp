#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node
{
  node* next = nullptr;

  int number;
};

struct list
{
  node* head = nullptr;
  node* tail = nullptr;

  int size = 0;

  // добавить элемент в конец списка
  void push(node* n);
  // удалить k элементов, начиная с элемента index
  void remove(int index, int k);
  // добавить элемент n после элемента с ключом key 
  void add(node* n, int key);
  // записать список в файл
  void write(ofstream &out);
  // прочитать список из файла
  void read(ifstream &in);
  // вывести список
  void print();
};


void list::push(node* n)
{
  if(size == 0)
  {
    head = n;
    tail = n;

    n->next = nullptr;
    
    size = 1;
  }
  else
  {
    head->next = n;
    head = n;
    size++;
  }
}


void list::remove(int index, int k)
{
  if(index + k - 1 > size || index < 1 || k < 1)
  {
    cout << "Нет такого элемента! " << endl;
    return;
  }

  node* temp = tail;

  node* start_of_deletion = tail;
  for(int i = 1; i < index; i++)
  {
    start_of_deletion = temp;
    temp = temp->next;
  }

  node* temp2;
  for(int i = 1; i < k + 1; i++)
  {
    temp2 = temp;
    temp = temp->next;

    delete temp2;
    size--;
  }
  
  if(size == 0)
  {
    head = nullptr;
    tail = nullptr;

    return;
  }
  else if(index == 1)
  {
    start_of_deletion = temp;
    tail = start_of_deletion;
  }
  else if(temp == nullptr)
  {
    head = start_of_deletion;
    head->next = nullptr;
  }
  else
  {
    start_of_deletion->next = temp;
  }
}



void list::add(node* n, int key)
{
  // ищем элемент с ключом key
  for(node* temp = tail; temp != nullptr; temp = temp->next)
  {
    // если нашли, то вставляем элемент, выходим из функции и увеличиваем размер списка
    if(temp->number == key)     
    {
      if(temp->next == nullptr)
      {
        head->next = n;
        head = n;
      }
      else
      {
        n->next = temp->next;
        temp->next = n;
      }
      size++;
      return;
    }
  }
  // если не нашли - ничего не делаем
  cout << "Элемента с ключом " << key << " нет!" << endl;
}


void list::print()
{
  if(size > 0)
  {
    for(node* temp = tail; temp != nullptr; temp = temp->next)
    {
      cout << temp->number << ' ';
    }
    cout << endl;
  }
}


void list::write(ofstream &out)
{
  if(size > 0)
  {
    for(node* temp = tail; temp != nullptr; temp = temp->next)
    {
      out << temp->number << ' ';
    }
  }
}


void list::read(ifstream &in)
{
  node* temp;

  int i;

  while(in.peek() != 10)
  {
    temp = new node;

    in >> temp->number;

    push(temp);
  } 
}


int main()
{
  list numbers;
  
  // открываем файл для чтения
  ifstream in;
  in.open("F1");

  if(!in)
  {
    cerr << "Cannot open file!" << endl;
  }

  numbers.read(in);
  cout << "Чтение из файла F1:" << endl;
  numbers.print();

  // задание
  // удалить К элементов после определенного номера элемента
  int index;
  cout << "Удалить начиная с какого элемента? ";
  cin >> index;

  int k;
  cout << "Удалить сколько элементов? ";
  cin >> k;

  numbers.remove(index, k);
  numbers.print();


  // добавить элемент после элемента с заданным ключом
  int key;
  cout << "После какого значения добавить элемент: ";
  cin >> key;

  int number;
  cout << "Значение нового элемента: ";
  cin >> number;

  node* tmp = new node;
  tmp->number = number;

  numbers.add(tmp, key);

  in.close();

  // открываем файл для записи

  ofstream out;

  out.open("F2");

  if(!out)
  {
    cerr << "Couldn't open file!" << endl;
  }

  cout << "Запись в файл F2: " << endl;
  numbers.print(); 

  numbers.write(out);

  out.close();

  return 0;
}
