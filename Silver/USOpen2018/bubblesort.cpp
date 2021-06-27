//wrong on tc4
#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, ans = -1;
vector<pair<int, int> > A;

bool comp(pair<int, int>&a, pair<int, int>&b){
    if(a.f != b.f){
        return a.f<b.f;
    } else{
        return a.s<b.s;
    }
}

int main(){

    ifstream fin("sort.in");
    ofstream fout("sort.out");

    fin >> N;
    for(int i=0; i<N; ++i){
        int a; fin >> a;
        A.pb(mp(a,i));
    }
    sort(A.begin(), A.end(), comp);
    for(int i=0; i<N; ++i){
        ans = max(ans, abs(A[i].s-i));
    }
    fout << ans+1;

    return 0;
}
