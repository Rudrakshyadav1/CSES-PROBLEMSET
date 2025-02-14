#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; i++){
        cin >> data[i].first >> data[i].second;
    }
    sort(data.begin(), data.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    multiset<int> tracker;
    int counter = 0;
    for (int i = 0; i < n; i++){
        if (tracker.size() < k) {
            tracker.insert(data[i].second);
        }
        else{
            if (*tracker.begin() <= data[i].first){
                tracker.erase(tracker.begin()); 
                tracker.insert(data[i].second); 
            }
            else{
                counter++;
            }
        }
    }
    cout << n - counter;
}
