#include "bits/stdc++.h"
#define pb push_back
using namespace std;

int N, ans = 0;
vector<char> fj;
vector<vector<int> > psum;//hps

int main(){

    ifstream fin("hps.in");
    ofstream fout("hps.out");

    fin >> N;
    for(int i=0; i<N; ++i){
        char c; fin >> c;
        fj.pb(c);
    }
    psum.pb({0,0,0});
    for(int i=0; i<N; ++i){
        if(fj[i] == 'H'){
            psum.pb({psum[i][0]+1, psum[i][1], psum[i][2]});
        } else if(fj[i] == 'P'){
            psum.pb({psum[i][0], psum[i][1]+1, psum[i][2]});
        } else{
            psum.pb({psum[i][0], psum[i][1], psum[i][2]+1});
        }
    }
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            for(int k=1; k<N; ++k){
                if(psum[k][i]+(psum[N][j]-psum[k][j]) > ans){
                    ans = psum[k][i]+(psum[N][j]-psum[k][j]);
                }
            }
        }
    }
    fout << ans;

    return 0;
}
