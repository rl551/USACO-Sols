#include "bits/stdc++.h"
using namespace std;

int N, K;
vector<int> haybales;

bool check(int R){
    int curindex=-1;
    for(int i=0; i<K; ++i){
        curindex++;
        auto nextindex=upper_bound(haybales.begin(), haybales.end(), haybales[curindex]+2*R); nextindex--;
        curindex = nextindex-haybales.begin();
        if(curindex >= N-1) return true;
    }
    return(curindex >= N-1);
}

int main(){

    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin >> N >> K;
    for(int i=0; i<N; ++i){
        int x_i; fin >> x_i;
        haybales.push_back(x_i);
    }
    sort(haybales.begin(), haybales.end());
    int lo=0, hi=1e9, ans;
    while(lo<=hi){//false, false, ..., false, true, true, true, ...
        int mi=(lo+hi)/2;
        if(check(mi)){
            ans=mi;
            hi=mi-1;
        } else lo=mi+1;
    }
    fout << ans;

    return 0;
}
