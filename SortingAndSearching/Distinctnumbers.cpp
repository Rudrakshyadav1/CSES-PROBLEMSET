#include<iostream>
#include<set>
using namespace std;
int main(){
    long long n;
    cin>>n;
    set<long long> data;
    while(n--){
        long long temp;
        cin>>temp;
        data.insert(temp);
    }
    long long answer=data.size();
    cout<<answer;
}