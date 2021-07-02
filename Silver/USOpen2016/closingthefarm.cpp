#include "bits/stdc++.h"
#define pb push_back
using namespace std;

int N, M;
vector<vector<int> > adj(3001);
vector<int> close;
vector<bool> ordered(3001), visited(3001);

void dfs(int start){
    if(visited[start] || !ordered[start]){
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

    ifstream fin("closing.in");
    ofstream fout("closing.out");
    fin >> N >> M;
    for(int i=0; i<M; ++i){
        int a, b; fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=0; i<N; ++i){
        int x; fin >> x;
        close.pb(x);
        ordered[x]=true;
    }
    for(int i=0; i<N; ++i){
        fill(visited.begin(), visited.end(), false);
        dfs(close[N-1]);
        bool possible = true;
        for(int j=1; j<=N; ++j){
            if(ordered[j] && !visited[j]){
                possible = false;
            }
        }
        if(possible){
            fout << "YES" << endl;
        } else{
            fout << "NO" << endl;
        }
        ordered[close[i]] = false;
    }
    
    return 0;
}
