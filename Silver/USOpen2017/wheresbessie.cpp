#include "bits/stdc++.h"
#define MAXN 20
using namespace std;

int N, counter0, counter1;
char farm[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<char> letters;
set<char> templetters;
vector<pair<pair<int, int>, pair<int, int> > > ans;
set<int> inside;

void ff(int a, int b, int c, int d, int i, int j, char l){//xmin=a, xmax=b, ymin=c, ymin=d
    if(visited[i][j] || (i<a || i>b || j<c || j>d) || farm[i][j] != l) return;
    visited[i][j] = true;
    ff(a, b, c, d, i-1, j, l);
    ff(a, b, c, d, i+1, j, l);
    ff(a, b, c, d, i, j-1, l);
    ff(a, b, c, d, i, j+1, l);
}

int main(){
    ifstream fin("where.in");
    ofstream fout("where.out");
    fin >> N;
    for(int i=0; i<N; ++i){
        string s; fin >> s;
        for(int j=0; j<N; ++j) farm[i][j]=s[j];
    }
    for(int i=0; i<N; ++i){
        for(int j=i; j<N; ++j){
            for(int k=0; k<N; ++k){
                for(int l=k; l<N; ++l){
                    //xmin=i, xmax=j, ymin=k, ymax=l
                    templetters.clear();
                    //step 1: check if there are two letters
                    for(int m=i; m<=j; ++m){
                        for(int n=k; n<=l; ++n) templetters.insert(farm[m][n]);
                    }
                    if(templetters.size() == 2){
                        //step 2: floodfill to check the "contiguous regions condition"
                        counter0=0, counter1=0;
                        letters.clear();
                        for(auto &u: templetters) letters.push_back(u);
                        fill(&visited[0][0], &visited[0][0]+400, false);
                        for(int m=i; m<=j; ++m){
                            for(int n=k; n<=l; ++n){
                                if(!visited[m][n] && farm[m][n] == letters[0]){
                                    ff(i, j, k, l, m, n, letters[0]);
                                    counter0++;
                                }
                            }
                        }
                        fill(&visited[0][0], &visited[0][0]+400, false);
                        for(int m=i; m<=j; ++m){
                            for(int n=k; n<=l; ++n){
                                if(!visited[m][n] && farm[m][n] == letters[1]){
                                    ff(i, j, k, l, m, n, letters[1]);
                                    counter1++;
                                }
                            }
                        }
                        if((counter0 == 1 && counter1 >= 2) || (counter1 == 1 && counter0 >= 2)) ans.push_back(make_pair(make_pair(i,j), make_pair(k,l)));
                    }
                }
            }
        }
    }
    for(int i=0; i<ans.size(); ++i){
        for(int j=0; j<ans.size(); ++j){//j inside i
            if(
                ans[i].first.first <= ans[j].first.first &&
                ans[j].first.second <= ans[i].first.second &&
                ans[i].second.first <= ans[j].second.first &&
                ans[j].second.second <= ans[i].second.second &&
                j != i
            ) inside.insert(j);
        }
    }
    fout << static_cast<int>(ans.size()-inside.size());
   
    return 0;
}
