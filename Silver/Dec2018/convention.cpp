#include "bits/stdc++.h"
using namespace std;

int N, M, C;
vector<int> times;
bool check(int T){
    long long curindex=-1;
    for(int i=0; i<M; ++i){
        curindex++;
        auto nextindex=upper_bound(times.begin(), times.end(), times[curindex]+T); nextindex--;
        if((nextindex-times.begin())-curindex+1 <= C) curindex=nextindex-times.begin();
        else curindex += (C-1);
        if(curindex >= N-1) return true;
    }
    return(curindex >= N-1);
}

int main(){

    ifstream fin("convention.in");
    ofstream fout("convention.out");
    fin >> N >> M >> C;
    for(int i=0; i<N; ++i){
        int t; fin >> t;
        times.push_back(t);
    }
    sort(times.begin(), times.end());
    int lo=0, hi=1e9, ans;
    while(lo<=hi){
        int mi=(lo+hi)/2;
        if(check(mi)){
            ans=mi;
            hi=mi-1;
        } else lo=mi+1;
    }
    fout << ans;

    return 0;
}
