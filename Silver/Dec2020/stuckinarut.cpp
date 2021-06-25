//my implementation is extremely messy, so you can definitely have cleaner code than me
#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

int N;
vector<pair<int, pair<int, int> > > ans;
vector<pair<bool, pair<int, int> > > input, east, north;

bool bx(const pair<bool, pair<int, int> >&a, const pair<bool, pair<int, int> >&b){
    if(a.s.f != b.s.f){
        return(a.s.f < b.s.f);
    } else{
        return(a.s.s < b.s.s);
    }
}
bool by(const pair<bool, pair<int, int> >&a, const pair<bool, pair<int, int> >&b){
    if(a.s.s != b.s.s){
        return a.s.s<b.s.s;
    } else{
        return a.s.f<b.s.f;
    }
}
bool ax(const pair<int, pair<int, int> >&a, const pair<int, pair<int, int> >&b){
    if(a.s.f != b.s.f){
        return(a.s.f < b.s.f);
    } else{
        return(a.s.s < b.s.s);
    }
}
bool intersect(const int &eindex, const int &nindex){
    return(east[eindex].s.f <= north[nindex].s.f && east[eindex].s.s >= north[nindex].s.s);
}
int bsearch(const pair<bool, pair<int, int> >&a){//bsearch for a in ans
    int low = 0, high = N-1, mid = (low+high)/2;
    while(low <= high){
        if(ans[mid].s.f == a.s.f && ans[mid].s.s == a.s.s){
            return mid;
        } else if(ans[mid].s.f < a.s.f){
            low = mid+1;
            mid = (low+high)/2;
        } else{
            high = mid-1;
            mid = (low+high)/2;
        }
    }
}

int main(){

    cin >> N;
    for(int i=0; i<N; ++i){
        char c; int x, y;
        cin >> c >> x >> y;
        ans.pb(mp(0,mp(x,y)));
        input.pb(mp(false,mp(x,y)));
        if(c == 'E'){
            east.pb(mp(false, mp(x,y)));
        } else{
            north.pb(mp(false, mp(x,y)));
        }
    }
    sort(east.begin(), east.end(), by);
    sort(north.begin(), north.end(), bx);
    sort(ans.begin(), ans.end(), ax);
    for(int i=0; i<north.size(); ++i){
        for(int j=0; j<east.size(); ++j){
            if(intersect(j, i) && (!east[j].f && !north[i].f)){
                if(north[i].s.f-east[j].s.f < east[j].s.s-north[i].s.s){//east arrives first
                    north[i].f = true;
                    ans[bsearch(east[j])].f += (1+ans[bsearch(north[i])].f);
                    break;
                } else if(north[i].s.f-east[j].s.f > east[j].s.s-north[i].s.s){//north arrives first
                    east[j].f = true;
                    ans[bsearch(north[i])].f += (1+ans[bsearch(east[j])].f);
                }
            }
        }
    }
    for(int i=0; i<N; ++i){
        cout << ans[bsearch(input[i])].f << endl;
    }

    return 0;
}
