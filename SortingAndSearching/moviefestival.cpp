#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main(){
    long long n;
    cin >> n;
    vector<pair<long long,long long> >movies(n);
    for (int i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(),[](const pair<long long,long long>& a, const pair<long long , long long>& b){
        return a.second < b.second;}
        );
    long long count = 0;
    long long last_end_time = 0;
    for (const auto& movie : movies){
        if (movie.first >= last_end_time) {
            count++;
            last_end_time = movie.second;  
        }
    }
    cout << count << endl;
}
