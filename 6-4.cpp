#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    //sort(a.begin(), a.end());
    //→aは既に昇順だから今回は不要

    // 「すべての間隔を x 以上にして M 個の小屋を選べるか？」という判定問題を解く
    // Yes であるような最大の x を求める
    long long left = 0, right = __LONG_LONG_MAX__;
    
    while (right - left > 1) {        
        long long x = (left + right) / 2;
        int cnt = 1; // 何個の小屋が取れたか (最初の小屋は選ぶ)
        int prev = 0; // 前回の小屋の index
        for (int i = 0; i < N; ++i) {
            // x 以上の間隔が空いたら採用する
            if (a[i] - a[prev] >= x) {
                ++cnt;
                prev = i;
                //x以上出なければ取らない→prevも更新しない
                //次も今見ていた小屋prevとの距離を調べる(差がx以上になるまで小屋を取らない)
            }
        }
        // 判定問題が Yes か No か
        if (cnt >= M) left = x;
        //Mより多く選んでも最小の差がx以上
        //→もっとxを上げられる
        //→leftをxに(大きく)
        else right = x;
        //M個選べない
        //→xを下げないといけない
        //→rightをxに(小さく)
    }

    //最終的に条件をみたすとき、left=xである
    cout << left << endl;
}
