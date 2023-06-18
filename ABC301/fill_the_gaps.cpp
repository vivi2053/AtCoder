#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;

int main(){

    int N;
    cin >> N;
    int seq[N];
    rep(i, N){
        cin >> seq[i]; 
    }

    int diff, abs_diff, direc;
    rep(i, N-1){
        diff = seq[i+1] - seq[i];
        direc = diff>0?1:-1;
        diff = diff<0? -diff: diff;
        cout << seq[i] << " ";
        
        if (diff <= 1 and diff >=-1){
            continue;
        } 
        rep2(j, 1, diff){
            cout << seq[i] + direc * j << " ";
        }   
    }   

    cout << seq[N-1] << endl;

}