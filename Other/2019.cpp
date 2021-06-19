//https://atcoder.jp/contests/abc164/tasks/abc164_d
#include "bits/stdc++.h"
#define pb push_back
#define ub upper_bound
#define lb lower_bound
using namespace std;

string S;
int curnum = 1, ans = 0;
vector<int> ten, digits, psum;

int main(){

    ten.pb(1);
    for(int i=1; i<=200000; ++i){
        curnum *= 10;
        curnum %= 2019;
        ten.pb(curnum);
    }
    cin >> S;
    for(int i=0; i<S.length(); ++i){
        curnum = 1;
        curnum *= (ten[S.length()-i-1] * (S[i]-'0'));
        curnum %= 2019;
        digits.pb(curnum);
    }
    curnum = 0;
    psum.pb(curnum);
    for(int i=0; i<digits.size(); ++i){
        curnum += digits[i];
        curnum %= 2019;
        psum.pb(curnum);
    }
    sort(psum.begin(), psum.end());
    for(int i=0; i<=2018; ++i){
        ans += (ub(psum.begin(), psum.end(), i) - lb(psum.begin(), psum.end(), i)) * (ub(psum.begin(), psum.end(), i) - lb(psum.begin(), psum.end(), i)-1) / 2;
    }
    cout << ans;

    return 0;
}
