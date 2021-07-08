#include "bits/stdc++.h"//timeout on tc10
#define f first
#define s second
using namespace std;
bool done = true;
int N, M;
vector<int> cows(1e5+1), temp;
vector<vector<pair<int, int> > > adj(1e5+1);
vector<bool> visited(1e5+1);
void dfs(int start, int mid){
    if(visited[start]){
        return;
    }
    visited[start] = true;
    temp.push_back(start);
    for(auto u: adj[start]){
        if(u.second >= mid){
            dfs(u.first, mid);
        }
    }
}
bool inarray(int target){
    int lo=0, hi=temp.size()-1, mi=(lo+hi)/2;
    while(lo <= hi){
        if(temp[mi] == target){
            return true;
        } else if(temp[mi] < target){
            lo=mi+1;
            mi=(lo+hi)/2;
        } else{
            hi=mi-1;
            mi=(lo+hi)/2;
        }
    }
    return false;
}
bool check(int mid){
    fill(visited.begin(), visited.end(), false);
    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            temp.clear();
            dfs(i, mid);
            sort(temp.begin(), temp.end());
            for(int j=0; j<temp.size(); ++j){
                if(cows[temp[j]] != temp[j] && !inarray(cows[temp[j]])){
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    fin >> N >> M;
    for(int i=1; i<=N; ++i){
        fin >> cows[i];
    }
    for(int i=1; i<=M; ++i){
        int a, b, w; fin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    for(int i=1; i<=N; ++i){
        if(cows[i] != i){
            done = false;
            break;
        }
    }
    if(done){
        fout << -1;
        return 0;
    } else{
        int low=0, high=1e9, mid=(low+high)/2;
        while(low <= high){
            if(check(mid) && !check(mid+1)){
                fout << mid;
                break;
            } else if(!check(mid)){
                high = mid-1;
                mid = (low+high)/2;
            } else{
                low = mid+1;
                mid = (low+high)/2;
            }
        }
    }
}
