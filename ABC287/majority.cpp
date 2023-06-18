#include <vector>
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long

int main(){
    int N;
    cin >> N;
    string temp;
    int for_count = 0;
    rep(i, N){
        cin >> temp;
        if (temp == "For"){
            for_count++;
        }
    }

    if (for_count >= (N/2) + 1 ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}