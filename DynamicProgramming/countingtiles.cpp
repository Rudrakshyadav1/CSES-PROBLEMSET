#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
void column_filler(int column, int idx, int current_mask, int next_mask, vector<vector<int>>& data){
    if(idx == n){ 
        data[column + 1][next_mask]=(data[column + 1][next_mask] + data[column][current_mask]) % mod;
        return;
    }
    if(current_mask & (1 << idx)){
        column_filler(column, idx + 1, current_mask, next_mask, data);
    }
    else {
        column_filler(column, idx + 1, current_mask, next_mask | (1 << idx), data);  
        if (idx + 1 < n && !(current_mask & (1 << (idx + 1)))) {
            column_filler(column, idx + 2, current_mask, next_mask, data);  
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> data(m + 1, vector<int>(1 << n, 0));
    data[0][0] = 1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < (1 << n); j++){
            if (data[i][j] > 0){
                column_filler(i,0,j,0,data);  
            }
        }
    };
    cout<<data[m][0];
}
