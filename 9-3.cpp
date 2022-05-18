#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;


// (：push ):pop(空なら整合しない)

int main()
{
    string S;
    cin>>S;
    stack<int> stack;
    
    rep(i,(int)S.sixe()){
        if (S[i] == '(') stack.push(i);
        else {
            // )が過剰 スタックが空なのにpop
            if (stack.empty()) {
                cout << "整合していない" << endl;
                return 0;
            }
            // 空じゃないとき
            int top = stack.top();
            stack.pop();
        }
    }

    // (が過剰
    if (!stack.empty()) {
        cout << "整合していない" << endl;
        return false;
    }

    // (と)が同数
    cout<<"整合している"<<endl;
    return 0;
}
