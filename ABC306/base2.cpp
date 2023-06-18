#include <math.h>
#include <iostream>
#include <string>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;
#define ull unsigned long long int

int main(){
    ull coeffs[64];
    for(int i=0; i<64;i++){
        cin >> coeffs[i];
    }
    ull ans = 0;
    for(int i=0; i<64;i++){
        ans += coeffs[i] * (ull) pow(2, i);
    }
    cout << ans << endl;
}