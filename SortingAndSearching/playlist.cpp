#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>songs(n);
    for(ll i=0;i<n;i++){
        cin>>songs[i];
    }
    map <ll,ll>lastindex;
    ll maxlen=0;
    ll j=0;
    for(ll i=0;i<n;i++){
        if(lastindex.count(songs[i])!=0){
            j=max(j,lastindex[songs[i]]+1);
        }
        maxlen=max(maxlen,i-j+1);
        lastindex[songs[i]]=i;
    }
    cout<<maxlen;

}