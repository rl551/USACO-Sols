#include "bits/stdc++.h"
#define ll long long
using namespace std;

string recipe;
ll numb, nums, numc, priceb, prices, pricec, b=0, s=0, c=0, money;

bool solve(ll N){
    ll x = 0;
    return(max(b*N-numb,x)*priceb+max(s*N-nums,x)*prices+max(c*N-numc,x)*pricec <= money);
}

int main(){

    cin >> recipe >> numb >> nums >> numc >> priceb >> prices >> pricec >> money;
    for(int i=0; i<recipe.size(); ++i){
        if(recipe[i] == 'B'){
            b++;
        } else if(recipe[i] == 'S'){
            s++;
        } else{
            c++;
        }
    }
    ll low = 0, high = pow(10,15), mid = (low+high)/2;
    while(low <= high){
        if(solve(mid) && !solve(mid+1)){
            cout << mid;
            return 0;
        } else if(!solve(mid)){
            high = mid-1;
            mid = (low+high)/2;
        } else{
            low = mid+1;
            mid = (low+high)/2;
        }
    }

}
