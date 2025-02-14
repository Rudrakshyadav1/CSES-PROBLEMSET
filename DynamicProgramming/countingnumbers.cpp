#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
ll counter(ll num,vector<ll>&dp){
    if(num<1)
        return num==0? 1:0;

    string str=to_string(num);
    ll ans=0;
    for(int i=0;i<str.size();i++) ans+=dp[i];
    int prev=0;
    for(int i=0;i<str.size();i++){
        int digit=str[i]-'0';
        int remain=str.size()-1-i;
        int range= (prev<digit) ? digit-1:digit;
        ans+=(digit==0)?0:range*dp[remain];
        if(prev==digit){
            return ans;
        }
        prev=digit;
    }
    return ans+1;
}
int main(){
    ll a,b;
    cin>>a>>b;
    vector<ll>dp(19);
    dp[0]=1;
    ll temp=1;
    for(int i=1;i<19;i++){
        temp*=9;
        dp[i]=temp;
    }
    cout<<counter(b,dp)-counter(a-1,dp);
}