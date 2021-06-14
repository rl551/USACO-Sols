#include "bits/stdc++.h"
#define ll long long
#define pb push_back
using namespace std;

ll xi, yi, xf, yf;
int N;
string w;

bool check(ll T){
    int index = 0; 
    ll xpos=xi, ypos=yi;
    if(T < N){
        for(int i=1; i<=T; ++i){
            if(w[index] == 'U'){
                ypos++;
            } else if(w[index] == 'D'){
                ypos--;
            } else if(w[index] == 'L'){
                xpos--;
            } else{
                xpos++;
            }
            index++;
        }
        return (abs(xf-xpos)+abs(yf-ypos) <= T);
    } else{
        for(int i=1; i<=N; ++i){
            if(w[index] == 'U'){
                ypos++;
            } else if(w[index] == 'D'){
                ypos--;
            } else if(w[index] == 'L'){
                xpos--;
            } else{
                xpos++;
            }
            index++;
            }
        xpos += ((T-T%N-1)/N)*(xpos-xi);
        ypos += ((T-T%N-1)/N)*(ypos-yi);
        index = 0;
        for(int i=1; i<=T%N; ++i){
            if(w[index] == 'U'){
                ypos++;
            } else if(w[index] == 'D'){
                ypos--;
            } else if(w[index] == 'L'){
                xpos--;
            } else{
                xpos++;
            }
            index++;
        }
        return (abs(xf-xpos)+abs(yf-ypos) <= T);
    }
}

int main(){

    cin >> xi >> yi >> xf >> yf >> N >> w;
    ll low = 1, high = pow(10,15), mid = (low+high)/2;
    while(low <= high){
        if(check(mid) && (mid == 0 || !check(mid-1))){
            cout << mid;
            return 0;
        } else if(!check(mid)){
            low = mid+1;
            mid = (low+high)/2;
        } else{
            high = mid-1;
            mid = (low+high)/2;
        }
    }

    cout << -1;

}
