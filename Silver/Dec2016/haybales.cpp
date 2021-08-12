#include "bits/stdc++.h"
using namespace std;

int N, Q;
vector<int> haybales;

int main(){

    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    fin >> N >> Q;
    for(int i=0; i<N; ++i){
        int h; fin >> h;
        haybales.push_back(h);
    }
    sort(haybales.begin(), haybales.end());
    for(int i=0; i<Q; ++i){
        int a,b; fin >> a >> b;
        int l=lower_bound(haybales.begin(), haybales.end(), a)-haybales.begin();
        int r=upper_bound(haybales.begin(), haybales.end(), b)-haybales.begin();
        //a <= a_1, a_2, ..., a_k <= b < b_1, b_2, ...
        //*l=a_1
        //*r=b_1
        fout << r-l << endl;
    }

    return 0;
}
