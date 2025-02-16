#include <iostream>
#include <string>
using namespace std;
const int n = 7;
const int total_steps=48;
bool visited[n][n];
string path;
void move(int row, int col, int &ans, int &steps) {
    if (row == n - 1 && col == 0) {
        if (steps == total_steps) {
            ans++;
        }
        return;
    }
    if (((row + 1 == n || (visited[row - 1][col] && visited[row + 1][col])) && col - 1 >= 0 && col + 1 < n && !visited[row][col - 1] && !visited[row][col + 1])){
        return;
    }
    if (((col + 1 == n || (visited[row][col - 1] && visited[row][col + 1])) && row - 1 >= 0 && row + 1 < n && !visited[row - 1][col] && !visited[row + 1][col])){
        return;
    }
    if (((row == 0 || (visited[row + 1][col] && visited[row - 1][col])) && col - 1 >= 0 && col + 1 < n && !visited[row][col - 1] && !visited[row][col + 1])){
        return;
    }
    if (((col == 0 || (visited[row][col + 1] && visited[row][col - 1])) && row - 1 >= 0 && row + 1 < n && !visited[row - 1][col] && !visited[row + 1][col])){
        return;
    }
    visited[row][col] = true;
    if (path[steps] != '?') {
        if (path[steps] == 'U') {
            if (row - 1 >= 0) {
                if (!visited[row - 1][col]) {
                    steps++;
                    move(row - 1, col, ans, steps);
                    steps--;
                }
            }
        }
        else if (path[steps] == 'R') {
            if (col + 1 < n) {
                if (!visited[row][col + 1]) {
                    steps++;
                    move(row, col + 1, ans, steps);
                    steps--;
                }
            }
        }
        else if (path[steps] == 'D') {
            if (row + 1 < n) {
                if (!visited[row + 1][col]) {
                    steps++;
                    move(row + 1, col, ans, steps);
                    steps--;
                }
            }
        }
        else if (path[steps] == 'L') {
            if (col - 1 >= 0) {
                if (!visited[row][col - 1]) {
                    steps++;
                    move(row, col - 1, ans, steps);
                    steps--;
                }
            }
        }
    }
    else {
        if (row + 1 < n) {
            if (!visited[row + 1][col]) {
                steps++;
                move(row + 1, col, ans, steps);
                steps--;
            }
        }
        if (col + 1 < n) {
            if (!visited[row][col + 1]) {
                steps++;
                move(row, col + 1, ans, steps);
                steps--;
            }
        }
        if (row - 1 >= 0) {
            if (!visited[row - 1][col]) {
                steps++;
                move(row - 1, col, ans, steps);
                steps--;
            }
        }
        if (col - 1 >= 0) {
            if (!visited[row][col - 1]) {
                steps++;
                move(row, col - 1, ans, steps);
                steps--;
            }
        }
    }
    visited[row][col] = false;
}

int main() {
    cin >> path;

    int ans = 0, steps = 0;
    move(0, 0, ans, steps);
    cout << ans << endl;
}
