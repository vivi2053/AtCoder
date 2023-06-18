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
    ll max_V = 100000;
    ll weights[N], values[N];
    rep(i, N){
        cin >> weights[i] >> values[i];
    }

    vector<vector<ll> > dp;
    rep(i, N+1){
        vector<ll> inner;
        rep(j, max_V+1){
            inner.pb(0);
        }
        dp.pb(inner);
    }

    rep2(i, 1, N+1){
        rep2(j, 1, max_V+1){
            if (j < values[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if (j == values[i-1]){
                if (dp[i-1][j] > 0){
                    dp[i][j] = min(dp[i-1][j], weights[i-1]);
                }
                else{
                    dp[i][j] = weights[i-1];
                }
            }
            else{
                if (dp[i-1][j-values[i-1]] > 0){
                    if (dp[i-1][j]>0){
                        dp[i][j] = min(dp[i-1][j], dp[i-1][j-values[i-1]]+weights[i-1]);
                    }
                    else{
                        dp[i][j] = dp[i-1][j-values[i-1]]+weights[i-1];
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }  

    

    for(int k=max_V;k>=0;k--){
        if (dp[N][k] > 0 and dp[N][k] <= W){
            cout << k << endl;
            return 0;
        }
    }

}