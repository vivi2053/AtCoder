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
    // cout << parent << " " << current << endl;
    bool is_in = visited.find(current) != visited.end();
    if (is_in){ return false; }
    visited.insert(current);
    if(graph[current].size() > 2){return false;}
    rep(j, graph[current].size()){
        // cout << current << " " << graph[current][j] << endl; 
        if(graph[current][j] != parent){

            bool res = dfs(current, graph[current][j], visited, graph);
            // cout << current << " " << graph[current][j] << " " << res << endl;
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
    
    int all_have_edges;
    rep(k, N){
        if (k, N){
            
        }
    }

    if ( M && dfs(0, 1, visited, graph)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}
