//timeout on tc10 fsr(idek why)
#include "bits/stdc++.h"
const long NM=500;
const long long X_CHANGE[]={1, 0, -1, 0};
const long long Y_CHANGE[]={0, -1, 0, 1};
using namespace std;

long long M, N, course[NM][NM];
bool visited[NM][NM], waypoint[NM][NM];

void floodfill(long long i, long long j, long long D){
    if(visited[i][j] || (i<0 || i>=M || j<0 || j>=N)) return;
    visited[i][j] = true;
    for(int k=0; k<4; ++k){
        if(abs(course[i+X_CHANGE[k]][j+Y_CHANGE[k]]-course[i][j]) <= D) floodfill(i+X_CHANGE[k], j+Y_CHANGE[k], D);
    }
}
bool check(long long D){
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            visited[i][j] = false;
        }
    }
    floodfill(0,0,D);
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            if(waypoint[i][j] && !visited[i][j]) return false;
        }
    }
    return true;
}

int main(){
    ifstream fin("ccski.in");
    ofstream fout("ccski.out");
    fin >> M >> N;
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j) fin >> course[i][j];
    }
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j) fin >> waypoint[i][j];
    }
    long long lo = 0, hi = 1e9, best;
    while (lo <= hi) {
        long long mid = (lo+hi)/2;
        if (check(mid)) {
            best = mid;
            hi = mid-1;
        } else lo=mid+1;
    }
    fout << best;
    
    return 0;
}
