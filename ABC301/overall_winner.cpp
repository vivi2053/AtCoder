// #include <vector>


#define rep2(i, j, n) for (int i=j;i<n;i++)
// #define pb push_back
// #define vc vector<char>
// #define vvc vector<vc>
// #define ll long long
#include <iostream>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;

int main(){

    int N;
    int T = 0, A = 0;
    char temp;
    cin >> N;
    int min_num = (N%2==0)?(N/2):(N/2)+1;
    rep(i, N){
        cin >> temp;
        if (temp == 'T'){
            T++;
        }
        else{
            A++;
        }
        
        if(T==min_num){
            cout << "T" << endl;
            return 0;
        }
        else if (A==min_num) {
            cout << "A" << endl;
            return 0;
        }
    }

    

}