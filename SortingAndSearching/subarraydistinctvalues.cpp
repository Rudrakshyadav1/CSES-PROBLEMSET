#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    int left = 0, right = 0;
    ll counter = 0;
    map<int, int> data; 
    while (right < n){
        data[num[right]]++;  
        while (data.size() > k){
            data[num[left]]--;
            if (data[num[left]] == 0){
                data.erase(num[left]);
            }
            left++;
        }
        counter += (right - left + 1);
        right++;
    }
    cout << counter;
}
