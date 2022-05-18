#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int best_min = 1000010, second_min = 1000000;
    rep(i,n) {
        cin>>a[i];
        if(best_min > a[i]){
            second_min  = best_min;
            best_min = a[i];
        }else if(second_min > a[i]){
            second_min = a[i];
        }
    }
    cout<<second_min<<endl;
    
    return 0;
}
