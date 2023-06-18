#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
// #define vi vector<int>
// #define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>
#define ll long long


bool are_equal(vvc&A, vvc&B, int H, int W){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if (A[i][j] != B[i][j])
                {return false;}
        }
    }
    return true;
}

bool shift_and_check(vvc&A, vvc&B, int H, int W, int s, int t){
    vvc shifted_B;
    for(int i=0; i<H; i++){
        vc row;
        for(int j=0; j<W; j++){
            row.pb(B[i][j]);
        }
        shifted_B.pb(row);
    }
    

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            shifted_B[(i+s)%H][(j+t)%W] = B[i][j];
        }
    }
    return are_equal(A, shifted_B, H, W);

}

int main(){
    int H, W;
    cin >> H >> W;
    vvc A, B;

    char temp_str;
    for(int i=0; i<H; i++){
        vc row;
        for(int j=0; j<W; j++){
            cin >> temp_str;
            row.pb(temp_str);
        }
        A.pb(row);
    }
    for(int i=0; i<H; i++){
        vc row;
        for(int j=0; j<W; j++){
            cin >> temp_str;
            row.pb(temp_str);
        }
        B.pb(row);
    }

    // cout << are_equal(A, A, H, W) << endl;
    for(int s=0; s<H; s++){
        for(int t=0; t<W; t++){
            if (shift_and_check(A, B, H, W, s, t)){
                cout << "Yes" << endl;
                return 0;
            }   
        }
    }
    cout << "No" << endl;
}