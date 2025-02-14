#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int>num;
    for(int i=0;i<n;i++){
        num.push(i+1);
    }
    while(num.size()!=1){
        int val=num.front();
        num.pop();
        num.push(val);
        int val2=num.front();
        num.pop();
        cout<<val2<<" ";
    }
    cout<<num.front();
}
