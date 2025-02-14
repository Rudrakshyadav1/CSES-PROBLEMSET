#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout << 0;
        return 0;
    }
    vector<vector<int>> ans(n,vector<int>(n, 0));
    ans[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == '*') {
                ans[i][j] = 0;
                continue;
            }
            if (i > 0 && grid[i-1][j] != '*'){
                ans[i][j] = (ans[i][j] + ans[i-1][j]) % mod;
            }
            if (j > 0 && grid[i][j-1] != '*'){
                ans[i][j] = (ans[i][j] + ans[i][j-1]) % mod;
            }
        }
    }
    cout << ans[n-1][n-1];
}
