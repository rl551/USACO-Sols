#include "bits/stdc++.h"
using namespace std;

bool over;
int N, K, counter, grid[100][10], visited[100][10];
vector<int> notzero;

void ff(int i, int j, int c){
	if(visited[i][j] || (i<0 || i>=N || j<0 || j>=10) || grid[i][j] != c) return;
	visited[i][j] = true;
	counter++;
	ff(i-1, j, c);
	ff(i+1, j, c);
	ff(i, j-1, c);
	ff(i, j+1, c);
}

void change(int i, int j, int c){
	if(!visited[i][j] || (i<0 || i>=N || j<0 || j>=10) || grid[i][j] != c) return;
	grid[i][j] = 0;
	change(i-1, j, c);
	change(i+1, j, c);
	change(i, j-1, c);
	change(i, j+1, c);
}

int main(){
	ifstream fin("mooyomooyo.in");
	ofstream fout("mooyomooyo.out");
	fin >> N >> K;
	for(int i=0; i<N; ++i){
		string s; fin >> s;
		for(int j=0; j<10; ++j) grid[i][j]=(s[j]-'0');
	}
	while(!over){
		fill(&visited[0][0], &visited[0][0]+1000, false);
		over = true;
		for(int i=0; i<N; ++i){
			for(int j=0; j<10; ++j){
				if(!visited[i][j] && grid[i][j] != 0){
					counter=0;
					ff(i, j, grid[i][j]);
					if(counter >= K){
						change(i, j, grid[i][j]);
						over = false;
					}
				}
			}
		}
		if(over) break;
		for(int i=0; i<10; ++i){
			notzero.clear();
			for(int j=N-1; j>=0; --j){
				if(grid[j][i] != 0) notzero.push_back(grid[j][i]);
			}
			for(int j=0; j<notzero.size(); ++j) grid[N-1-j][i] = notzero[j];
			for(int j=N-1-notzero.size(); j>=0; --j) grid[j][i] = 0;
		}
	}
	for(int i=0; i<N; ++i){
		string ans="";
		for(int j=0; j<10; ++j) ans += to_string(grid[i][j]);
		fout << ans << endl;
	}

	return 0;
}
