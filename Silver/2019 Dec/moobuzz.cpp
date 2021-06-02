#include "bits/stdc++.h"
#define ll long long
#define str string
#define db double
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pi pair<int, int>
#define ps pair<str, str>
#define pdb pair<db, db>
#define pll pair<ll, ll>
#define vi vector<int>
#define vs vector<str>
#define vdb vector<db>
#define vll vector<ll>
#define vpi vector<pi>
#define vps vector<ps>
#define vpdb vector<pdb>
#define vpll vector<pll>
using namespace std;

int N;

int main(){

    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");

    fin >> N;
    if(N%8 == 1){fout << 15*(N/8)+1;}
    else if(N%8 == 2){fout << 15*(N/8)+2;}
    else if(N%8 == 3){fout << 15*(N/8)+4;}
    else if(N%8 == 4){fout << 15*(N/8)+7;}
    else if(N%8 == 5){fout << 15*(N/8)+8;}
    else if(N%8 == 6){fout << 15*(N/8)+11;}
    else if(N%8 == 7){fout << 15*(N/8)+13;}
    else{fout << 15*(N/8-1)+14;}


    return 0;
}
