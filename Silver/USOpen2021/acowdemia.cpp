#include "bits/stdc++.h"
using namespace std;

const int MAXN=1e5+11;
long long N, K, L, citations[MAXN];
bool check(int h_index){
    long long num_citations=0;
    for(int i=N-1; i>=N-h_index; --i){
        if(citations[i] < h_index){
            if(h_index-citations[i]>K) return false;
            else num_citations += (h_index-citations[i]);
        }
    }
    return(num_citations <= K*L);
}

int main(){

    cin >> N >> K >> L;
    for(int i=0; i<N; ++i) cin >> citations[i];
    sort(citations, citations+N);
    int lo=0, hi=N, ans;
    while(lo <= hi){
        int mi=(lo+hi)/2;
        if(check(mi)){
            ans=mi;
            lo=mi+1;
        } else hi=mi-1;
    }
    cout << ans;

    return 0;
}
