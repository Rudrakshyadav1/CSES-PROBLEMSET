// solved here by recurssive approach 
//but can also be done by using gray code formula=> i^(i>>1) ;i->[0,2^n-1]
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> graycode(int n){
    if (n == 0){
        vector<string> result;
        result.push_back("0");
        return result;
    }
    if (n == 1){
        vector<string> result;
        result.push_back("0");
        result.push_back("1");
        return result;
    }
    vector<string> zeroadd = graycode(n - 1);
    for (auto &it : zeroadd) {
        it = "0" + it;
    }
    vector<string> oneaddition = graycode(n - 1);
    for (auto &it : oneaddition){
        it="1"+it;
    }
    zeroadd.insert(zeroadd.end(), oneaddition.rbegin(), oneaddition.rend());
    
    return zeroadd;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = graycode(n);
    for (auto &it : ans){
        cout << it << endl;
    }

    return 0;
}
