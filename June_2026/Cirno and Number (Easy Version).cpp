//testing code 
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull toNum(const string& s) {
    ull v = 0;
    for (char c : s) v = v * 10 + (c - '0');
    return v;
}

// returns floor-string and ceil-string (same length as a), "" if none exists
pair<string,string> getFloorCeil(const string& a, int lo, int hi) {
    int L = a.size();
    string floorS = "", ceilS = "";

    // ---- floor: largest b <= a ----
    for (int k = L; k >= 0; k--) {
        if (k == L) {
            bool ok = true;
            for (char c : a) { 
                int d = c - '0'; 
                if (d != lo && d != hi) { 
                    ok = false; break; } 
                }
            if (ok) { 
                floorS = a; 
                break; 
            }
        } else {
            bool prefOk = true;
            for (int i = 0; i < k; i++) {
                int d = a[i] - '0';
                if (d != lo && d != hi) { 
                    prefOk = false; break; 
                }
            }
            if (!prefOk) continue;
            int ad = a[k] - '0';
            int best = -1;
            // try hi first (larger), then lo
            if (hi < ad && !(k == 0 && L > 1 && hi == 0)) best = hi;
            else if (lo < ad && !(k == 0 && L > 1 && lo == 0)) best = lo;
            if (best != -1) {
                string s = a.substr(0, k) + char('0' + best) + string(L - 1 - k, char('0' + hi));
                floorS = s;
                break;
            }
        }
    }

    // ---- ceil: smallest b >= a ----
    for (int k = L; k >= 0; k--) {
        if (k == L) {
            bool ok = true;
            for (char c : a) { int d = c - '0'; if (d != lo && d != hi) { ok = false; break; } }
            if (ok) { ceilS = a; break; }
        } else {
            bool prefOk = true;
            for (int i = 0; i < k; i++) {
                int d = a[i] - '0';
                if (d != lo && d != hi) { prefOk = false; break; }
            }
            if (!prefOk) continue;
            int ad = a[k] - '0';
            int best = -1;
            // try lo first (smaller), then hi  -- no leading-zero issue here since digit > ad >= 0
            if (lo > ad) best = lo;
            else if (hi > ad) best = hi;
            if (best != -1) {
                string s = a.substr(0, k) + char('0' + best) + string(L - 1 - k, char('0' + lo));
                ceilS = s;
                break;
            }
        }
    }

    return {floorS, ceilS};
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char abuf[25];
        int n;
        scanf("%s %d", abuf, &n);
        string a(abuf);
        int lo, hi;
        scanf("%d %d", &lo, &hi); // n == 2, d1 < d2

        ull aVal = toNum(a);
        int L = a.size();

        vector<ull> candidates;

        auto floorCeil = getFloorCeil(a, lo, hi);
        if (!floorCeil.first.empty())  candidates.push_back(toNum(floorCeil.first));
        if (!floorCeil.second.empty()) candidates.push_back(toNum(floorCeil.second));

        // length L-1 : max number = hi repeated (L-1) times
        if (L >= 2) {
            string s(L - 1, char('0' + hi));
            candidates.push_back(toNum(s));
        }

        // length L+1 : min number with no leading zero
        {
            string s;
            if (lo > 0) {
                s = string(L + 1, char('0' + lo));
            } else {
                s = string(1, char('0' + hi)) + string(L, char('0' + lo));
            }
            candidates.push_back(toNum(s));
        }

        ull best = ULLONG_MAX;
        for (ull c : candidates) {
            ull diff = (aVal > c) ? (aVal - c) : (c - aVal);
            best = min(best, diff);
        }

        printf("%llu\n", best);
    }
    return 0;
}