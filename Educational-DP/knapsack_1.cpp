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
    ll N, W;
    cin >> N >> W;
    ll weights[N], values[N];
    rep(i, N){
        cin >> weights[i] >> values[i];
    }

    vector<vector<ll> > dp;
    rep(i, N+1){
        vector<ll> inner;
        rep(j, W+1){
            inner.pb(0);
        }
        dp.pb(inner);
    }

    rep2(i, 1, N+1){
        rep2(j, 1, W+1){
            if (j < weights[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if (j == weights[i-1]){
                dp[i][j] = max(dp[i-1][j], values[i-1]);
            }
            else{
                if (dp[i-1][j-weights[i-1]] > 0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]]+values[i-1]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }  

    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;

}