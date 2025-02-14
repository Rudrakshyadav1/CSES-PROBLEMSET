#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> data(n);
    stack<pair<int, int>> temp;
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }
    for (int i = 0; i < n; i++){
        if (temp.empty()) {
            cout << 0 << " ";
            temp.push(make_pair(data[i], i + 1));
        }
        else if(data[i] > temp.top().first){
            cout << temp.top().second << " ";
            temp.push(make_pair(data[i], i + 1));
        }
        else{
            while (!temp.empty() && data[i] < temp.top().first){
                temp.pop();
            }
            if (!temp.empty() && temp.top().first !=data[i]){
                cout << temp.top().second << " ";
            }
            else{
                cout << 0 << " ";
            }
            temp.push(make_pair(data[i], i + 1));
        }
    }
}
