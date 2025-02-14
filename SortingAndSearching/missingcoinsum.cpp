#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long total = 0;
    vector<long long> num(n);
    for(long long i = 0; i < n; i++){
        cin >> num[i];
        total += num[i];
    }
    sort(num.begin(),num.end());
    long long sum = 1;  
    for(long long i = 0; i < n; i++){
        if(num[i] <= sum){
            sum += num[i];
        }
        else{
            cout << sum; 
            return 0;
        }
    }
    cout << total + 1;
}

