#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; i++){
        cin >> data[i].first;
        data[i].second = i + 1;  
    }
    if (n == 4){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += data[i].first;
        }
        if (sum == x){
            for (int i = 0; i < n; i++){
                cout << data[i].second << " ";
            }
            return 0;
        }
        else {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < n - 3; i++){
        for (int j = i + 1; j < n - 2; j++){
            int temp = x - data[i].first - data[j].first;
            int low = j + 1;
            int high = n - 1;
            while (low < high) {
                if (data[low].first + data[high].first == temp){
                    cout << data[i].second << " " << data[j].second << " "
                         << data[low].second << " " << data[high].second;
                    return 0;
                }
                else if (data[low].first + data[high].first < temp){
                    low++;
                }
                else {
                    high--;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}
