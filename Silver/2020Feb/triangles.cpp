#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
using namespace std;

int N, curpos, ans = 0;
vector<pair<int, int> > coord;
vector<vector<int> >xcoord(2*pow(10,4)+1), ycoord(2*pow(10,4)+1), xpsum(2*pow(10,4)+1), ypsum(2*pow(10,4)+1);

int xbsearch(pair<int, int> x){
    int low = 0, high = ycoord[x.s+pow(10,4)].size()-1, mid = (low+high)/2;
    while(low <= high){
        if(ycoord[x.s+pow(10,4)][mid] == x.f){
            return mid;
        } else if(ycoord[x.s+pow(10,4)][mid] < x.f){
            low = mid+1;
            mid = (low+high)/2;
        } else{
            high = mid-1;
            mid = (low+high)/2;
        }
    }
}

int ybsearch(pair<int, int> y){
    int low = 0, high = xcoord[y.f+pow(10,4)].size()-1, mid = (low+high)/2;
    while(low <= high){
        if(xcoord[y.f+pow(10,4)][mid] == y.s){
            return mid;
        } else if(xcoord[y.f+pow(10,4)][mid] < y.s){
            low = mid+1;
            mid = (low+high)/2;
        } else{
            high = mid-1;
            mid = (low+high)/2;
        }
    }
}

bool xcomp(const pair<int, int>&a, const pair<int, int>&b){
    if(a.first != b.first){
        return a.first<b.first;
    } else{
        return a.second<b.second;
    }
}

bool ycomp(const pair<int, int>&a, const pair<int, int>&b){
    if(a.second != b.second){
        return a.second<b.second;
    } else{
        return a.first<b.first;
    }
}

int main(){

    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    fin >> N;
    for(int i=0; i<N; ++i){
        ll x, y; fin >> x >> y;
        coord.pb(mp(x,y));
    }
    sort(coord.begin(), coord.end(), xcomp);
    curpos = coord[0].f;
    xpsum[coord[0].f+pow(10,4)].pb(0);
    for(int i=0; i<N; ++i){
        if(coord[i].f != curpos){
            curpos = coord[i].f;
            xpsum[coord[i].f+pow(10,4)].pb(0);
            xpsum[coord[i].f+pow(10,4)].pb(coord[i].s);
        } else{ 
            xpsum[coord[i].f+pow(10,4)].pb(xpsum[coord[i].f+pow(10,4)][xpsum[coord[i].f+pow(10,4)].size()-1]+coord[i].s);
        }
        xcoord[coord[i].f+pow(10,4)].pb(coord[i].s);
    }
    sort(coord.begin(), coord.end(), ycomp);
    curpos = coord[0].s;
    ypsum[coord[0].s+pow(10,4)].pb(0);
    for(int i=0; i<N; ++i){
        if(coord[i].s != curpos){
            curpos = coord[i].s;
            ypsum[coord[i].s+pow(10,4)].pb(0);
            ypsum[coord[i].s+pow(10,4)].pb(coord[i].f);
        } else{
            ypsum[coord[i].s+pow(10,4)].pb(ypsum[coord[i].s+pow(10,4)][ypsum[coord[i].s+pow(10,4)].size()-1]+coord[i].f);
        }
        ycoord[coord[i].s+pow(10,4)].pb(coord[i].f);
    }
    for(int i=0; i<N; ++i){
        ll width = (2*xbsearch(coord[i])-ycoord[coord[i].s+pow(10,4)].size()+1)*coord[i].f-ypsum[coord[i].s+pow(10,4)][xbsearch(coord[i])]-ypsum[coord[i].s+pow(10,4)][xbsearch(coord[i])+1]+ypsum[coord[i].s+pow(10,4)][ycoord[coord[i].s+pow(10,4)].size()];
        ll height = (2*ybsearch(coord[i])-xcoord[coord[i].f+pow(10,4)].size()+1)*coord[i].s-xpsum[coord[i].f+pow(10,4)][ybsearch(coord[i])]-xpsum[coord[i].f+pow(10,4)][ybsearch(coord[i])+1]+xpsum[coord[i].f+pow(10,4)][xcoord[coord[i].f+pow(10,4)].size()];
        ans += width*height;
        ans %= 1000000007;
    }
    fout << ans;

    return 0;
}
