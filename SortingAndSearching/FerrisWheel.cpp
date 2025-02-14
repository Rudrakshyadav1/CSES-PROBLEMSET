#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n, x, ans = 0;
    cin >> n >> x;
    vector<long long> weight(n);
    for (long long i = 0; i < n; i++) {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());
    long long i = 0, j = n - 1;
    while (i<=j) {
        if (weight[i] + weight[j] <= x){
            ans++;
            i++;
            j--;  
        }
        else{
            ans++;
            j--;  
        }
    }
    cout <<ans<< endl;
}
