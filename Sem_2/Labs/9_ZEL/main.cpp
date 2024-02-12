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

  return 0;
}
