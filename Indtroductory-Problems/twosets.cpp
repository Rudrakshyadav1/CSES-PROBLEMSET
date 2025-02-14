#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long total = n * (n + 1) / 2;
    if (total % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<long long> set1, set2;
    long long target = total / 2;
    for (long long i = n; i > 0; i--){
        if (target >= i) {
            set1.push_back(i);
            target -= i;
        }
        else {
            set2.push_back(i);
        }
    }
    cout << set1.size() << endl;
    for (auto num : set1){
        cout << num << " ";
    }
    cout << endl;

    cout << set2.size() << endl;
    for (auto num : set2){
        cout << num << " ";
    }
    cout << endl;
}
