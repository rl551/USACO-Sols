//https://codeforces.com/problemset/problem/1223/C
#include "bits/stdc++.h"
#define ll long long
#define pb push_back
using namespace std;

ll Q, N, a, b, x, y, k;
vector<ll> price;

ll lcm(ll c, ll d){
    for(int i=1; i<=d; ++i){
        if(c*i == d*(c*i/d)){
            return(c*i);
        }
    }
}

bool check(ll mid){
    ll h, j, l, counter = 0;
    h = mid/a-mid/(lcm(a,b));
    j = mid/b-mid/(lcm(a,b));
    l = mid/(lcm(a,b));
    for(int i=N-1; i>=N-l; --i){
        counter += price[i]*(x+y)/100;
    }
    if(x >= y){
        for(int i=N-l-1; i>=N-l-h; --i){
            counter += price[i] * x/100;
        }
        for(int i=N-l-h-1; i>= N-l-h-j; --i){
            counter += price[i] * y/100;
        }
    } else{
        for(int i=N-l-1; i>=N-l-j; --i){
            counter += price[i] * y/100;
        }
        for(int i=N-l-j-1; i>= N-l-j-h; --i){
            counter += price[i] * x/100;
        }
    }
    return(counter >= k);
}

ll solve(ll N){
    ll low = 1, high = N, mid = (low+high)/2;
    while(low <= high){
        if(check(mid) && !check(mid-1)){
            return(mid);
        } else if(!check(mid)){
            low = mid+1;
            mid = (low+high)/2;
        } else{
            high = mid-1;
            mid = (low+high)/2;
        }
    }
    return -1;
}

int main(){

    cin >> Q;
    for(int i=0; i<Q; ++i){
        cin >> N;
        price.clear();
        for(int i=0; i<N; ++i){
            ll p; cin >> p;
            price.pb(p);
        }
        sort(price.begin(), price.end());
        cin >> x >> a >> y >> b >> k;
        cout << solve(N) << endl;
    }

    return 0;
}
