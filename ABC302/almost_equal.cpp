#include <iostream>
#include <string>
#include <vector>
// #include <set>
#define vs vector<string>
#define vi vector<int>
#define vvs vector<vs>
#define pb push_back
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;
#define ll long long


bool check_all(vvs& strs, idx, intvisited)


int main(){
    int N, M;
    cin >> N >> M;
    char temp;
    vvs strs;
    rep(i, N){
        vs row;
        rep(j, M){
            cin >> temp;
            strs[i][j].pb(string(1, temp));
        }
        strs.pb(row);
    }

    int visited[N];
    rep(i, N){
        visited[i] = 0;
    }
    check_all(strs, 0, visited);
}