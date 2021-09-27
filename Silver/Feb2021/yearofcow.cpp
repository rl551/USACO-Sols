#include "bits/stdc++.h"
using namespace std;

int N, K, ans;
set<int> input;
vector<int> years, diff;

int main(){
    cin >> N >> K;
    for(int i=0; i<N; ++i){
        int y; cin >> y;
        if(y%12 == 0) input.insert(y/12);
        else input.insert(y/12+1);
    }
    for(auto u: input) years.push_back(u);
    ans = years.back();
    diff.push_back(years[0]);
    for(int i=0; i<years.size()-1; ++i) diff.push_back(years[i+1]-years[i]);
    sort(diff.begin(), diff.end());
    for(int i=diff.size()-1; i>=max(static_cast<int>(diff.size())-K+1, 0); --i) ans -= (diff[i]-1);
    cout << 12*ans;

    return 0;
}
