#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define vi unordered_set<int>
#define vvi vector<vi>
#define pb push_back
using namespace std;

bool compare_products(int i, int j, int products[100000], vvi &funcs){
    if (products[i] < products[j]){
        return false;
    }
    for (auto itr : funcs[i]){
        if (funcs[j].find(itr) == funcs[j].end()){
            return false;
        }
    }

    int counter = 0;
    for (auto itr : funcs[j]){
        if (funcs[i].find(itr) == funcs[i].end()){
            counter += 1;
        }
    }
    if (counter==0 and products[j]==products[i]){
        return false;
    }
    return true;
}

int main(){
    int N, M;
    int products[100000];
    vvi funcs;
    int temp, c;
    cin >> N >> M;
    rep(i, N){
        cin >> products[i] >> c;
        vi pfuncs;
        rep(i, c){
            cin >> temp;
            pfuncs.insert(temp);
        }
        funcs.pb(pfuncs);
    }

    rep(i, N){
        rep(j, N){
            if (i!=j){
                if (compare_products(i, j, products, funcs)){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;

}