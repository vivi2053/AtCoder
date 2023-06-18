#include <iostream>
#include <string>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;
// #define ll long long

int main(){
    int type[300000];
    int taste[300000];
    int N;
    cin >> N;
    rep(i, N){
        cin >> type[i] >> taste[i];
    }
    rep(i, N){
        cout << type[i] << taste[i] << endl;
    }

}