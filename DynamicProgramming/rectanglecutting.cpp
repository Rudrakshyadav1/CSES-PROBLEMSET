#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            if (j == i){
                dp[i][j] = 0;
                continue;
            }
            for (int p = 1; p < i; p++){
                dp[i][j] = min(dp[i][j], dp[i - p][j] + dp[p][j] + 1);
            }
            for (int q = 1; q < j; q++){
                dp[i][j] = min(dp[i][j], dp[i][j - q] + dp[i][q] + 1);
            }
        }
    }
    cout << dp[a][b];
}