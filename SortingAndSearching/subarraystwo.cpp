#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
int main(){
    int n, x;
    cin >> n >> x;
    map<ll, int> counter;
    ll ans = 0;
    counter[0]++;
    ll temp = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        temp += a;
        ans += counter[temp - x];
        counter[temp]++;
    }
    cout << ans; 
}