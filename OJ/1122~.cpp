#include <iostream>
using namespace std;

bool in[ 50005 ] = {0};

int lowbit( int x ){
    return x&( -x );
}

int sum( int end ){
    int sum = 0;
    while( end >0 ){
        sum += in[ end ];
        end -= lowbit( end );
    }
    return sum;
}

void plus( int pos, int num ){
    while( pos<=n ){
        in[ pos ] += num;
        pos += lowbit( pos );
    }
}

int main( )
{
    int op,x,y;
    cin >> n >> m;
    while( m-- ){
        cin >> op;
        if( op==1 ){
            cin >> x; 
        }
        else if( op==2 )
    }
    return 0;
}
