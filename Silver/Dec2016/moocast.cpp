#include "bits/stdc++.h"
using namespace std;

int N, counter = 0, ans = -1;
vector<pair<pair<int, int>, int> > cows;
vector<int> visited(200);

void dfs(int start){
    if(visited[start]){return;}
    visited[start] = true;
    for(int j=0; j<N; ++j){
        if(!visited[j] && sqrt(pow(cows[j].first.first-cows[start].first.first,2)+pow(cows[j].first.second-cows[start].first.second,2)) <= cows[start].second){
            dfs(j);
        }
    }
}

int main(){

    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> N;
    for(int i=0; i<N; ++i){
        int x, y, p; fin >> x >> y >> p;
        cows.push_back(make_pair(make_pair(x,y),p));
    }
    for(int i=0; i<N; ++i){
        fill(visited.begin(), visited.end(), false);
        dfs(i);
        counter = 0;
        for(int j=0; j<N; ++j){
            if(visited[j]){counter++;}
        }
        if(counter>ans){ans=counter;}
    }
    fout << ans;
    
    return 0;
}
