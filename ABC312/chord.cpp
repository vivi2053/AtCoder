#include <math.h>
#include <iostream>
#include <unordered_set>
#include <string>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;

int main(){
    string input_str;
    unordered_set<string> chords = { "ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD" };
    cin >> input_str;
    if (chords.find(input_str) != chords.end()){
            cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
