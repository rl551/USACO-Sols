#include "bits/stdc++.h"
const int MAXN=1e5+11;
using namespace std;

int N, M, K, itr=-1, cnt, pos[MAXN], adj[MAXN];
pair<int, int> findCC[MAXN], Swap[100];
vector<vector<int> > connectedComponents;
bool visited[MAXN];
void dfs(int node, int itr){
    if(visited[node]) return;
    visited[node] = true;
    findCC[node] = make_pair(itr,cnt);
    connectedComponents[itr].push_back(node);
    cnt++;
    dfs(adj[node], itr);
}

int main(){

    ifstream fin("swap.in");
    ofstream fout("swap.out");
    fin >> N >> M >> K;
    for(int i=0; i<M; ++i) fin >> Swap[i].first >> Swap[i].second;
    for(int i=1; i<=N; ++i) pos[i]=i;
    for(int i=0; i<M; ++i) for(int j=Swap[i].first; j<=(Swap[i].second+Swap[i].first)/2; ++j) swap(pos[j], pos[Swap[i].first+Swap[i].second-j]);
    for(int i=1; i<=N; ++i) adj[pos[i]] = i;
    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            cnt=0; itr++;
            connectedComponents.push_back({});
            dfs(i,itr);
        }
    }
    for(int i=1; i<=N; ++i){
        int CC = findCC[i].first, index = findCC[i].second, remainder = K%static_cast<int>(connectedComponents[CC].size());
        pos[connectedComponents[CC][(index+remainder)%static_cast<int>(connectedComponents[CC].size())]]=i;
    }
    for(int i=1; i<=N; ++i) fout << pos[i] << endl;

    return 0;
}
