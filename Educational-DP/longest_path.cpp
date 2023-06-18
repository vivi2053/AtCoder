#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int dfs(int node, vvi &adjacency, int distances[], bool visited[]){
    if (adjacency[node].size()==0){
        visited[node] = true;
        distances[node] = 0;
        return 0;
    }
    int max_len;
    vi dists;
    rep(i, adjacency[node].size()){
        if(visited[adjacency[node][i]]){
            dists.pb(distances[adjacency[node][i]]);
        }
        else {
            dists.pb(dfs(adjacency[node][i], adjacency, distances, visited));
        }
        
    }
    // rep(i, dists.size()){
    //     cout << dists[i];
    // }
    // cout << endl;
    max_len = 1 + *std::max_element(std::begin(dists), std::end(dists));
    visited[node] = true;
    distances[node] = max_len;
    return max_len;
}

int main(){
    int N, M;
    cin >> N >> M;
    int distances[100001] = {0};
    bool visited[100001] = { false };
    
    vvi adjacency(N+1);
    int x, y;
    rep(i, M){
        cin >> x >> y;
        adjacency[x].pb(y);
    }

    int max_ = 0;
    rep2(i, 1, N+1){
        max_ = dfs(i, adjacency, distances, visited);
    }

    int max_dist = 0;
    rep2(i, 1, N+1){
        if (distances[i] > max_dist){
            max_dist = distances[i];
        }
    }
    cout << max_dist << endl;

}
