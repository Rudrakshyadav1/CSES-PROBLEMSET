#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
typedef long long ll;
void mincoins(int sum,int n,const vector<int>&data,vector<ll>& minsaver){
    minsaver[0]=0;
    for(int i = 1; i <= sum; i++){
        for(int j = 0; j < n; j++){
            if(i - data[j] >= 0 && minsaver[i - data[j]]!=LLONG_MAX){
                minsaver[i] = min(minsaver[i], minsaver[i - data[j]]+1);
            }
        }
    }
}
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> data(n);
    for(int i = 0; i < n;i++){
        cin >> data[i];
    }
    vector<ll>minsaver(x+1,LLONG_MAX);
    mincoins(x, n, data, minsaver);
    if(minsaver[x] == LLONG_MAX){
        cout << -1; 
    }
    else{
        cout << minsaver[x]; 
    }
}