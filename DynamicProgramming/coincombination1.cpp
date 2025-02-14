#include <iostream>
#include <vector>
using namespace std; 
const int MOD = 1e9 + 7;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n), dp(x + 1,0);
    for (auto &c : coins){ 
        cin >> c;
    }
    dp[0] = 1; 
    for (int i = 1; i <= x; i++){
        for (int c : coins){
            if (i - c >= 0){
                (dp[i] += dp[i - c]) %= MOD; 
            }
        }
    }
    cout<<dp[x];
}