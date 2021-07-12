#include "bits/stdc++.h"
#define NM 1e5+1
using namespace std;

bool possible = true;
int counter=0, N, M;
vector<vector<int> >same(NM), dif(NM);
vector<bool> visited(NM), grass(NM);

void dfs(int start, bool c){
    if(visited[start]) return;
    visited[start] = true;
    grass[start] = c;
    for(auto u: same[start]){
        if(visited[u]){
            if(grass[start] != grass[u]) possible = false;
        } else dfs(u,c);
    }
    for(auto u: dif[start]){
        if(visited[u]){
            if(grass[start] == grass[u]) possible = false;
        } else dfs(u,!c);
    }
}

int main(){

    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    fin >> N >> M;
    for(int i=1; i<=M; ++i){
        char c; int a, b; fin >> c >> a >> b;
        if(c == 'S'){
            same[a].push_back(b);
            same[b].push_back(a);
        } else{
            dif[a].push_back(b);
            dif[b].push_back(a);
        }
    }
    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            counter++;
            dfs(i, 0);
        }
    }
    if(!possible) fout << 0;
    else{
        string ans ="";
        for(int i=0; i<counter; ++i){
            ans += "0";
        }
        fout << "1" << ans;
    }

    return 0;
}
