#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> red(N), blue(N);
    rep(i,N) cin >> red[i].first >> red[i].second;
    rep(i,N) cin >> blue[i].first >> blue[i].second;

    sort(blue.begin(), blue.end());
    vector<bool> used_red(N, false);

    int ans = 0;
    rep(i,N){
        int max_y = -1, tmp = -1;

        rep(j,N){
            if (used_red[j]) continue;
            if (red[j].first >= blue[i].first || red[j].second >= blue[i].second) continue;
            if (max_y < red[j].second) {
                max_y = red[j].second;
                tmp = j;
            }
        }

        if (tmp == -1) continue;
        ans++;
        used_red[tmp] = true;
    }

    cout << ans << endl;

    return 0;
}
