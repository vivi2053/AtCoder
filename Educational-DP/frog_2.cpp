#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int main(){

    int N; int K;
    int i;
    cin >> N >> K;
    int heights[N];
    int cost[N];
    int cand_costs[K];
    

    
    rep(i, N){
        cin >> heights[i];
    }
    
    cost[0] = 0;
    rep2(i, 1, N){
        rep2(j, 1, K+1){
            if ((i-j) >= 0){ cand_costs[j-1] = cost[i-j] + abs(heights[i] - heights[i-j]);}
            else{ cand_costs[j-1] = INT_MAX;}
        }
        cost[i] = *min_element(cand_costs, cand_costs + K);
    }
    cout << (cost[N-1]) << endl;

}