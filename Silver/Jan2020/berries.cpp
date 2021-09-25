#include "bits/stdc++.h"
const int MAX_BERRIES=1e3;
using namespace std;

int N, K, ans, tempans, counter;
vector<int> trees, tempTrees;

int main(){

    ifstream fin("berries.in");
    ofstream fout("berries.out");
    fin >> N >> K;
    for(int i=0; i<N; ++i){
        int b_i; fin >> b_i;
        trees.push_back(b_i);
    }
    sort(trees.begin(), trees.end());
    for(int i=1; i<=MAX_BERRIES; ++i){
        tempTrees.clear();
        for(int j=0; j<N; ++j) tempTrees.push_back(trees[j]);
        tempans=0, counter = 0;
        for(int j=N-1; j>=0; --j){
            if(tempTrees[j]<i) break;
            else{
                if(tempTrees[j]/i+counter >= K/2){
                    tempTrees[j] -= i*(K/2-counter);
                    counter = K/2;
                    break;
                } else{
                    counter += tempTrees[j]/i;
                    tempTrees[j] %= i;
                }
            }
        }
        if(counter<K/2) break;
        sort(tempTrees.begin(), tempTrees.end());
        counter = 0;
        for(int j=N-1; j>=0; --j){
            if(tempTrees[j]<i) break;
            if(tempTrees[j]/i+counter >= K/2){
                tempans += i*(K/2-counter);
                tempTrees[j] -= i*(K/2-counter);
                counter = K/2;
                break;
            } else{
                counter += tempTrees[j]/i;
                tempans += (tempTrees[j]/i) * i;
                tempTrees[j] %= i;
            }
        }
        if(counter<K/2){
            sort(tempTrees.begin(), tempTrees.end());
            for(int j=N-1; j>=0; --j){
                if(counter == K/2) break;
                tempans += tempTrees[j];
                counter++;
            }
        }
        ans = max(tempans,ans);
    }
    fout << ans;

    return 0;
}
