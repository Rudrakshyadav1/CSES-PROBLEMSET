#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum=0;
    long long index=n/2;
    vector<long long>num(n);
    for(long long i=0;i<n;i++){
        cin>>num[i];
        sum+=num[i];
    }
    sum/=n;
    sort(num.begin(),num.end());
    if(n%2==0){
        if(abs(num[index]-sum)>=abs(num[index-1]-sum)){
            index-=1;
        }
    }
    long long ans=0;
    for(long long i=0;i<n;i++){
        ans+=abs(num[index]-num[i]);
    }
    cout<<ans;


}