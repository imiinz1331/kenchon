#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

//メモ
vector<int> memo(MAX, -1);

//トリボナッチ数列の第n項を求める
int Tribonacci(int n){
    if(n <= 0) return 0;
    else if(n == 1) return 0;
    else if(n == 2) return 1;
    return Tribonacci(n - 1) + Tribonacci(n - 2) + Tribonacci(n - 3);
}

//トリボナッチ数列の第n項を求める
int Tribonacci_memo(int n){
    if(n <= 0) return 0;
    else if(n == 1) return 0;
    else if(n == 2) return 1;
    // メモをチェック (すでに計算済みならば答えをリターンする)
    if(memo[n] != -1) return memo[n];
    // 答えをメモ化しながら，再帰呼び出し
    return memo[n] = Tribonacci_memo(n - 1) + Tribonacci_memo(n - 2) + Tribonacci_memo(n - 3);
}


int main()
{
    int n;
    cin >> n;
    cout << Tribonacci_memo(n) << endl;
    return 0;
}
