#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();


/*
問題
N 個の正の整数 ao, a1, …, aN-1 が与えられます。これらに対して「N 個の整数がすべて偶数ならば 2 で割った値に置き換える」という」
操作を、操作が行えなくなるまで繰り返します。何回の操作を行うことになるかを求めるアルゴリズムを設計してください
テストケース
3
2 4 8
5
2 2 2 2 2
6
4 8 4 8 4 8
*/



//xが2の何乗でわることができるか
int search(int x){
    int ans = 0;
    while(x%2 ==  0){
        x /= 2;
        ans++;
    }
    return ans;
}

int main()
{
    /*入力*/
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    /* n個の整数が全て偶数なら2で割った値に置き換える操作を何回行えるか */
    /* tmp_min = 割ることのできる最小回数 */
    if(a.size() > 0){
        int tmp_min = search(a[0]);
        rep(i, n){
            tmp_min = min(tmp_min, search(a[i]));
            // cout << tmp_min << endl;
        }
        cout << tmp_min << endl;
    }
    else cout << 0 << endl;

    return 0;
}
