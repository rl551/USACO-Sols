#include "bits/stdc++.h"
#define f first
#define s second
using namespace std;

int N, counter;
vector<pair<int, int> > cows;
vector<bool> visited(1e3);

void dfs(int start, int X){
    if(visited[start]){
        return;
    }
    visited[start] = true;
    counter++;
    for(int i=0; i<N; ++i){
        if(i != start && !visited[i] && (pow(cows[start].f-cows[i].f,2)+pow(cows[start].s-cows[i].s,2) <= X)){
            dfs(i, X);
        }
    }
}
bool check(int X){
    counter = 0;
    fill(visited.begin(), visited.end(), false);
    dfs(0,X);
    return(!(counter<N));
}

int main(){
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> N;
    for(int i=0; i<N; ++i){
        int x, y; fin >> x >> y;
        cows.push_back(make_pair(x,y));
    }
    int l=1, h=1e9, m=(l+h)/2;
    while(l<=h){
        if(check(m) && !check(m-1)){
            fout << m;
            return 0;
        } else if(!check(m)){
            l=m+1;
            m=(l+h)/2;
        } else{
            h=m-1;
            m=(l+h)/2;
        }
    }
}
