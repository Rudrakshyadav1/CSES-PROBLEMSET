#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;  
    vector<int> data(n);
    for (int i = 0; i < n; i++){
        cin >> data[i]; 
    }
    if (k == 1){
        for (int i = 0; i < n; i++){
            cout << data[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if (k == 2){
        for (int i = 1; i < n; i++) {
            cout << min(data[i - 1], data[i]) << " ";
        }
        cout << endl;
        return 0;
    }
    vector<int> temp(k);
    for (int i = 0; i < k; i++){
        temp[i] = data[i];
    }
    sort(temp.begin(), temp.end());
    multiset<int> left, right;
    int len_left = (k+1)/ 2;
    int len_right = k - len_left;
    for (int i = 0; i <len_left; i++){
        left.insert(temp[i]);
    }
    for (int i = len_left; i < k; i++){
        right.insert(temp[i]);
    }
    cout << *left.rbegin() << " ";
    int low = 0, high = k;
    while (high < n){
        int new_val = data[high];
        int old_val = data[low];
        low++;
        high++;
        if (new_val <= *left.rbegin()){
            left.insert(new_val);
        }
        else{
            right.insert(new_val);
        }
        if (old_val <= *left.rbegin()){
            left.erase(left.find(old_val));
        }
        else{
            right.erase(right.find(old_val));
        }
        if (left.size() > len_left){
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        }
        else if (left.size() < len_left){
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        cout << *left.rbegin() << " ";
    }
    cout << endl;
}
