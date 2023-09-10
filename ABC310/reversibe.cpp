#include <math.h>
#include <iostream>
#include <string>
// #include <vector>
#include <unordered_set>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
// #define vi unordered_set<int>
// #define vvi vector<vi>
// #define pb push_back
using namespace std;

int main(){
    int N;
    string temp1, temp2;
    cin >> N;
    unordered_set<string> strings;
    rep(i, N){
        cin >> temp1;
        temp2 = temp1;
        reverse(temp2.begin(), temp2.end());
        if ((strings.find(temp1) == strings.end()) && (strings.find(temp2) == strings.end())){
            strings.insert(temp1);
        }
    }
    cout << strings.size() << endl;
}