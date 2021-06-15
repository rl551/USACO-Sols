//https://cses.fi/problemset/task/1620/
#include "bits/stdc++.h"
#define ll long long
#define vll vector<ll>
#define pb push_back
using namespace std;

ll N, T;
vll t;

bool check(ll mid){
    ll counter = 0;
    for(int i=0; i<N; ++i){
        counter += mid/t[i];
        if(counter >= T){
            return true;
        }
    }
    return(counter >= T);
}

int main(){

    cin >> N >> T;
    for(int i=0; i<N; ++i){
        ll x; cin >> x;
        t.pb(x);
    }
    ll low = 0, high = pow(10,18), mid = (low+high)/2;
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
