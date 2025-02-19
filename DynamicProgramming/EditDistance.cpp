#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++){
        dp[i][0] = i;  
    }
    for (int j = 0; j <= m; j++){
        dp[0][j] = j;  
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];  
            }
            else {
                dp[i][j] =dp[i - 1][j - 1] + 1; 
            }
            dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    } 
    cout << dp[n][m]; 
}
