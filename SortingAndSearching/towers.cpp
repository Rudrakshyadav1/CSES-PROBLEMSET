#include <iostream>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    multiset<int> num;
    while (n--){
        int a;
        cin >> a;
        num.insert(a);
        auto it = num.upper_bound(a);
        if(it !=num.end()){
        num.erase(it);
        }
    }
    cout << num.size() << endl;
}