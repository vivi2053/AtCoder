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
    int set_size, t;
    vvi sos;
    rep(i, M){
        vi temp;
        cin >> set_size;
        rep(j, set_size){
            cin >> t;
            temp.pb(t);
        }
        sos.pb(temp);
    }

    rep(i, sos.size()){
        rep(j, sos[i].size()){
            cout << sos[i][j] << " ";
        }
        cout << endl;
    }

    
}