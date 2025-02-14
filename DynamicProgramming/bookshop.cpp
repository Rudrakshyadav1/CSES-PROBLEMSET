#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);
    for(int i = 0; i < n; i++){
        cin >> price[i];
    } 
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for(int i = 1; i <= n; i++){
        for (int j = 0; j <= x; j++){ 
            int pricing = price[i - 1];
            int page_count = pages[i - 1];
            if (j >= pricing){
                int pick = dp[i - 1][j - pricing] + page_count; 
                int skip = dp[i - 1][j]; 
                dp[i][j] = max(pick, skip); 
            }
            else{
                dp[i][j] = dp[i - 1][j]; 
            }
        }
    }
    cout << dp[n][x];
}