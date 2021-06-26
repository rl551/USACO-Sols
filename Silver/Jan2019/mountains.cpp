#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, r, counter;
vector<pair<int, int> > mountains;

bool comp(pair<int, int>&a, pair<int, int>&b){
    if(a.f != b.f){
        return a.f<b.f;
    } else{
        return a.s<b.s;
    }
}

int main(){

    ifstream fin("mountains.in");
    ofstream fout("mountains.out");

    fin >> N;
    for(int i=0; i<N; ++i){
        int x, y; fin >> x >> y;
        mountains.pb(mp(x-y,x+y));
    }
    sort(mountains.begin(), mountains.end(), comp);
    r = mountains[0].s;
    counter = N;
    for(int i=1; i<N; ++i){
        if(r >= mountains[i].s){
            counter--;
        } else{
            r = mountains[i].s;
        }
    }
    fout << counter;

    return 0;
}
