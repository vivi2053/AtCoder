#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int main(){
    int N; int i;
    int prev_cost; int prev2_cost;
    cin >> N;
    int heights[N];
    int cost[N];

    rep(i, N){
        cin >> heights[i];
    }
    cost[0] = 0;
    cost[1] = abs(heights[1] - heights[0]);
    rep2(i, 2, N){
        prev_cost = cost[i-1] + abs(heights[i] - heights[i-1]);
        prev2_cost = cost[i-2] + abs(heights[i] - heights[i-2]);
        cost[i] = min(prev2_cost, prev_cost);
    }
    
    cout << cost[N-1] << endl;
    
}