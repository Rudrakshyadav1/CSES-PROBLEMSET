#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
int main(){
    ll x,n;
    cin>>x>>n;
    set<ll>positions;
    multiset<ll>len;
    positions.insert(0);
    positions.insert(x);
    len.insert(x);
    while(n--){
        int a;
        cin>>a;
        positions.insert(a);
        auto it=positions.find(a);
        auto prev_=*prev(it);
        auto next_=*next(it);
        len.insert(*it-prev_);
        len.insert(next_-*it);
        len.erase(len.find(next_ - prev_));
        cout<<*len.rbegin()<<" ";
    }
}