#include "bits/stdc++.h"
using namespace std;

int N;
long long ans=4e9;
vector<pair<int, int> > cows, possible;
set<pair<int, int> > poss;
bool ycomp(const pair<int, int>&a, const pair<int, int>&b){
    if(a.first != b.first) return a.second<b.second;
    else return a.first<b.first;
}

int main(){

    ifstream fin("reduce.in");
    ofstream fout("reduce.out");
    fin >> N;
    for(int i=0; i<N; ++i){
        int x, y; fin >> x >> y;
        cows.push_back(make_pair(x,y));
    }
    sort(cows.begin(), cows.end());
    for(int i=0; i<3; ++i) poss.insert(make_pair(cows[i].first,cows[i].second));
    for(int i=N-1; i>=N-3; --i) poss.insert(make_pair(cows[i].first, cows[i].second));
    sort(cows.begin(), cows.end(), ycomp);
    for(int i=0; i<3; ++i) poss.insert(make_pair(cows[i].first,cows[i].second));
    for(int i=N-1; i>=N-3; --i) poss.insert(make_pair(cows[i].first, cows[i].second));
    for(auto u: poss) possible.push_back(u);
    for(int i=0; i<possible.size(); ++i){
        for(int j=i+1; j<possible.size(); ++j){
            for(int k=j+1; k<possible.size(); ++k){
                int xmin=1e5, xmax=-1, ymin=1e5, ymax=-1;
                for(int l=0; l<N; ++l){
                    if(!(
                        (cows[l].first == possible[i].first && cows[l].second == possible[i].second) ||
                        (cows[l].first == possible[j].first && cows[l].second == possible[j].second) ||
                        (cows[l].first == possible[k].first && cows[l].second == possible[k].second)
                        )
                    ){
                        if(cows[l].first <xmin) xmin=cows[l].first;
                        if(cows[l].first>xmax) xmax=cows[l].first;
                        if(cows[l].second<ymin) ymin=cows[l].second;
                        if(cows[l].second>ymax) ymax=cows[l].second;
                    }
                }
                if((xmax-xmin)*(ymax-ymin)<ans) ans=(xmax-xmin)*(ymax-ymin);
            }
        }
    }
    fout << ans;

    return 0;
}
