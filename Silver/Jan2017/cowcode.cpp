#include "bits/stdc++.h"
using namespace std;

string s;
int counter;
long long N, curnum;

int main(){

    ifstream fin("cowcode.in");
    ofstream fout("cowcode.out");
    fin >> s >> N;
    curnum=static_cast<int>(s.size());
    while(curnum<N){
        curnum *= 2;
        counter++;
    }
    for(int i=counter; i>=0; --i){
        if(N<=static_cast<int>(s.size())){
            fout << s[N-1];
            return 0;
        }
        if(N == curnum/2+1) N=curnum/2;
        if(N>curnum/2+1) N -= curnum/2-1;
        curnum /= 2;
    }
    fout << s[N-1];
    
    return 0;
}
