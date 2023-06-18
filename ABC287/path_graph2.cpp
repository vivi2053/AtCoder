#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#include <set>

bool dfs(int parent, int current, set<int> &visited, vvi &graph){
    bool is_in = visited.find(current) != visited.end();
    if (is_in){ return false; }
    visited.insert(current);
    rep(j, graph[current].size()){
        if(graph[current][j] != parent){
            bool res = dfs(current, graph[current][j], visited, graph);
            if (!res) { return false; }
        }
    }
    return true;
}

int main(){
    int u, v, N, M;
    cin >> N >> M;
    vector<vector<int> > graph(20001);
    set<int> visited;
    rep(i, M-1){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    // rep(k, graph[1].size()){
    //     cout << graph[1][k] << endl;
    // }

    if ( M && dfs(0, 1, visited, graph)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}
