#include "bits/stdc++.h"
const int MAXN=1e5+7;
using namespace std;

vector<bool> signals(MAXN);
vector<int> psum(MAXN);
int N, K, B, ans=1e8;

int main(){
	
	ifstream fin("maxcross.in");
	ofstream fout("maxcross.out");
	fill(signals.begin(), signals.end(), true);
	fin >> N >> K >> B;
	for(int i=0; i<B; ++i){
		int id; fin >> id;
		signals[id]=false;
	}
	for(int i=1; i<=N; ++i) psum[i]=psum[i-1]+signals[i];
	for(int i=1; i<=N-K+1; ++i) ans=min(ans, K-(psum[i+K-1]-psum[i-1]));
	fout << ans;

	return 0;
}
