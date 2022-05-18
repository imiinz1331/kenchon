#include <bits/stdc++.h>
using namespace std;
/*入力形式
N v
a_0, a_1, a_2, ... , a_N-1
*/
int main() {
    int N;
    int v;
    int ans = 0;
    cin >> N >> v;
    vector<int> A(N);
    for(int i = 0;i < N; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N;i++){
        if(A.at(i) == v){
            ans ++;
        }
    }
    cout << ans << endl;
}
