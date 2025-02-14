#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long n,x;
    cin>>n>>x;
    vector<pair<long long,long long> >element(n);
    for(long long i=0;i<n;i++){
        long long a;
        cin>>a;
        element[i]=make_pair(a,i);
    }
    sort(element.begin(),element.end(),[](const pair<long long,long long>&a,const pair<long long,long long>&b){
        return a.first<b.first;
    });
    long long i=0;
    long long j=n-1;
    while(i<j){
        if(element[i].first+element[j].first==x){
            cout<<element[i].second+1<<" "<<element[j].second+1;
            break;
        }
        else if(element[i].first+element[j].first>x){
            j--;
        }
        else if(element[i].first+element[j].first<x){
            i++;
        }
    }
    if(i==j){
        cout<<"IMPOSSIBLE";
    }
}