#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
class project{
public:
    int start;
    int end;
    int price;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<project>projects(n);
    for (int i = 0; i < n; i++){
        cin >> projects[i].start >> projects[i].end >> projects[i].price;
    }
    sort(projects.begin(), projects.end(),[](project a, project b){
        return a.end < b.end;
    });
    set<pair<int, ll>> data;
    ll ans = 0;
    data.insert({0, 0});
    for (int i = 0; i < n; i++){
        auto it = data.lower_bound({projects[i].start, 0});
        if (it != data.begin()) {
            it--;
        }
        ans = max(ans, it->second + projects[i].price);
        data.insert({projects[i].end, ans});
    }
    cout << ans;
}
