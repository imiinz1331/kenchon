#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int ans=0;
    unordered_set<int> hash;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        hash.insert(a);
    }
    for(int i=0; i<m; i++) {
        int b;
        cin >> b;
        if(hash.count(b)) ans++;
    }
    cout << ans << endl;
    return 0;
}
