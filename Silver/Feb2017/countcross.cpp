#include "bits/stdc++.h"
using namespace std;

int N, K, R, notdistant, counter;
vector<pair<int, int> >cows;
bool grid[207][207], visited[107][107], cowsgrid[107][107];
/*
a point (i, j) is at grid[2i-2][2j-2]
between (i, j) and (i+1, j) is grid[2i-1][2j-2]
between (i, j) and (i-1, j) is grid[2i-3][2j-2]
between (i, j) and (i, j-1) is grid[2i-2][2j-3]
between (i, j) and (i, j+1) is grid[2i-2][2j-1]
*/

void ff(int i, int j){
    if(visited[i][j] || (i<=0 || i>N || j<=0 || j>N)) return;
    visited[i][j] = true;
    if(cowsgrid[i][j]) counter++;
    if(!grid[2*i-1][2*j-2]) ff(i+1, j);//(i, j) to (i+1, j)
    if(!grid[2*i-3][2*j-2]) ff(i-1, j);//(i, j) to (i-1, j)
    if(!grid[2*i-2][2*j-3]) ff(i, j-1);//(i, j) to (i, j-1)
    if(!grid[2*i-2][2*j-1]) ff(i, j+1);//(i, j) to (i, j+1)
}

int main(){

    ifstream fin("countcross.in");
    ofstream fout("countcross.out");
    fin >> N >> K >> R;
    for(int i=0; i<R; ++i){
        int r, c, rp, cp; fin >> r >> c >> rp >> cp;
        if(r == rp && c == cp+1) grid[2*r-2][2*c-3]=true;
        else if(r == rp && c == cp-1) grid[2*r-2][2*c-1]=true;
        else if(r == rp+1 && c == cp) grid[2*r-3][2*c-2]=true;
        else if(r == rp-1 && c == cp) grid[2*r-1][2*c-2]=true;
    }
    for(int i=0; i<K; ++i){
        int x, y; fin >> x >> y;
        cows.push_back(make_pair(x,y));
        cowsgrid[x][y] = true;
    }
    for(int i=0; i<K; ++i){
        if(!visited[cows[i].first][cows[i].second]){
            counter = 0;
            ff(cows[i].first, cows[i].second);
            notdistant += counter*(counter-1)/2;
        }
    }
    fout << K*(K-1)/2-ans;

	return 0;
}
