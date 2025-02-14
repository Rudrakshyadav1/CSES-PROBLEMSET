#include<iostream>
#include<set>
using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;
    multiset<long long> pricetickets; 
    for(long long i = 0; i < n; i++){
        long long price;
        cin >> price;
        pricetickets.insert(price);
    }
    for(long long i = 0; i < m; i++){
        long long maxprice;
        cin >> maxprice;
        auto it = pricetickets.upper_bound(maxprice);

        if (it == pricetickets.begin()){
          
            cout << -1 << endl;
        }
        else{
            it--;
            cout << *it << endl;
            pricetickets.erase(it);
        }
    }

}

