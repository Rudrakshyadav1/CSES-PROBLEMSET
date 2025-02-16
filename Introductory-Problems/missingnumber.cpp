#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long total=n*(n+1)/2;
    long long temp=0;
    long long p;
    for(int i=0;i<n-1;i++){
        cin>>p;
        temp+=p;
    }
    cout<<total-temp;
}