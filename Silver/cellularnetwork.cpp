//https://codeforces.com/contest/702/problem/C
#include "bits/stdc++.h"
#define ll long long
#define vll vector<ll>
using namespace std;

ll N, M;
vll cities;
vll towers;

bool check(ll R){
    bool ans = true;
    bool possible = false;
    for(int i=0; i<N; ++i){
        possible = false;
        ll l=0, h=M-1, m=(l+h)/2;
        while(l <= h){
            if(towers[m]-cities[i] < -R){
                l=m+1;
                m=(l+h)/2;
            } else if(towers[m]-cities[i]>R){
                h=m-1;
                m=(l+h)/2;
            } else{
                possible = true;
                break;
            }
        }
        if(!possible){
            ans = false;
            break;
        }
    }
    return ans;
}

int main(){

    cin >> N >> M;
    for(int i=0; i<N; ++i){
        int c; cin >> c;
        cities.pb(c);
    }
    for(int i=0; i<M; ++i){
        int t; cin >> t;
        towers.pb(t);
    }
    ll low = 0, high = 2*pow(10,9), mid = (low+high)/2;
    while(low <= high){
        if(check(mid) && (mid == 0 || !check(mid-1))){
            cout << mid;
            return 0;
        } else if(!check(mid)){
            low = mid+1;
            mid = (low+high)/2;
        } else{
            high = mid-1;
            mid = (low+high)/2;
        }
    }

}
