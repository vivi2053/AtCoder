#include <iostream>
#include <vector>
#include <string>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
#define vs vector<string>
#define vvs vector<vs>
using namespace std;


bool check_tak(vvs &taks, int &n, int &m, int &r, int &c){
    //check top block
    rep2(i, r, r+3){
        rep2(j, c, c+3){
            if (taks[i][j] != "#"){
                return false;
            }
        }
    }

    //upper adjacent cells
    int r_indxs[7] = {0, 1, 2, 3, 3, 3, 3};
    int c_indxs[7] = {3, 3, 3, 3, 2, 1, 0};
    rep(i, 7){
        if (taks[r+r_indxs[i]][c+c_indxs[i]] != "."){
            return false;
        }
    }

    //lower adjacent cells
    int r_indxs2[7] = {8, 7, 6, 5, 5, 5, 5};
    int c_indxs2[7] = {5, 5, 5, 5, 6, 7, 8};
    rep(i, 7){
        if (taks[r+r_indxs2[i]][c+c_indxs2[i]] != "."){
            return false;
        }
    }

    //check low block
    rep2(i, r+6, r+9){
        rep2(j, c+6, c+9){
            if (taks[i][j] != "#"){
                return false;
            }
        }
    }
    return true;
}


int main(){
    vvs taks;
    int n, m;
    char temp;
    string temp2;
    cin >> n >> m;
    rep(i, n){
        vs column;
        rep(j, m){
            cin >> temp;
            temp2 = temp;
            column.pb(temp2);
        }
        taks.pb(column);
    }

    rep(i, n-8){
        rep(j, m-8){
            if (check_tak(taks, n, m, i, j)){
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }
    


}