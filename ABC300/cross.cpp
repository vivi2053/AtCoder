#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vc vector<char>
#define vvc vector<vc>
#define ll long long

bool row_valid(int idx, int H){
    return idx >= 0 && idx < H;
}

bool column_valid(int idx, int W){
    return idx >= 0 && idx < W;
}


int check_cross(vvc& grid, int H, int W, int i, int j){
    int c = 1;
    while((row_valid(i-c, H) && column_valid(j-c, W) && grid[i-c][j-c] == '#') &&
        (row_valid(i-c, H) && column_valid(j+c, W) && grid[i-c][j+c] == '#') &&
        (row_valid(i+c, H) && column_valid(j-c, W) && grid[i+c][j-c] == '#') &&
        (row_valid(i+c, H) && column_valid(j+c, W) && grid[i+c][j+c] == '#')){
            c++;
        }
    return c-1;
    
}

int main(){
    int H, W;
    cin >> H >> W;
    vvc grid;

    int max_sq_size = min(H, W);

    int crosses[101];
    for(int i=0; i<=100; i++){
        crosses[i] = 0;
    }

    char temp;
    for(int i=0; i<H; i++){
        vc row;
        for(int j=0; j<W; j++){
            cin >> temp;
            row.pb(temp);
        }
        grid.pb(row);
    }

    // cout << i << " " << j << " " << ans << endl;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(grid[i][j] != '#'){ continue;}
            int ans = check_cross(grid, H, W, i, j);
            if (ans>0){crosses[ans]++;}
        }
    }

    for(int i=1;i<=max_sq_size;i++){
        cout << crosses[i] << " ";
    }
    cout << endl;

}