#include <iostream>
#include <vector>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;
#define ll long long

int main(){
    int limit = 300000;
    int N;
    ll type[limit];
    ll taste[limit];
    vector<ll> healthy(limit);
    vector<ll> unhealthy(limit);
    cin >> N;
    ll zero_val = (ll) 0;

    rep(i, N){
        cin >> type[i] >> taste[i];
        healthy[i] = 0;
        unhealthy[i] = 0;
    }

    if (type[0] == 0){
        healthy[0] = max(zero_val, taste[0]);
    }
    else{
        unhealthy[0] = max(zero_val, taste[0]);
    }
    
    rep2(i, 1, N){
        if (type[i] == 0){
            healthy[i] = max(healthy[i-1], max(healthy[i-1]+taste[i], unhealthy[i-1]+taste[i]));
            unhealthy[i] = unhealthy[i-1];
        }
        else{
            unhealthy[i] = max(unhealthy[i-1], healthy[i-1]+taste[i]);
            healthy[i] = healthy[i-1];
        }
    }
    cout << max(healthy[N-1], unhealthy[N-1]) << endl;
}