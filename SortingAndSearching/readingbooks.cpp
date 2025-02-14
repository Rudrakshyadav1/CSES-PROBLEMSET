#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;
ll solve(vector<ll>& arr, ll N){
    sort(arr.begin(), arr.end());
    ll largest = arr[N - 1];
    ll sumOfSmaller
        = accumulate(arr.begin(), arr.end() - 1, 0LL);
    if (largest <= sumOfSmaller) {
        return sumOfSmaller + largest;
    }
    return 2 * largest;
}
int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << solve(arr, n);
}        