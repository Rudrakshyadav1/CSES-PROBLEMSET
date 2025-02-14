#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
    ll n,k;
    cin>>n>>k;
    queue<ll>data;
    for(ll i=0;i<n;i++){
        data.push(i+1);}
        while(data.size()!=1){
            int temp=k;
            while(temp--){
                int front_=data.front();
                data.push(front_);
                data.pop();
            }
    cout<<data.front()<<" ";
    data.pop();
}
cout<<data.front();
}