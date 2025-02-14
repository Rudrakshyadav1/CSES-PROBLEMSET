#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>temp;
    int steps=0;
    int temp_prev=0;
    for(int i=0;i<n;i++){
        if(temp.size()==0){
            temp.push_back(a[i]);
            temp_prev=a[i];
            steps++;
        }
        if(a[i]>temp_prev){
            temp.push_back(a[i]);
            temp_prev=a[i];
            steps++;
        }
        else{
            auto it =lower_bound(temp.begin(),temp.end(),a[i]);
            if(it==temp.end()){
                temp.push_back(a[i]);
                steps++;
                temp_prev=a[i];
            }
            else{
               *it=a[i];
            }
        }
    }
    cout<<steps;
}