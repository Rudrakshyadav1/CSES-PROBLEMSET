#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool issafe(int row, int col, vector<pair<int, int> >& queenlocator){
    for (int i = 0; i < queenlocator.size(); i++){
        int r = queenlocator[i].first;
        int c = queenlocator[i].second;
        if (r == row || c == col || (r - c) == (row - col) || (r + c) == (row + col)){
            return false; 
        }
    }
    return true;
}
void queenplacer(int row, bool ismarked[8][8], char arr[8][8], int &qc, int &ans, vector<pair<int, int> >& queenlocator) {
    if (row == 8) {
        if (qc == 8) {
            ans++;
        }
        return;
    }

    for (int i = 0; i < 8; i++){
        if (arr[row][i] != '*' && !ismarked[row][i] && issafe(row, i, queenlocator)) {
            ismarked[row][i] = 1;
            qc++;
            queenlocator.push_back(make_pair(row,i));
            queenplacer(row + 1, ismarked, arr, qc, ans, queenlocator);
            ismarked[row][i] = 0;
            qc--;
            queenlocator.pop_back();
        }
    }
}
int main(){
    char arr[8][8];
    vector<pair<int, int> > queenlocator;
    bool ismarked[8][8] = {0};
    int qc = 0;
    int ans = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> arr[i][j];
        }
    }
    queenplacer(0, ismarked, arr, qc, ans, queenlocator);
    cout << ans << endl;
}
