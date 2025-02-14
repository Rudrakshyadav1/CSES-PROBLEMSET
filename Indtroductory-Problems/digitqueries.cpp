#include <iostream>
#include <string>
using namespace std;
void bitnumeral(long long k){
    long long len = 1; 
    long long count = 9; 
    long long start = 1;
    while (k > len * count){
        k -= len * count;
        len++; 
        count *= 10; 
        start *= 10; 
    }
    long long number = start + (k - 1) / len; 
    string temp = to_string(number); 
    cout << temp[(k - 1) % len] << endl;
}
int main(){
    int q;
    cin >> q;
    while (q--){
        long long k;
        cin >> k; 
        bitnumeral(k); 
    }
}