#include<iostream>
#include<vector>
using namespace std;
void elementfinder(long long  row,long long col,vector<long long >&answer){
    long long  sq;
    if(row>col){
        if(row%2==0){
            sq=row*row;
            answer.push_back(sq-col+1);
            }
        else{
            sq=(row-1)*(row-1);
            answer.push_back(sq+col);
        }
    }
    else if (row==col){
        sq=(row-1)*(row-1);
        answer.push_back(col+sq);
    }
    else{
        if(col%2==0){
            sq=(col-1)*(col-1);
            answer.push_back(sq+row);
        }
        else{
            sq=col*col;
           answer.push_back(sq-row+1);
        }
    }
}
int main(){
    long long row,col,t;
    cin>>t;
    vector<long long >answer;
    for(long long  i=0;i<t;i++){
        cin>>row;
        cin>>col;
        if(row==1 && col==1){
            answer.push_back(1);
        }
        else{
            elementfinder(row,col,answer);
        }
    }
    for(auto it : answer){
        cout<<it<<endl;
    }

}