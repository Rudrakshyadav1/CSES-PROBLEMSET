#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin >> str;
    if (str.size() > 1){
        long long length = 0;
        long long temp = 1;
        for (long long i = 0; i < str.size() - 1; i++){  
            if (str[i] == str[i + 1]){
                temp++;
                }
            else {
                length = max(length, temp);  
                temp = 1;
                }
        }
        length = max(length, temp);  
        cout << length;
        }
    else if(str.size() == 1) {
        cout << 1;
    }
    else{
        cout << 0;
    }
}
