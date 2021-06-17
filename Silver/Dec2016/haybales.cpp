#include "bits/stdc++.h"
#define pb push_back
using namespace std;

int N, Q, A, B;
vector<int> haybales;

int main(){

    cin >> N >> Q;
    for(int i=0; i<N; ++i){
        int h; cin >> h;
        haybales.pb(h);
    }
    sort(haybales.begin(), haybales.end());
    for(int i=0; i<Q; ++i){
        cin >> A >> B;        
        cout << upper_bound(haybales.begin(), haybales.end(), B)-lower_bound(haybales.begin(), haybales.end(), A) << endl;
    }
    
    return 0;
}
