#include <vector>
#include <queue>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    int nums[N], v_pos[M];

    rep(i, N){
        nums[i] = i+1;
    }
    
    rep(i,  M){
        cin >> v_pos[i];
    }

    if (M == 0){
        rep(i, N-1){
            cout << nums[i] << " " ;
        }
        cout << nums[N-1] << endl;
        return 0;
    }
    

    int start = v_pos[0];
    int last = v_pos[0];
    int cur = 0;
    
    vvi comps;
    rep2(i, 1, M){
        vi temp;
        cur = v_pos[i];
        if (cur == last + 1){
            last = cur;
        }
        else{
            temp.pb(start);
            temp.pb(last+1);
            comps.pb(temp);
            start = cur;
            last = cur;
        }
    }
    vi temp;
    temp.pb(start);
    temp.pb(last+1);
    comps.pb(temp);

    // rep(i, comps.size()){
    //     cout << comps[i][0] << comps[i][1] <<  endl;
    // }

    int s, e;
    start = 0;
    rep(i, comps.size()){
        s = comps[i][0];
        e = comps[i][1];
        rep2(j, start, s-1){
            cout << nums[j] << " ";
        }
        for(int j=e-1;j>=s-1;j--){
            cout << nums[j] << " ";
        }
        start = e;
    }

    rep2(i, start, N){
        cout << nums[i] << " ";
    }
    cout << endl;



}