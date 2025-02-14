#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
string create_palindrome(const string&s){
    unordered_map<char, long long> freq;  
    for (char c : s) {
        freq[c]++;
    }
    long long odd_count = 0;
    char odd_char=0;
    vector<char>left_half;
    for(auto&entry : freq){
        char c = entry.first;
        long long count = entry.second;
        if(count % 2 == 1){
            odd_count++;
            odd_char = c;
            if(odd_count > 1){
                return "NO SOLUTION";
            }
        }
        for(long long i = 0; i < count/2; i++){
            left_half.push_back(c);
        }
    }
    string left_str(left_half.begin(),left_half.end());
    string right_str(left_str.rbegin(),left_str.rend()); 
    if(odd_count == 1){
        return left_str + odd_char + right_str;
    }
    else{
        return left_str + right_str;
    }
}
int main(){
    string s;
    cin >> s;
    cout << create_palindrome(s) << endl;
}