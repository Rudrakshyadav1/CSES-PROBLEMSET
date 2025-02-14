#include<iostream>
#include<vector>
#include<algorithm>
#include<climits> 
using namespace std;
typedef long long ll;
class range{
public:
    ll left, right, index;
};
int main(){
    ll n;
    cin >> n;
    vector<range>data(n);
    vector<bool>contained(n,false);
    vector<bool>contains(n,false); 
    for (ll i = 0; i < n; i++){
        cin >> data[i].left >> data[i].right;
        data[i].index = i; 
    }
    sort(data.begin(), data.end(), [](auto &element, auto &element2){
        return (element.left < element2.left) || 
               (element.left == element2.left && element.right < element2.right);
    });
    ll mini = INT_MAX;
    for (ll i = data.size()- 1; i >= 0; i--){
        if (data[i].right>=mini){
            contains[data[i].index] = true;  
        }
        mini = min(mini, data[i].right);  
    }
    for (ll i = 0; i < contains.size(); i++){
        cout << contains[i] << " ";
    }
    cout << endl;
    ll maxi = 0;
    for (ll i = 0; i < data.size(); i++){
        if (data[i].right <= maxi) {
            contained[data[i].index] = true;  
        }
        else{
            maxi = max(maxi, data[i].right); 
        }
    }
    for(ll i = 0; i < contained.size(); i++){
        cout << contained[i] << " ";
    }
    cout << endl;
}
