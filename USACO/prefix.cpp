/*
ID: frequen1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX = 1<<30;

ifstream fin ("prefix.in");
ofstream fout ("prefix.out");

string prim[300];
string seq = "";
bool enable[200000];

int n = 0;

int main(int argc, char *argv[])
{
  while(true)
    {
      fin >> prim[n];
      if(prim[n]==".") break;
      ++n;
    }
  string in;
  while(fin>>in){
    seq.append(in);
  }
  enable[0] = 1;
  int longest = 0;
  int ans = 0;
  int max = seq.length();
  while(longest < max){
    int found = 0;
    string text;
    int p;
    queue<int> q;
    for (int i = 0; i < n; ++i)
      {
        q.push(i);
      }
    for (int i = longest; i >= 0; --i)
      {
        text.append(seq.substr(i,1));
        //        cout << "start from "<<longest+1 <<" text is "<<text << endl;
        bool flag = 0;
        queue<int> tmp;
        p = longest - i;
        while(!q.empty()){
          int now = q.front();
          q.pop();
          if (prim[now][prim[now].size()-p-1]==seq[i]){
            if(prim[now].size()-p-1==0 && enable[i]){
              ans = longest + 1;
              // cerr << "here " << ans << endl;
              enable[ans] = 1;
              break;
            }
            else tmp.push(now);
            //  cout << prim[now]<< endl;
          }
        }
        if(tmp.empty()) break;
        if(enable[longest+1]) break;
        q = tmp;
      }
    longest++;
  }
  
  fout << ans << endl;
  return 0;
}

