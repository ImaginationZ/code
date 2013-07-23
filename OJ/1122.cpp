#include<iostream>
using namespace std;
struct Node{
    int a,b,left,right,cover;
};
Node tnode[500005];
int Number,Tot,c,d;
void build(int a,int b){
    int Now;
    Tot++;
    Now=Tot;
    tnode[Now].a=a;
    tnode[Now].b=b;
    tnode[Now].cover=0;
    if(b-a>1){
        int mid=(a+b)>>1;
        tnode[Now].left=Tot+1;
        build(a,mid);
        tnode[Now].right=Tot+1;
        build(mid,b);
    }
}

void dele( int a,int b ){
    

}

void insert(int Num){
    if(c<=tnode[Num].a&&tnode[Num].b<=d)
        tnode[Num].cover++;
    else{
        int mid=(tnode[Num].a+tnode[Num].b)>>1;
        if(c<=mid)
            insert(tnode[Num].left);
        if(d>=mid)
            insert(tnode[Num].right);
    }
}
void del(int Num){
    if(c<=tnode[Num].a&&tnode[Num].b<=d)
        tnode[Num].cover--;
    else{
        int mid=(tnode[Num].a+tnode[Num].b)>>1;
        if(c<=mid)
            del(tnode[Num].left);
        if(d>=mid)
            del(tnode[Num].right);
    }
}
void Count(int Num){
    if(tnode[Num].cover)
        Number+=(tnode[Num].b-tnode[Num].a);
    else{
        if(tnode[Num].left)
            Count(tnode[Num].left);
        if(tnode[Num].right)
            Count(tnode[Num].right);
    }
}
int main()
{
    
    return 0;
}
