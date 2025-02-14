#include<iostream>
using namespace std;
long long m=1000000007;
int main(){
    long long n;
    cin>>n;
    long long base=2;
    base=base%m;
    long long result=1;
    //(a*b)%m=(a%m*b%m)%m
    for(int i=0;i<n;i++){
        result*=base;
        result%=m;
    }
    cout<<result;
}