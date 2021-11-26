#include "bits/stdc++.h"
const int MAXN=1e5+7;
using namespace std;

int N, M, itr=-1, cc[MAXN];
string s, ans="";
bool visited[MAXN];
vector<vector<int> > adj(MAXN), CC;
void dfs(int start, int itr){
    if(visited[start]) return;
    visited[start] = true;
    CC[itr].push_back(start);
    for(auto u: adj[start]){
        if(!visited[u] && s[start-1] == s[u-1]) dfs(u,itr);
    }
}

int main(){

    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");
    fin >> N >> M >> s;
    for(int i=0; i<N-1; ++i){
        int a,b; fin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            itr++; CC.push_back({});
            dfs(i,itr);
        }
    }
    for(int i=0; i<CC.size(); ++i){
        for(int j=0; j<CC[i].size(); ++j) cc[CC[i][j]]=i;
    }
    for(int i=0; i<M; ++i){
        int a,b; char c; fin >> a >> b >> c;
        if(cc[a] == cc[b] && s[a-1] != c) ans += '0';
        else ans += '1';
    }
    fout << ans;

    return 0;
}
