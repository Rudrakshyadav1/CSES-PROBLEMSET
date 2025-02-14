#include <iostream>
#include <vector>
#include <climits>  
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<long long> num(n);
    for(long long i = 0; i < n; i++){
        cin >> num[i];
    }
    long long maxsum = LONG_MIN; 
    long long current_sum = 0;   
    for (long long i = 0; i < n; i++){
        current_sum = max(num[i], current_sum + num[i]);  
        maxsum = max(maxsum, current_sum);  
    }
    cout << maxsum << endl; 
}
