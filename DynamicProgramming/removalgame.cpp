#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<int>arr(n);
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    ll total=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total+=arr[i];
        dp[i][i]=arr[i];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            ll first_element=arr[i]-dp[i+1][j];
            ll last_element=arr[j]-dp[i][j-1];
            dp[i][j]=max(first_element,last_element);
        }
    }
    cout<< (total+dp[0][n-1])/2;
}