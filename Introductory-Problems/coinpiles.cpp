#include<iostream>
using namespace std;
int main() {
    long long a, b, t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a == 0 && b == 0){
            cout << "YES" << endl;
        } 
        else if(a * b == 0){
            cout << "NO" << endl;
        } 
        else if((a + b) % 3 != 0 || a > 2 * b || b > 2 * a) {
            cout << "NO" << endl;
        } 
        else{
            cout << "YES" << endl;
        }
    }
}
