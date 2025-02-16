#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n==2 ||n==3){
        cout<<  "NO SOLUTION";
    }
    else if(n==1){
        cout<<1;
    }
    else if(n==4){
        cout<<3<<" "<<1<<" "<<4<<" "<<2;
    
    }
    else{
        long long odd=1;
        long long even=2;
        while(odd<n){
            cout<<odd<<" ";
            odd+=2;
        }
        if(n%2!=0 ){
            cout<<n<<" ";
        }
        while(even<n){
            cout<<even<<" ";
            even+=2;
        }
        if(n%2==0){cout<<n;};
    }
}