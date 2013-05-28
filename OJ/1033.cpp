#include <iostream>
#include <alogrithm>
#include <string>

using namesapce std;

const int MAX = 110;

template <class T>
class MyStack{
private:
  T p*;
  long size;
  long capasity;
  void resize()
  {
    capasity *= 2;
    T tmp* = p;
    p = new T[capasity];
    for (long i = 0;i < size;++i)
      *p = *tmp;
    delete tmp[];
  }
  
    
public:
  Mystack()
  {
    size = 0;
    capasity = 8;
    p = new T[capasity];
  }
  
  ~MyStack()
  {
    delete p[];
  }
  
  void add(T a)
  {
    if(size < capasity)
      {
	p[size] = a;
	++size;
      }
    else 
      {
	resize();
	p[size] = a;
	++size;
      }
  }
    
  bool pop()
  {
    if(size>0)
      {
	--size;
	return 1;
      }
    else return 0;
  }
  
  T search()
  {
    return p[size];
  }
  
  long AskSize()
  {
    return size;
  }
  
}

  bool ifNumber(char a)
  {
    return(0<=a-'0'&&a-'0'<10)? 1:0;
  }

int main(){
  char express[MAX];
  MyStack<long long> number;
  MyStack<char>  op;
  long long ans;
  cin.getline(express);
  char *p = express;
  while (*p != 0)
    {
      if(ifNumber(*p))
	{
	  long num = 0;
	  while (ifNumber(*p))
	    {
	      num *= 10;
	      num += *p - '0';
	      ++p;
	    }
	  number.add(num);
	}
      if(*p != ' ')
	{
	  op.add(*p);
	}
      if(*p == ' ')
	++p;
   }
  
}
