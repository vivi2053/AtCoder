#include <vector>
#include <iostream>
#include <iomanip>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long


int main(){
    int N;
    double in_;
    cin >> N;
    double hprobs[N+1], tprobs[N+1];
    double dp[N+1][N+1];
    rep2(i, 1, N+1){
        cin >> in_;
        hprobs[i] = in_;
        tprobs[i] = 1 - in_;
    }

    dp[0][0] = 1;
    rep2(i, 1, N+1){
        dp[0][i] = tprobs[i] * dp[0][i-1];
        rep2(j, 1, i+1){
            dp[j][i] = tprobs[i] * dp[j][i-1] + hprobs[i]* dp[j-1][i-1];
        }
    }
    double answer = 0;
    rep2(i, N/2 + 1, N+1){
        answer += dp[i][N];
    }
    cout << setprecision(9) << answer << endl;

    // rep2(i, 1, N+1){
    //     rep2(j, 1, i+1){
    //         cout << std::setprecision(4) << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    
}