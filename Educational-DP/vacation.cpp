#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int main(){
    int N;
    cin >> N;
    int a_arr[N], b_arr[N], c_arr[N];
    int a_total[N], b_total[N], c_total[N];
    int i;
    rep(i, N){
        cin >> a_arr[i] >> b_arr[i] >> c_arr[i];
    }
    a_total[0] = a_arr[0]; b_total[0] = b_arr[0]; c_total[0] = c_arr[0]; 
    rep2(i, 1, N){
        a_total[i] = max(a_arr[i] + b_total[i-1], a_arr[i] + c_total[i-1]);
        b_total[i] = max(b_arr[i] + a_total[i-1], b_arr[i] + c_total[i-1]);
        c_total[i] = max(c_arr[i] + a_total[i-1], c_arr[i] + b_total[i-1]);
    }
    
    cout << max(a_total[N-1], max(b_total[N-1], c_total[N-1])) << endl;

}