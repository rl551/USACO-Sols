#include "bits/stdc++.h"
const int MAXN=1e3;
using namespace std;

int N, temparea, tempperim, area=-1, perim;
char icecream[MAXN][MAXN];
bool visited[MAXN][MAXN];

void floodfill(int i, int j){
    if(icecream[i][j] == '.' || (i<0 || i>=N || j<0 || j>=N)){
        tempperim++;
        return;
    }
    if(visited[i][j]) return;
    visited[i][j] = true;
    temparea++;
    floodfill(i-1, j);
    floodfill(i+1, j);
    floodfill(i, j-1);
    floodfill(i, j+1);
}

int main(){

    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");
    fin >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            fin >> icecream[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(!visited[i][j] && icecream[i][j] == '#'){
                temparea=0, tempperim=0;
                floodfill(i, j);
                if(temparea>area || (temparea == area && tempperim<perim)){
                    area=temparea;
                    perim=tempperim;
                }
            }
        }
    }
    fout << area << " " << perim;

    return 0;
}
