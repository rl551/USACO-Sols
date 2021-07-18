#include "bits/stdc++.h"
#define MAXN 101
const int X_CHANGE[]={1, 0, -1, 0};
const int Y_CHANGE[]={0, -1, 0, 1};
using namespace std;

int N, M, ans;
bool visited[MAXN][MAXN], lit[MAXN][MAXN];
vector<vector<pair<int, int> > > light(1e4);//(i,j) --> 100(i-1)+j

void ff(int i, int j){
	if(visited[i][j] || !lit[i][j] || (i<1 || i>N || j<1 || j>N)) return;
	visited[i][j] = true;
	for(int k=0; k<light[100*(i-1)+j].size(); ++k){	
		if(!lit[light[100*(i-1)+j][k].first][light[100*(i-1)+j][k].second] && !visited[light[100*(i-1)+j][k].first][light[100*(i-1)+j][k].second]){
			lit[light[100*(i-1)+j][k].first][light[100*(i-1)+j][k].second]=true;
			for(int l=0; l<4; ++l){
				if(
					(1<=light[100*(i-1)+j][k].first+X_CHANGE[l] && light[100*(i-1)+j][k].first+X_CHANGE[l]<=N) &&
					(1 <= light[100*(i-1)+j][k].second+Y_CHANGE[l] && light[100*(i-1)+j][k].second+Y_CHANGE[l]<= N) &&
					visited[light[100*(i-1)+j][k].first+X_CHANGE[l]][light[100*(i-1)+j][k].second+Y_CHANGE[l]]
				) ff(light[100*(i-1)+j][k].first, light[100*(i-1)+j][k].second);
			}
		}
	}
	ff(i-1,j);
	ff(i+1,j);
	ff(i,j-1);
	ff(i,j+1);
}

int main(){
	ifstream fin("lightson.in");
	ofstream fout("lightson.out");
	fin >> N >> M;
	for(int i=0; i<M; ++i){
		int x, y, a, b; fin >> x >> y >> a >> b;
		light[100*(x-1)+y].push_back(make_pair(a,b));
	}
	lit[1][1] = true;
	ff(1,1);
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			if(lit[i][j]) ans++;
		}
	}
	fout << ans;

	return 0;
}
