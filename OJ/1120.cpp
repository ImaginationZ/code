#include <iostream>
#include <cstdio>
using namespace std;
struct node{
    int x;
    node* next;
};

void add( int k,node *&v ){
    node* tmp = new node;
    tmp->x = k;
    tmp->next = v->next;
    v->next = tmp;
}
int pp(node *&v){
    if( v->next == NULL ) return 0;
    return v->next->x;
}
void dele(node *&v){
    if( v->next == NULL ) return;
    node* tmp = v->next;
    v->next = tmp->next;
}

node *v[ 10005 ];
node *f[ 10005 ];

int main(int argc, char *argv[])
{
    int p=1;
    int n,k;
    int op,x;
    cin >> n >>k;
    for( int i=1;i<=n;++i ){
        f[ i ] = new node;
        v[ i ] = new node;
    }
    while( k-- ){
        //        cout <<"p="<<p<<endl;
        scanf( "%d",&op);
        switch( op ){
            case -1:
                ++p;
                break;
            case -2:
                --p;
                for (int i = 1; i <= n; ++i)
                {
                    if( pp( f[ i ] ) > p ){
                        dele( f[ i ] );
                        dele( v[ i ] );
                    }
                }
                break;
            case 0:
                scanf( "%d",&x );
                printf( "%d\n",pp( v[ x ] ) );
                break;
            default:
                scanf( "%d",&x );
                if( p > pp( f[ op ] ) ){
                    add( p,f[ op ] );
                    add( x,v[ op ]);
                }
                else if(v[op]->next!=NULL)
                    v[ op ]->next->x = x;
        }
    }
    return 0;
}
