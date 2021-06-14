#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, ans=0, counter=0;
vector<pair<pair<int, int>, int> > cows;
vector<bool> visited(200);
vector<vector<int> > adj(200);

void dfs(int start){
    if(visited[start]){
        return;
    }
    visited[start] = true;
    for(auto &u: adj[start]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

int main(){

    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    fin >> N;
    for(int i=0; i<N; ++i){
        int x, y, p;
        fin >> x >> y >> p;
        cows.pb(mp(mp(x,y),p));
    }
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            if(pow(cows[i].f.f-cows[j].f.f,2)+pow(cows[i].f.s-cows[j].f.s,2) <= pow(cows[i].s,2)){
                adj[i].pb(j);
            }
            if(pow(cows[i].f.f-cows[j].f.f,2)+pow(cows[i].f.s-cows[j].f.s,2) <= pow(cows[j].s,2)){
                adj[j].pb(i);
            }
        }
    }
    for(int i=0; i<N; ++i){
        counter = 0;
        fill(visited.begin(), visited.end(), false);
        dfs(i);
        for(int j=0; j<N; ++j){
            if(visited[j]){
                counter++;
            }
        }
        if(counter>ans){
            ans=counter;
        }
    }
    fout << ans;

    return 0;
}
