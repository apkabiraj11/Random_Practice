#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ln '\n'

vector<pair<int,int>> moves;

void hanoi(int n, int from, int to, int aux){
    if(n == 0) return;

    hanoi(n-1, from, aux, to);        // step 1
    moves.push_back({from, to});      // step 2
    hanoi(n-1, aux, to, from);        // step 3
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    hanoi(n, 1, 3, 2);

    cout << moves.size() << ln;
    for(auto &p : moves){
        cout << p.first << " " << p.second << ln;
    }

    return 0;
}