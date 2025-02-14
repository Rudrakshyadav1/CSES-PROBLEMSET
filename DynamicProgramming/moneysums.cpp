#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum = 0;
    vector<int> coin(n);
    for (int i = 0; i < n; i++){
        cin >> coin[i];
        sum += coin[i];
    }
    set<int> ans;
    vector<bool> dp(sum + 1, false); 
    dp[0] = true;  
    for(int i = 0; i < n; i++){ 
        for (int j = sum; j >= coin[i]; j--){ 
            if (dp[j - coin[i]]){
                dp[j] = true;
            }
        }
    }
    for(int i = 1; i <= sum; i++){
        if(dp[i]){
            ans.insert(i);
        }
    }
    cout << ans.size() << endl;  
    for (auto it : ans) {
        cout << it << " ";
    }
}
