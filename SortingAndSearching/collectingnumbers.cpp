#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<pair<long long, long long> > num(n);
    for(long long i = 0; i < n; i++){
        cin >> num[i].first;
        num[i].second = i;
    }
    sort(num.begin(), num.end());
    long long rounds = 1;
    long long prev_index = num[0].second; 
    for (long long i = 1; i < n; i++){  
        if (num[i].second < prev_index){  
            rounds++;
        }
        prev_index = num[i].second;  
    }
    cout << rounds << endl;
   
}
