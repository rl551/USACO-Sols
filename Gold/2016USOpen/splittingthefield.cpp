#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

ll N, low, high, ans = pow(10,18);
vector<pair<ll, ll> > xcoord, ycoord;//sorted in terms of x and y coordinates
vector<pair<ll, ll> > yleft, yright(50000), xbottom, xtop(50000);
//initial area is (xcoord[N-1].first-xcoord[0].first)*(ycoord[N-1].second-ycoord[0].second)

bool xcomp(const pair<ll, ll>&a, const pair<ll, ll>&b){
    if(a.first != b.first){
        return a.first<b.first;
    } else{
        return a.second<b.second;
    }
}
bool ycomp(const pair<ll, ll>&a, const pair<ll, ll>&b){
    if(a.second != b.second){
        return a.second<b.second;
    } else{
        return a.first<b.first;
    }
}

int main(){

    ifstream fin("split.in");
    ofstream fout("split.out");

    fin >> N;
    for(int i=0; i<N; ++i){
        ll x, y; fin >> x >> y;
        xcoord.pb(mp(x,y));
        ycoord.pb(mp(x,y));
    }
    sort(xcoord.begin(), xcoord.end(), xcomp);
    sort(ycoord.begin(), ycoord.end(), ycomp);
    low = xcoord[0].second;
    high = xcoord[0].second;
    for(int i=0; i<N; ++i){
        low = min(low, xcoord[i].second);
        high = max(high, xcoord[i].second);
        yleft.pb(mp(low,high));
    }
    low = xcoord[N-1].second;
    high = xcoord[N-1].second;
    for(int i=N-1; i>=0; --i){
        low=min(low, xcoord[i].second);
        high=max(high, xcoord[i].second);
        yright[i]=mp(low, high);
    }
    low=ycoord[0].first;
    high=ycoord[0].first;
    for(int i=0; i<N; ++i){
        low=min(low, ycoord[i].first);
        high=max(high, ycoord[i].first);
        xbottom.pb(mp(low, high));
    }
    for(int i=N-1; i>=0; --i){
        low=min(low, ycoord[i].first);
        high = max(high, ycoord[i].first);
        xtop[i] = mp(low, high);
    }
    for(int i=0; i<N-1; ++i){
        ans = min(ans, ((xcoord[i].first-xcoord[0].first) * (yleft[i].second-yleft[i].first) + (xcoord[N-1].first-xcoord[i+1].first) * (yright[i+1].second-yright[i+1].first)));
    }
    for(int i=0; i<N-1; ++i){
        ans = min(ans, ((ycoord[i].second-ycoord[0].second) * (xbottom[i].second-xbottom[i].first) + (ycoord[N-1].second-ycoord[i+1].second) * (xtop[i+1].second-xtop[i+1].first)));
    }
    fout << (xcoord[N-1].first-xcoord[0].first)*(ycoord[N-1].second-ycoord[0].second)-ans;

    return 0;
}
