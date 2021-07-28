#include "bits/stdc++.h"
const int X_CHANGE[]={0, 1, 0, -1};
const int Y_CHANGE[]={1, 0, -1, 0};
const int MAX_SIZE=2*880+1;
using namespace std;

string walk;
int N, x, y, ans;
bool grid[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE];

void ff(int i, int j){
	if(visited[i][j] || (i<0 || i>=MAX_SIZE || j<0 || j>=MAX_SIZE) || grid[i][j]) return;
	visited[i][j] = true;
	for(int k=0; k<4; ++k) ff(i+X_CHANGE[k], j+Y_CHANGE[k]);
}

int main(){

	ifstream fin("gates.in");
	ofstream fout("gates.out");
	fin >> N >> walk;
	for(int i=0; i<N; ++i){
		if(walk[i] == 'N'){
			for(int j=0; j<3; ++j) grid[x+880][y+880+j] = true;
			y += 2;
		}
		else if(walk[i] == 'S'){
			for(int j=0; j<3; ++j) grid[x+880][y+880-j] = true;
			y -= 2;
		}
		else if(walk[i] == 'W'){
			for(int j=0; j<3; ++j) grid[x+880-j][y+880] = true;
			x -= 2;
		}
		else if(walk[i] == 'E'){
			for(int j=0; j<3; ++j) grid[x+880+j][y+880] = true;
			x += 2;
		}
	}
	for(int i=0; i<MAX_SIZE; ++i){
		for(int j=0; j<MAX_SIZE; ++j){
			if(!visited[i][j] && !grid[i][j]){
				ans++;
				ff(i,j);
			}
		}
	}
	fout << ans-1;

	return 0;
}
