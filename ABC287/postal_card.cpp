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
    int N, M;
    cin >> N >> M;
    string s[N];
    string t[M];
    rep(i, N){
        cin >> s[i];
    }
    rep(i, M){
        cin >> t[i];

    }
    string search_str;
    int total = 0;
    rep(i, N){
        search_str = s[i].substr(3, 3);
        rep(j, M){
            if(search_str == t[j]){
                total++;
                break;
            }
        }
    }
    cout << total << endl;

}