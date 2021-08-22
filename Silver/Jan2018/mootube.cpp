#include "bits/stdc++.h"
const int MAXN=5e3+11;
using namespace std;

int N, Q, K, v, counter;
vector<vector<pair<int, int> > > adj(MAXN);
void dfs(int cur_node, int last_node){
    counter++;
    for(auto u: adj[cur_node]) if(u.second >= K && u.first != last_node) dfs(u.first, cur_node);
}

int main(){

    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    fin >> N >> Q;
    while(N-->1){
        int p, q, r; fin >> p >> q >> r;
        adj[p].push_back(make_pair(q,r));
        adj[q].push_back(make_pair(p,r));
    }
    while(Q--){
        fin >> K >> v;
        counter=0;
        dfs(v, -1);
        fout << counter-1 << endl;
    }

    return 0;
}
