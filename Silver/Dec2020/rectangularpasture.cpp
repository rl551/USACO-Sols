#include "bits/stdc++.h"
const int MAXN=2500+1;
using namespace std;

int N, psum[MAXN][MAXN], iscows[MAXN][MAXN];
long long counter;
pair<int, int> cows[MAXN];
bool xcomp(const pair<int, int>&a, const pair<int, int>&b){
    return a.first<b.first;
}
bool ycomp(const pair<int, int>&a, const pair<int, int>&b){
    return a.second<b.second;
}

int main(){

    cin >> N;
    for(int i=1; i<=N; ++i) cin >> cows[i].first >> cows[i].second;
    sort(cows+1, cows+N+1, xcomp);
    for(int i=1; i<=N; ++i) cows[i].first=i;
    sort(cows+1, cows+N+1, ycomp);
    for(int i=1; i<=N; ++i) cows[i].second=i;
    sort(cows+1, cows+N+1, ycomp);
    for(int i=1; i<=N; ++i) iscows[cows[i].first][cows[i].second]=1;
    for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j) psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+iscows[i][j];
    for(int y1=1; y1<=N; ++y1){
        for(int y2=y1+1; y2<=N; ++y2){
            int x1=min(cows[y1].first, cows[y2].first);
            int x2=max(cows[y1].first, cows[y2].first);
            int l=psum[x1][y2]-psum[x1][y1-1]-psum[0][y2]+psum[0][y1-1];
            int r=psum[N][y2]-psum[x2-1][y2]-psum[N][y1-1]+psum[x2-1][y1-1];
            counter += r*l;
        }
    }
    cout << counter+N+1;

    return 0;
}
