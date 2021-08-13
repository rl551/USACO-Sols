#include "bits/stdc++.h"
#define ll long long
using namespace std;

int N, M;
vector<pair<ll, ll> > intervals;
bool check(int D){
    ll curpos=intervals[0].first;
    for(int i=1; i<N; ++i){
        int lo=0, hi=M-1, ans;
        while(lo <= hi){
            int mi=(lo+hi)/2;
            if(intervals[mi].first <= curpos+D){
                ans=mi;
                lo=mi+1;
            } else hi=mi-1;
        }
        if(intervals[ans].first <= curpos+D && curpos+D <= intervals[ans].second) curpos += D;
        else{
            if(ans == M-1) return false;
            curpos=intervals[ans+1].first;
        }
    }
    return(curpos <= intervals[M-1].second);
}

int main(){

    ifstream fin("socdist.in");
    ofstream fout("socdist.out");
    fin >> N >> M;
    for(int i=0; i<M; ++i){
        ll a,b; fin >> a >> b;
        intervals.push_back(make_pair(a,b));
    }
    sort(intervals.begin(), intervals.end());
    int lo=0, hi=1e9, ans;
    while(lo<=hi){//true, true, ... ,true, false, false
        int mi=(lo+hi)/2;
        if(check(mi)){
            ans=mi;
            lo=mi+1;
        } else hi=mi-1;
    }
    fout << ans;

    return 0;
}
