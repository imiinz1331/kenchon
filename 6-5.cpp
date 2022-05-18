#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> a(N);
    vector<long long> b(N);
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<N; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long hi=a[N-1]*b[N-1], lo=0;
    long long X;
    while(hi-lo > 1) {
        X = (hi+lo)/2;
        int count = 0;
        for(int i=0; i<N; i++) {
          
            long long bm = X/a[i];
            count += upper_bound(b.begin(), b.end(), bm) - b.begin();
        }
        if(K<=count) hi=X;
        if(count<K) lo=X;
    }
    cout << hi << endl;
    return 0;
}
