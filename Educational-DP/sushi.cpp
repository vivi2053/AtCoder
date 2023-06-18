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

int N;
double dp[310][310][310];

double rec(int i, int j, int k){
    if (dp[i][j][k] >= 0) return dp[i][j][k];
    if (i == 0  && j == 0 && k == 0) return 0.0;

    double res = 0.0;

    if (i>0) res += i * rec(i-1, j, k);
    if (j>0) res += j * rec(i+1, j-1, k);
    if (k>0) res += k * rec(i, j+1, k-1);

    res += N;
    res *= 1.0 / (i + j + k);

    return dp[i][j][k] = res;

}


int main(){
    cin >> N;
    
    int one=0, two=0, three=0;
    int temp;
    rep(i, N){
        cin >> temp;
        if (temp == 1) one++;
        else if(temp == 2) two++;
        else three++;
    }

    memset(dp, -1, sizeof(dp));
    
    cout << fixed << setprecision(10) << rec(one, two, three) << endl;
    return 0;
}