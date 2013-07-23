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

    struct node{
        char op;
        int key;
    }

int main(){
    char input;
    MyStack<char> charpool;
    int p=0;
    node a[ MAX ];
    do{
        cin >> input;
        if(ifNumber( input )){
            if(p>0 && !a[ p-1 ].op ){
               a[ p-1 ].key *= 10;
               a[ p-1 ].key += input - '0';
            }
            else{
               a[ p ].op = 0;
               a[ p ].key = input - '0';
               ++p;
           }
        }
        else if( p=='(' ) charpool.add( p );
        else if( p==')' ){
            while( charpool.search()!='(' ){
                a[ p ] = charpool.search( );
                ++p;
                charpool.pop();
            }
            charpool.pop();
        }
    }
    return 0;  
}
