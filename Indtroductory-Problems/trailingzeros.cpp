#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long counter=0;
    while(n!=0){
        n/=5;
        counter+=n;
    }
    cout<<counter;

}