#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int>data(n);
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    vector<pair<int,int> >dp(1<<n,{INT_MAX,INT_MAX});
    dp[0]={1,0};
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i &(1<<j)){
                int occupied =dp[i^(1<<j)].second;
                if(occupied+data[j]<=x){
                    dp[i]=min(dp[i],{dp[i^(1<<j)].first,occupied+data[j]});
                }
                else{
                    dp[i]=min(dp[i],{dp[i^(1<<j)].first+1,data[j]});

                }
            }
        }
    }
    cout<<dp[(1<<n)-1].first;
}