//doesn't pass on 5, 6
#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, M, R;
ll ans = 0, tempans = 0;
vector<ll> milk, mpsum;//gallons(milk)
vector<pair<ll, ll> > store, spsum;//a gallons of milk for b cents per gallon
vector<ll> neighbors, npsum;//rent a cow for r cents per day

bool mcomp(const int &a, const int &b){
    return a>b;
}

bool scomp(const pair<int, int>&a, const pair<int, int>&b){
    return a.second>b.second;
}

bool ncomp(const int&a, const int&b){
    return a>b;
}

int bsearch(int target){//lowerbound for target in spsum.f
    int low = 0, high = M, mid = (low+high)/2;
    while(low <= high){
        if(spsum[mid].f <= target && (mid == M || spsum[mid+1].f>target)){
            return mid;
        } else if(spsum[mid].f>target){
            high = mid-1;
            mid = (low+high)/2;
        } else{
            low = mid+1;
            mid = (low+high)/2;
        }
    }
}

int main(){

    ifstream fin("rental.in");
    ofstream fout("rental.out");

    fin >> N >> M >> R;
    for(int i=0; i<N; ++i){
        ll c; fin >> c;
        milk.pb(c);
    }
    sort(milk.begin(), milk.end(), mcomp);
    mpsum.pb(0);
    for(int i=0; i<N; ++i){
        mpsum.pb(mpsum[i]+milk[i]);
    }
    for(int i=0; i<M; ++i){
        ll q, r; fin >> q >> r;
        store.pb(mp(q,r));
    }
    sort(store.begin(), store.end(), scomp);
    spsum.pb(mp(0,0));
    for(int i=0; i<M; ++i){
        spsum.pb(mp(spsum[i].f+store[i].f, spsum[i].s+store[i].s*store[i].f));
    }
    for(int i=0; i<R; ++i){
        ll r; fin >> r;
        neighbors.pb(r);
    }
    sort(neighbors.begin(), neighbors.end(), ncomp);
    npsum.pb(0);
    for(int i=0; i<R; ++i){
        npsum.pb(npsum[i]+neighbors[i]);
    }
    for(int i=0; i<=N; ++i){
        ans = max(npsum[max(0,N-i)]+spsum[bsearch(mpsum[i])].s+(mpsum[i]-spsum[bsearch(mpsum[i])].f)*store[bsearch(mpsum[i])].s, ans);
    }
    fout << ans;

    return 0;
}
