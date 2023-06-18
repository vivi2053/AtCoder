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
    int H, W;
    cin >> H >> W;
    char in;
    int squares[H][W];
    ll dp[H+1][W+1];
    const ll modulo_num = 1000000007;
    char hash_ = '#';
    rep(i, H){
        rep(j, W){
            cin >> in ;
            if (in == hash_){squares[i][j] = 1;}
            else{ squares[i][j] = 0; }
            dp[i+1][j+1] = 0;
        }
    }
    
    rep(i, H+1){
        dp[i][0] = 0;
    }
    rep(j, W+1){
        dp[0][j] = 0;
    }

    // rep(i, H+1){
    //     rep(j, W+1){
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }

    dp[1][0] = 1;
    ll upper, left;

    rep2(i, 1, H+1){
        rep2(j, 1, W+1){
            if (squares[i-1][j-1] == 0){
                upper = dp[i-1][j];
                // cout << upper << endl;
                left = dp[i][j-1];
                // cout << left << endl;
                dp[i][j] = (upper + left) % modulo_num;
            }
        }
    }
    cout << dp[H][W] << endl;
}