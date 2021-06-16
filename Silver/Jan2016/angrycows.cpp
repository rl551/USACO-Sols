//not correct on tc4
#include "bits/stdc++.h"
#define pb push_back
using namespace std;

int N, K;
vector<int> cows;

bool check(int R){
    int curpos = 0;
    for(int i=0; i<K; ++i){
        int l=curpos, h=N-1, m = (l+h)/2;
        while(l <= h){
            if(cows[m] <= cows[curpos]+2*R && (m == N-1 || cows[m+1]>cows[curpos]+2*R)){
                curpos = m+1;
                break;
            } else if(cows[m] > cows[curpos]+2*R){
                h = m-1;
                m = (l+h)/2;
            } else{
                l = m+1;
                m = (l+h)/2;
            }
        }
    }
    return(curpos >= N-1);
}

int main(){

    ifstream fin("angry.in");
    ofstream fout("angry.out");

    fin >> N >> K;
    for(int i=0; i<N; ++i){
        int x; fin >> x;
        cows.pb(x);
    }
    sort(cows.begin(), cows.end());
    int low = 0, high = pow(10,9), mid = (low+high)/2;
    while(low <= high){
        if(check(mid) && (mid == 0 || !check(mid-1))){
            fout << mid;
            return 0;
        } else if(!check(mid)){
            low = mid+1;
            mid = (low+high)/2;
        } else{
            high = mid-1;
            mid = (low+high)/2;
        }
    }

}
