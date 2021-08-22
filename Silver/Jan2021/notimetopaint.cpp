#include "bits/stdc++.h"
using namespace std;

const int MAXN=1e5+11;
const string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int N, Q, psum[MAXN], ssum[MAXN];
string s;
bool can_place[26];

int main(){

    cin >> N >> Q >> s;
    psum[0]=0;
    for(int i=1; i<=N; ++i){
        int index;
        for(int j=0; j<26; ++j) if(alphabet[j] == s[i-1]) index=j;
        if(can_place[index]){
            psum[i]=psum[i-1];
            for(int j=index+1; j<26; ++j) can_place[j]=false;
        } else{
            can_place[index]=true;
            psum[i]=psum[i-1]+1;
            for(int j=index+1; j<26; ++j) can_place[j]=false;
        }
    }
    ssum[N+1]=0; fill(&can_place[0], &can_place[0]+26, false);
    for(int i=N; i>=1; --i){
        int index;
        for(int j=0; j<26; ++j) if(alphabet[j] == s[i-1]) index=j;
        if(can_place[index]){
            ssum[i]=ssum[i+1];
            for(int j=index+1; j<26; ++j) can_place[j]=false;
        } else{
            can_place[index]=true;
            ssum[i]=ssum[i+1]+1;
            for(int j=index+1; j<26; ++j) can_place[j]=false;
        }
    }
    for(int i=0; i<Q; ++i){
        int a, b; cin >> a >> b;
        cout << psum[a-1]+ssum[b+1] << endl;
    }

    return 0;
}
