#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
void stringpermutation(string str,string &temp,vector<bool>&ismarked,int len,set<string>&ans){
    if(temp.size()==len){
        ans.insert(temp);
        return;
    }
    for(int i=0;i<len;i++){
        if(ismarked[i]==1){
            continue;
        }
        ismarked[i]=1;
        temp+=str[i];
        stringpermutation(str,temp,ismarked,len,ans);
        ismarked[i]=0;
        temp.pop_back();
    }

}
int main(){
    string str;
    cin>>str;
    set<string>ans;
    int len=str.size();
    vector<bool>ismarked(len,0);
    string temp="";
    stringpermutation(str,temp,ismarked,len,ans);
    cout<<ans.size()<<endl;
    for(auto &it:ans){
        cout<<it<<endl;
    }

}