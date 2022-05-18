#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

/*
逆ポーランド記法 一桁の場合で
(3 + 4)*((1 + 3) - 2)
←→ 3 4 + 1 2 - *
*/

bool is_num(char x){
    int diff = x - '0';
    if(diff >= 0 && diff < 10) return true;
    return false;
}

int calc(string x){
    int len = x.size();
    stack<int> s;

    for(int i = 0;i < x.size();i++){
        if(is_num(x[i])){
            int tmp_n = x[i] - '0';
            s.push(tmp_n);
        }
        else{
            int sn = s.top();
            s.pop();
            int fn = s.top();
            s.pop();
            if(x[i] == '*') s.push(fn*sn);
            if(x[i] == '+') s.push(fn+sn);
            if(x[i] == '/') s.push(fn/sn);
            if(x[i] == '-') s.push(fn-sn);
        }
    }

    return s.top();
}

int main()
{
    string s;
    s = "34+12-*";
    cout << calc(s) << endl;
    return 0;
}
