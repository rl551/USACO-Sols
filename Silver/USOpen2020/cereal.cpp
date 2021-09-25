#include "bits/stdc++.h"
const int MAX_SIZE = 1e5+11;
using namespace std;

int N, M, suffixSum[MAX_SIZE], cow[MAX_SIZE];//cow[i] is what cow is currently at cereal i
pair<int, int> cereal[MAX_SIZE];
bool available[MAX_SIZE];

int main(){

    ifstream fin("cereal.in");
    ofstream fout("cereal.out");
    fill(available, available+MAX_SIZE, true);
    fill(cow,cow+MAX_SIZE, 1e9);    
    fin >> N >> M;
    for(int i=0; i<N; ++i) fin >> cereal[i].first >> cereal[i].second;
    for(int i=N-1; i>=0; --i){
        if(available[cereal[i].first]){
            suffixSum[i] = suffixSum[i+1]+1;
            available[cereal[i].first] = false;
            cow[cereal[i].first] = i;
        } else{
            int curCow = i, curCereal = cereal[i].first;
            while(true){
                if(available[curCereal]){
                    suffixSum[i] = suffixSum[i+1] + 1;
                    available[curCereal] = false;
                    cow[curCereal] = curCow;
                    break;
                } else{
                    int tempCow = cow[curCereal];
                    if(curCereal == cereal[tempCow].second){
                        cow[curCereal] = curCow;
                        suffixSum[i] = suffixSum[i+1];
                        break;
                    } else{
                        cow[curCereal] = curCow;
                        if(cow[cereal[tempCow].second]<tempCow){
                            suffixSum[i] = suffixSum[i+1];
                            break;
                        } else{
                            curCow = tempCow;
                            curCereal = cereal[curCow].second;
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<N; ++i) fout << suffixSum[i] << endl;

    return 0;
}
