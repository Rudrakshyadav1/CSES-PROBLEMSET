#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll sum=0;
    ll mod;
    map<ll,ll>data;
    data[0]=1;
    ll count=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum+=a;
        mod=sum%n;
        if(mod<0){
            mod+=n;
        }
        count+=data[mod];
        data[mod]++;
    }
    cout<<count;
}