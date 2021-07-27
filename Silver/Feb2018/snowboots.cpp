//wrong on tc 4,9
#include "bits/stdc++.h"
#define MAX_SIZE 250+1//1-indexed
using namespace std;

int N, B;
bool visited[MAX_SIZE][MAX_SIZE];
vector<int> snow(MAX_SIZE);
vector<pair<int, int> > boots(MAX_SIZE);//boots[i].first is max(snow) and boots[i].second is max(dist)

void ff(int curboot, int curindex){
	if((curindex<1 || curindex>N) || visited[curboot][curindex] || snow[curindex] > boots[curboot].first) return;
	visited[curboot][curindex] = true;
	for(int i=1; i<=boots[curboot].second; ++i) ff(curboot, curindex+i);
}

int main(){

	ifstream fin("snowboots.in");
	ofstream fout("snowboots.out");
	fin >> N >> B;
	for(int i=1; i<=N; ++i) fin >> snow[i];
	for(int i=1; i<=B; ++i) fin >> boots[i].first >> boots[i].second;
	ff(1,1);
	for(int i=2; i<=B; ++i){
		for(int j=1; j<=N; ++j){
			if(visited[i-1][j]) ff(i,j);
		}
		if(visited[i][N]){
			fout << i-1;
			return 0;
		}
	}
	fout << B;
}
