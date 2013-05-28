#include <iostream>
#include <cmath>
using namespace std;


int main(){
    long long number,pride,times;
    cin >> number;
    cout <<number << '=';
    for (pride = 2;pride <= sqrt(number);++pride){
        times = 0;
        while (number % pride == 0){
            number /= pride;
            ++times;
        }
        if (times > 0) cout << pride << '(' << times <<')';
    }
        if (number > 1) cout << number << '(' << 1 <<')' <<endl;
    return 0;

}
