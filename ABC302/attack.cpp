#include <iostream>
#include <string>
// #include <set>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;
#define ll long long



int main(){
    ll A, B;
    cin >> A;
    cin >> B;
    if (A%B == 0){
        cout << (A/B) << endl;
    }
    else{ 
        cout << (A/B) + 1 << endl;
    }
    
    
}