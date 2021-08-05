#include "bits/stdc++.h"
const int MAX_SIZE=1e3+11;
using namespace std;

int N, K, counter, paint, change[MAX_SIZE][MAX_SIZE], barn[MAX_SIZE][MAX_SIZE];

int main(){

    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    fin >> N >> K;
    for(int i=0; i<N; ++i){
        int x1, y1, x2, y2; fin >> x1 >> y1 >> x2 >> y2;
        for(int y=y1; y<y2; ++y){
            change[x1][y]++;
            change[x2][y]--;
        }
    }
    for(int y=0; y<MAX_SIZE; ++y){
        for(int x=0; x<MAX_SIZE; ++x){
            paint += change[x][y];
            barn[x][y]=paint;
            if(barn[x][y] == K) counter++;
        }
    }
    fout << counter;

    return 0;
}
