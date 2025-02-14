#include<iostream>
#include<vector>
#include<climits>
#include<cmath> 
using namespace std;
typedef long long ll;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> data(n);
    int maxi = INT_MIN;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        cin >> data[i];
        maxi = max(maxi, data[i]);
        sum += data[i];
    }
    ll low = maxi;  
    ll high = sum;  
    ll prevmid = -1;  
    while (low <= high){
        ll mid = low + (high - low) / 2;
        int counter = 1;  
        ll current_sum = 0;
        for(int i = 0; i < n; i++){
            if(current_sum + data[i]>mid){
                counter++;
                current_sum =data[i];
                if (counter > k) break;
            }
            else{
                current_sum += data[i];
            }
        }
        if (counter > k){
            low = mid + 1; 
        }
        else{
            prevmid = mid;  
            high = mid - 1;
        }
    }
    cout << prevmid;
}
