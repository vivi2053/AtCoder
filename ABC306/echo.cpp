#include <iostream>
#include <string>
// #include <set>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;

int main(){
    string input_str;
    int len;
    cin >> len;
    cin >> input_str;

    for(int i=0; i<len;i++){
        cout << input_str[i] << input_str[i];
    }
    cout << endl;
}