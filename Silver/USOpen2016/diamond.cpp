#include "bits/stdc++.h"
const int MAXN=5e4+11;
using namespace std;

int N, K, ans, cur;
vector<int> diamonds, prefix(MAXN), suffix(MAXN);
vector<pair<int, int> > l, r;
int lb(int x){
    int lo=x, hi=N-1, ans;
    while(lo<=hi){
        int mi=(lo+hi)/2;
        if(diamonds[mi]<=diamonds[x]+K){
            ans=mi;
            lo=mi+1;
        } else hi=mi-1;
    }
    return ans;
}
int ub(int x){
    int lo=0, hi=x, ans;
    while(lo<=hi){
        int mi=(lo+hi)/2;
        if(diamonds[mi]>=diamonds[x]-K){
            ans=mi;
            hi=mi-1;
        } else lo=mi+1;
    }
    return ans;
}

int main(){

    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    fin >> N >> K;
    for(int i=0; i<N; ++i){
        int d; fin >> d;
        diamonds.push_back(d);
    }
    sort(diamonds.begin(), diamonds.end());
    for(int i=0; i<N; ++i) l.push_back(make_pair(i,lb(i)));
    for(int i=0; i<N; ++i) r.push_back(make_pair(ub(i),i));
    for(int i=N-1; i>=0; --i) prefix[i]=max(prefix[i+1], l[i].second-l[i].first+1);
    for(int i=0; i<N; ++i) suffix[i]=max(suffix[i-1], r[i].second-r[i].first+1);
    for(int i=0; i<N-1; ++i) ans=max(ans,suffix[i]+prefix[i+1]);
    fout << ans;

    return 0;
}
