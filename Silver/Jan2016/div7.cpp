#include "bits/stdc++.h"
#define pb push_back
using namespace std;

int N, ans = 0, l=0, r=0;
vector<int> v, psum;

int main(){

    ifstream fin("div7.in");
    ofstream fout("div7.out");

    fin >> N;
    for(int i=0; i<N; ++i){
        int x; fin >> x;
        v.pb(x);
    }
    psum.pb(0);
    for(int i=0; i<N; ++i){
        psum.pb((psum[i]+v[i])%7);
    }
    for(int i=0; i<7; ++i){
        for(int j=0; j<N; ++j){
            if(i == psum[j]){
                l = j;
                break;
            }
        }
        for(int j=N-1; j>=0; --j){
            if(i == psum[j]){
                r = j;
                break;
            }
        }
        if(r-l > ans){
            ans = r-l;
        }
    }
    fout << ans;
    
    return 0;
}
