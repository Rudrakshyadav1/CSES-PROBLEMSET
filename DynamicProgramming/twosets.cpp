#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
long long modInverse(long long a, long long m){
    long long result = 1;
    long long power = m - 2; 
    while (power > 0){
        if (power % 2 == 1){
            result = (result * a) % m;
        }
        a = (a * a) % m;
        power /= 2;
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    long long total = (long long)n * (n + 1) / 2;
    if (total % 2 != 0){
        cout << 0 << endl;
        return 0;
    }
    long long target = total / 2;
    vector<long long> dp(target + 1, 0);
    dp[0] = 1; 
    for (int i = 1; i <= n; i++){
        for (int j = target; j >= i; j--){
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    long long result = dp[target];
    result = (result * modInverse(2, MOD)) % MOD;
    cout << result;
}


