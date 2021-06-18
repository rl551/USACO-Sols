#include "bits/stdc++.h"
#define pb push_back
using namespace std;

int N, Q;
vector<int> cows;
vector<vector<int> > psum;//h, g, j

int main(){

    ifstream fin("bcount.in");
    ofstream fout("bcount.out");

    fin >> N >> Q;
    for(int i=0; i<N; ++i){
        int c; fin >> c;
        cows.pb(c);
    }
    psum.pb({0, 0, 0});
    for(int i=0; i<N; ++i){
        if(cows[i] == 1){
            psum.pb({psum[i][0]+1, psum[i][1], psum[i][2]});
        } else if(cows[i] == 2){
            psum.pb({psum[i][0], psum[i][1]+1, psum[i][2]});
        } else{
            psum.pb({psum[i][0], psum[i][1], psum[i][2]+1});
        }
    }
    for(int i=0; i<Q; ++i){
        int a, b; fin >> a >> b;
        fout << psum[b][0]-psum[a-1][0] << " " << psum[b][1]-psum[a-1][1] << " " << psum[b][2]-psum[a-1][2] << endl;
    }

    return 0;
}
