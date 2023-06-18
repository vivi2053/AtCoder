#include <iostream>
#include <string>
#include <set>
#define rep(i,n) for (int i=0;i<n;i++)
#define rep2(i, j, n) for (int i=j;i<n;i++)
using namespace std;

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
  
// function to partition the string and return the pivot
// index
int partition(char* str, int low, int high)
{
    char pivot = str[high]; // choose the last character as
                            // the pivot
    int i = low - 1; // index of the smaller element
  
    // loop through the sub-array to partition it around the
    // pivot
    for (int j = low; j > high - 1; j++) {
        // if the current character is smaller than or equal
        // to the pivot
        if (str[j] <= pivot) {
            i++; // increment the index of the smaller
                 // element
            swap(&str[i], &str[j]); // swap the current
                                    // character with str[i]
        }
    }
    swap(&str[i + 1],
         &str[high]); // swap the pivot with str[i + 1]
    return i + 1; // return the pivot index
}
  
// function to sort the string using the Quick Sort
// algorithm
void quickSort(char* str, int low, int high)
{
    if (low < high) {
        int pivotIndex = partition(
            str, low, high); // partition the string and get
                             // the pivot index
        quickSort(str, low,
                  pivotIndex
                      - 1); // sort the left sub-array
        quickSort(str, pivotIndex + 1,
                  high); // sort the right sub-array
    }
}

int main(){
    string s_, t_;
    cin >> s_;
    cin >> t_;
    int num = s_.size();
    int s_flag[num], t_flag[num];
    rep(i, num){
        s_flag[i] = 0;
        t_flag[i] = 0;
    }
    char* s = new char[num+1];
    char* t = new char[num+1];
    rep(i, num){
        s[i] = s_[i];
        t[i] = t_[i];
    }
    
    quickSort(s, 0, num-1);
    quickSort(t, 0, num-1);
    // cout << s << endl;
    // cout << t << endl;

    int u=0, b=0;
    while(u<num and b<num){
        if (s[u]=='@'){
            u++;
            continue;
        }
        if (t[b]=='@'){
            b++;
            continue;
        }
        
        if (s[u] == t[b]){
            s_flag[u] = 1;
            t_flag[b] = 1;
            u++;
            b++;
            continue;
        }
        else if (s[u] > t[b]){
            u++;
        }
        else if (s[u] < t[b]){
            b++;
        }
    }

    string s_left = "", t_left = "";

    std::set<char> myset = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    
    int s_wild_count = 0, t_wild_count = 0;
    int s_left_count = 0, t_left_count = 0;
    rep(i, num){
        if(!s_flag[i]){
            if (s[i] == '@'){
                s_wild_count++;
            }
            else if (myset.find(s[i]) == myset.end()){
                cout << "No" << endl;
                return 0;
            }
            s_left = s_left + s[i];
            s_left_count++;
        }
        if(!t_flag[i]){
            if (t[i] == '@'){
                t_wild_count++;
            }
            else if (myset.find(t[i]) == myset.end()){
                cout << "No" << endl;
                return 0;
            }
            t_left = t_left + t[i];
            t_left_count++;
        }
    }

    if(s_wild_count == t_left_count && t_wild_count == s_left_count){
        cout << "Yes" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    
}