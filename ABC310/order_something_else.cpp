#include <math.h>
#include <iostream>
#include <string>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;
// #define ull unsigned long long;

int main(){
    int N, P, Q, temp;
    cin >> N >> P >> Q;
    int min_price = 10e6;
    rep(i, N){
        cin >> temp;
        min_price = min(min_price, temp);
    }
    min_price += Q;
    if (min_price < P){
        cout << (min_price) << endl ;
    }
    else{
        cout << (P) << endl ;
    }
}