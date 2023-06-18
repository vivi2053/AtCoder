#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long


int main(){
    string s;
    cin >> s;
    string s_not = "";
    for(int i = 0;i<s.size();i++){
        if(s.substr(i, 1) == "1"){
            s_not += "0";
        }
        else{
            s_not += "1";
        }
    }
    cout << s_not << endl;
}