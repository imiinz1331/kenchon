#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

vector<int> a, b, c;

//targetがa[x]より大きい
bool P(int x, int target){
    if(target > a[x]){
        return true;
    }
    return false;
}

//targetがc[x]よりt小さい
bool Q(int x, int target){
    cout << c[x] << endl;
    if(target < c[x]){
        return true;
    }
    return false;
}

//P(x) = true となる最小の整数xを返す
int binary_search_a(int target){
    int left, right; //P(left) = false, P(right) = trueとなるもの
    while(right - left > 1){
        int mid = left + (right - left)/2;
        if(P(mid, target)) right = mid;
        else left = mid;
    }
    return right;
}

//Q(x) = true となる最小の整数xを返す
int binary_search_c(int target){
    int left, right; //P(left) = false, P(right) = trueとなるもの
    while(right - left > 1){
        int mid = left + (right - left)/2;
        if(Q(mid, target)) right = mid;
        else left = mid;
    }
    return right;
}

int main()
{
    int n;
    cin >> n;

    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    rep(i, n){
        int x;
        cin >> x;
        b.push_back(x);
    }
    rep(i, n){
        int x;
        cin >> x;
        c.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    // vector<int> b_count(n, 0);

    // cout << endl;
    // rep(i, n){
    //     //b[i]より大きいc[i]の個数を調べる
    //     b_count[i] = n - binary_search_c(b[i]) - 1;
    //     cout << b[i] << " " << binary_search_c(b[i]) + 1 << endl;
    // }

    // cout << endl;
    // rep(i, n){
    //     //b[i]より小さいa[i]の個数を調べる
    //     b_count[i] *= binary_search_a(b[i]) + 1;
    //     cout << b[i] << " " << binary_search_a(b[i]) << endl;
    // }

    // int ans = 0;
    // rep(i, n){
    //     ans += b_count[i];
    // }

    // cout << ans << endl;

        // b[j] を固定して考える
    long long res = 0;
    for (int j = 0; j < n; ++j) {
        long long Aj = lower_bound(a.begin(), a.end(), b[j]) - a.begin(); //イテレータ
        long long Cj = n - (upper_bound(c.begin(), c.end(), b[j]) - c.begin());
        res += Aj * Cj;
    }
    cout << res << endl;

    
    return 0;
}
