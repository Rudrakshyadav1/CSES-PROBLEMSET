#include<iostream>
#include<map>
using namespace std;
int main(){
    long long n;
    map<long,long>timings;
    cin>>n;
    while(n--){
        long long a,b;
        cin>>a>>b;
        timings[a]++;
        timings[b]--;
    }
    long long ans=0;
    long long maximum=0;
    for(auto it:timings){
        ans+=it.second;
        maximum=max(ans,maximum);
    }
    cout<<maximum;
}