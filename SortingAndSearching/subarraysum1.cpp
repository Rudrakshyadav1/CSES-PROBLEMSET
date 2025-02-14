#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> data(n);
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }
    int left = 0, right = 0;
    ll sum = data[0];
    int counter = 0;
    while (right<n){
        if(sum == x){
            counter++;
        } 
        if(sum < x && right < n - 1){ 
            right++;
            sum += data[right];
        }
        else if(sum > x && left <= right){ 
            sum -= data[left];
            left++;
        }
        else{
            right++;
            if(right < n){
                sum += data[right];
            }
        }
    }
    cout << counter << endl;
}
