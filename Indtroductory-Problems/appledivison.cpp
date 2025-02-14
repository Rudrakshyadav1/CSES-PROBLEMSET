#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> weight(n, 0);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        cin >> weight[i];
        sum += weight[i];
    }
    if (n == 1){
        cout << weight[0];
        return 0;
    }

    long long mini = LONG_MAX;

    for (int i = 1; i < (1 << n) - 1; i++){
        vector<long long> a;
        vector<long long> b;

        for (int j = n - 1; j >= 0; j--){
            int binary = i & (1 << j);
            if (binary) {
                a.push_back(weight[j]);
            } else {
                b.push_back(weight[j]);
            }
        }

        long long suma = 0;
        for (vector<long long>::size_type k = 0; k < a.size(); k++){
            suma += a[k];
        }

        long long sumb = 0;
        for (vector<long long>::size_type k = 0; k < b.size(); k++){
            sumb += b[k];
        }
        mini = min(abs(suma - sumb), mini);
    }
    cout << mini;
}