#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;  
    for (int coin : coins){
        for (int j = coin; j <= x; j++){
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
    }
    cout << dp[x];  
}
