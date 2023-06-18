#include <iostream>
#include <string>
#include <vector>
// #include <set>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;
#define ll long long

int H, W;

string get_candidate(vvs& grid, int H, int W, int  pos_i, int pos_j, int r, int c, int depth){
    if (pos_i < 0 || pos_i >= H || pos_j < 0 || pos_j >=W){
        return "";
    }
    if (depth == 4){
        return grid[pos_i][pos_j];
    }
    return grid[pos_i][pos_j] + get_candidate(grid, H, W, pos_i+r, pos_j+c, r, c, depth+1);
}

int* check_pos(vvs& grid, int pos_i, int pos_j){
    rep2(i, -1, 2){
        rep2(j, -1, 2){
            if(i==0 && j==0){
                continue;
            }
            string cand = get_candidate(grid, H, W, pos_i, pos_j, i, j, 0);
            cout << cand << endl;
            if (cand == "snuke"){
                return new int[2]{i, j};
            }
        }
    }
    return new int[2]{0, 0};

}


int main(){
    cin >> H >> W;
    vvs grid;
    char temp;
    rep2(i, 0, H){
        vs row;
        rep2(j, 0, W){
            cin >> temp;
            row.pb(string(1, temp));
        }
        grid.pb(row);
    }

    rep2(i, 0, H){
        rep2(j, 0, W){
            if (grid[i][j] != "s"){
                continue;
            }
            else{
                int* res = check_pos(grid, i, j);
                if (*(res) == 0 && *(res+1) == 0){
                    continue;
                }
                else{
                    int direc_i = *(res);
                    int direc_j = *(res+1);
                    rep(x, 5){
                        cout << i + direc_i * x + 1 << " " << j + direc_j * x + 1 << endl;
                    }
                    return 0;
                }
            }
        }
    }

}