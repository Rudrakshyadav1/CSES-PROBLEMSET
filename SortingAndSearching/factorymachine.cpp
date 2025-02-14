#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll low,high;
    low=0;
    high=1e18;
    int n,k;
    cin>>n>>k;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    ll time=0;
    ll ans;
    while(low<=high){
        ll mid=low+(high-low)/2;
        time=mid;
        ll temp_product=0;
        for(int i=0;i<n;i++){
            temp_product+=(time/num[i]);
            if(temp_product>=k){
                break;
            } 
        }
        if(temp_product<k){
            low=mid+1;
        }
        else{
            ans=time;
            high=mid-1;
        }
    }
    cout<<ans;
}