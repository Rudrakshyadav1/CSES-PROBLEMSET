#include<iostream>
using namespace std;
void towerofhanoi(int n, int source, int auxiliary, int destination){
    if (n == 1){
        cout << source << " "<< destination << endl; 
        return;
    }
    towerofhanoi(n - 1, source, destination, auxiliary); 
    cout << source << " "<< destination << endl; 
    towerofhanoi(n - 1, auxiliary, source, destination);
}
int main() {
    int source = 1;
    int auxiliary = 2;
    int destination = 3;
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl; 
    
    towerofhanoi(n, source, auxiliary, destination);

}
