#include "bits/stdc++.h"
#define ll long long
#define MAXN 501
using namespace std;

int N;
int grid[MAXN][MAXN], atleast[MAXN][MAXN], psum[MAXN][MAXN];

ll solve(int target){//at least target
    ll ans = 0, tempcount = 0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            if(grid[i][j] >= target){
                atleast[i][j] = 1;
            } else{
                atleast[i][j] = 0;
            }
        }
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            psum[i][j] = psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+atleast[i][j];
        }
    }
    for(int i=1; i<=N; ++i){
        for(int j=i; j<=N; ++j){
            tempcount = 0;
            for(int k=1; k<=N; ++k){
                if(k == N){
                    if(psum[j][k]-psum[i-1][k]-psum[j][k-1]+psum[i-1][k-1] == j-i+1){
                        tempcount++;
                    }
                    ans += tempcount*(tempcount+1)/2;
                } else if(psum[j][k]-psum[i-1][k]-psum[j][k-1]+psum[i-1][k-1] == j-i+1){
                    tempcount++;
                } else{
                    ans += tempcount*(tempcount+1)/2;
                    tempcount = 0;
                }
            }
        }
    }
    return ans;
}

int main(){

    cin >> N;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin >> grid[i][j];
        }
    }
    cout << solve(100)-solve(101);

    return 0;
}
