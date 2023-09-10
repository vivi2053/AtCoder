#include <iostream>
#include <vector>
#define ll long long
#define vl vector<ll>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
#define pb push_back
using namespace std;

std::vector<long long> sortVector(const std::vector<long long>& inputVector) {
    std::vector<long long> sortedVector = inputVector; // Copy the input vector to avoid modifying the original

    // Use std::sort to sort the elements in ascending order
    std::sort(sortedVector.begin(), sortedVector.end());

    return sortedVector;
}


long long binarySearch(const std::vector<long long>& sortedVector, long long target) {
    long long left = 0;
    long long right = sortedVector.size() - 1;
    long long result = -1; // Initialize with -1, which indicates the target is not found

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (sortedVector[mid] == target) {
            return mid; // Target found, return the index
        } else if (sortedVector[mid] < target) {
            left = mid + 1; // Search the right half
        } else {
            result = mid; // Update the result to the current mid index
            right = mid - 1; // Search the left half
            // if (result == 0 && left>right){
            //     return -2;
            // }
        }
    }

    return result;
}


int main(){
    int n, m;
    ll temp;
    cin >> n >> m;
    vl sell;
    vl buy;
    rep(i, n){
        cin >> temp;
        sell.pb(temp);
    }
    rep(i, m){
        cin >> temp;
        buy.pb(temp);
    }

    vl sort_sell = sortVector(sell);
    vl sort_buy = sortVector(buy);
    int sellnum = 0;
    int buynum = 0;
    rep(i, n){
        sellnum = i+1;
        buynum = binarySearch(sort_buy, sort_sell[i]);
        if (buynum == -1){
            buynum = sort_buy[m-1]+1;
            cout << buynum << endl;
            return 0;
        }
        // cout << sellnum << " " << buynum << endl;
        buynum = m - buynum;
        if (sellnum >= buynum){
            cout << sort_sell[i] << endl;
            return 0;
        }
    }
    cout << sort_buy[0] << endl;
    
}