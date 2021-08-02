#include "bits/stdc++.h"
const int MAXN=1e5+7;
using namespace std;

int N, minscore=1e8, scores[MAXN], minscores[MAXN], psum[MAXN];
double maxScore=-1;
vector<int> ans;

int main(){

    ifstream fin("homework.in");
    ofstream fout("homework.out");
    fin >> N;
    for(int i=1; i<=N; ++i) fin >> scores[i];
    for(int i=1; i<=N; ++i) psum[i]=psum[i-1]+scores[i];
    for(int i=N; i>=1; --i){
        if(scores[i]<minscore) minscore=scores[i];
        minscores[i]=minscore;
    }
    for(int k=1; k<=N-2; ++k){
        double score=(psum[N]-psum[k])-minscores[k+1];
        score /= (N-k-1);
        if(score>maxScore) maxScore=score;
    }
    for(int k=1; k<=N-2; ++k){
        double score=(psum[N]-psum[k])-minscores[k+1];
        score /= (N-k-1);
        if(score == maxScore) ans.push_back(k);
    }
    for(int i=0; i<ans.size()-1; ++i) fout << ans[i] << " ";
    fout << ans[ans.size()-1];

    return 0;
}
