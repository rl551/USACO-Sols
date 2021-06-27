//wrong on tc7, 9, 14, 17
#include "bits/stdc++.h"
#define ll long long
#define pb push_back
using namespace std;

ll N, K, L;
vector<ll> citations;

bool check(ll H){
    ll counter = N-(lower_bound(citations.begin(), citations.end(), H)-citations.begin()), articles = 0, x=0;
    for(ll i=(lower_bound(citations.begin(), citations.end(), H)-citations.begin())-1; i>=max(x,(lower_bound(citations.begin(), citations.end(), H)-citations.begin())-K); --i){
        if(H-citations[i]>K) break;
        if(articles+(H-citations[i])>K*L) break;
        articles += (H-citations[i]);
        counter++;
    }
    return(counter >= H);
}

int main(){

    cin >> N >> K >> L;
    for(int i=0; i<N; ++i){
        ll c; cin >> c;
        citations.pb(c);
    }
    sort(citations.begin(), citations.end());
    ll low = 1, high = pow(10,10), mid = (low+high)/2;
    while(low <= high){
        if(check(mid) && !check(mid+1)){
            cout << mid;
            return 0;
        } else if(!check(mid)){
            high = mid-1;
            mid = (low+high)/2;
        } else{
            low = mid+1;
            mid = (low+high)/2;
        }
    }
}
