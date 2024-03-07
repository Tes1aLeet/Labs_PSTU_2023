#include <iostream>
#include <string>

using namespace std;

struct country
{
  string name    = " ";
  string capital = " ";

  int population = 0;
  float area = 0.0;
};


struct node
{
  node* next = nullptr;
  node* prev = nullptr;
  
  country data;
};


struct list
{
  node* head = nullptr;
  node* tail = nullptr;

  int size = 0;

  void init(char* name, char* capital, int population, float area);
};

void list::init(char* name, char* capital, int population, float area)
{

}

int main()
{
  list test;

  char name[2] = {'m','2'};

  test.init(name, name, 1, 1.1); 

  return 0;
};
