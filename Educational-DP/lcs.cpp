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
    string s, t;
    cin >> s;
    cin >> t;

    int s_size = s.size();
    int t_size = t.size();

    vector<vector<int> > dp;
    rep(i, t_size+1){
        vector<int> temp;
        rep(j, s_size+1){
            temp.pb(0);
        }
        dp.pb(temp);
    }

    rep2(i, 1, t_size+1){
        rep2(j, 1, s_size+1){
            if(s.substr(j-1, 1) == t.substr(i-1, 1)){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    string ans = "";
    int i = t_size, j = s_size;

    while(j > 0 && i > 0){
        if ((s.substr(j-1, 1) == t.substr(i-1, 1)) && (dp[i][j] == dp[i-1][j-1] + 1)){
            ans += s.substr(j-1, 1);
            i--;
            j--;

        }
        else if (dp[i][j-1] == dp[i][j]){
            j--;

        }
        else if (dp[i-1][j] == dp[i][j]){
            i--;

        }
        else{
            i--;
        }
    }
    
    for(int k=ans.size()-1; k>=0; k--){
        cout << ans.substr(k, 1);
    }
    cout << endl;

}