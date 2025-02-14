#include<iostream>
using namespace std;
void knightposition(long long n){
    long long num = 4*(n-1)*(n-2);
    long long k=n*n;
    long long total= (k * (k - 1)) / 2;
    cout<<(total-num)<<endl;
}
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        if(i==1){
            cout<<0<<endl;
        }
        else if(i==2){
            cout<<6<<endl;
        }
        else{ 
            knightposition(i);
        }
       
    }

}