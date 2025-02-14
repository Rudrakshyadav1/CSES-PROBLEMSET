#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> >num(n);
    vector<pair<int,int> >queries(m);
    for(int i=0;i<n;i++){
        cin>>queries[i].first>>queries[i].second;
    }
    for(int i=0;i<n;i++){
        cin>>num[i].first;
        num[i].second=i;
    }
    vector<pair<int,int> >sorted(n);
    sorted=num;
    sort(sorted.begin(),sorted.end());
    auto rounds=[](int n,vector<pair<int,int> >&sorted){
        int rounds=1;
        for(int i =1;i<n;i++){
            if(sorted[i-1].second>sorted[i].second){
                rounds++;
            }
        }
        return rounds;
    };
   
   

}