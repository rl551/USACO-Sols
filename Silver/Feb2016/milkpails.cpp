#include "bits/stdc++.h"
using namespace std;

int X, Y, K, M, ans=1e3;
bool visited[101][101][101];
//the way we do dfs is to create a 3-D vector, where the 3rd dimension is the number of operations it takes to get to this state
//time comlexity iis O(XYK)

void ff(int i, int j, int curT){
    if(visited[i][j][curT] || (i<0 || i>100 || j<0 || j>100) || curT>K) return;
    visited[i][j][curT] = true;
    ff(0, j, curT+1);
    ff(i, 0, curT+1);
    ff(i, Y, curT+1);
    ff(X, j, curT+1);
    if(i+j <= Y) ff(0, i+j, curT+1);
    else ff(i-(Y-j), Y, curT+1);
    if(i+j <= X) ff(i+j, 0, curT+1);
    else ff(X, j-(X-i), curT+1);
}

int main(){

    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin >> X >> Y >> K >> M;
    ff(0,0,0);
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++j){
            for(int k=0; k<=K; ++k){
                if(visited[i][j][k]) ans=min(ans, abs(M-i-j));
            }
        }
    }
    fout << ans;

    return 0;
}
