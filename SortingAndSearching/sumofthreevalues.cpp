#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; i++){
        cin >> data[i].first;
        data[i].second = i + 1; 
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < n - 2; i++){
        int low = i + 1;
        int high = n - 1;
        int target = x - data[i].first; 
        while (low < high) {
            int sum = data[low].first + data[high].first;
            if (sum == target){
                cout << data[i].second << " " << data[low].second << " " << data[high].second;
                return 0; 
            }
            else if (sum < target){
                low++; 
            }
            else {
                high--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
}
