#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++){
        if(arr[0] == 0 || arr[0] == i){
            dp[1][i] = 1;
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i - 1] != 0 && arr[i - 1] != j){
                continue;
            }
            for(int val =j - 1; val <=j + 1; val++){
                if(val>m){
                    continue;
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][val]) % mod;
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= m; i++){
        result = (result + dp[n][i]) % mod;
    }
    cout << result;
}
