#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
using namespace std;

int N, G, counter;
vector<pair<int, pair<int, int> > > change;
set<pair<int, int> > milk, input;
vector<pair<int, int> > curmilk;
int find(int x){
    int lo=0, hi=curmilk.size()-1;
    while(lo<=hi){
        int mi=(lo+hi)/2;
        if(curmilk[mi].first == x) return mi;
        else if(curmilk[mi].first<x) lo=mi+1;
        else hi=mi-1;
    }
}

int main(){

    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    fin >> N >> G;
    for(int i=0; i<N; ++i){
        int day, id, pm; fin >> day >> id >> pm;
        milk.insert(mp(G,id));
        input.insert(mp(id,G));
        change.pb(mp(day,mp(id,pm)));
    }
    for(int i=1; i<=N-static_cast<int>(input.size()); ++i) input.insert(mp(1e9+i,G));
    sort(change.begin(), change.end());
    for(auto u: input) curmilk.push_back(make_pair(u.first, u.second));
    for(int i=0; i<N; ++i){
        int id=change[i].second.first, pm=change[i].second.second;
        auto itr=milk.find(mp(curmilk[find(id)].second, id));
        auto itr2=milk.end(); itr2--;
        if((*itr).first != (*itr2).first){
            if((*itr).first+pm >= (*itr2).first) counter++;
        }else{
            itr2--;
            if((*itr).first == (*itr2).first) counter++;
            else if((*itr).first>(*itr2).first){
                if((*itr).first+pm <= (*itr2).first) counter++;
            }
        }
        milk.erase(mp(curmilk[find(id)].second, id));
        milk.insert(mp(curmilk[find(id)].second+pm, id));
        curmilk[find(id)].second += pm;
    }
    fout << counter;

    return 0;
}
