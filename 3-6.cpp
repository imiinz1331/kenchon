#include <bits/stdc++.h>
using namespace std;
int main() {
   int K, N;
   cin >> K >> N;
   int ans = 0;
   for(int i = 0; i<=K; i++){  
         for(int j = 0;j<=K; j++){
            if(0<=N-i-j && N-i-j <= K){
               ans ++;
            }
         }
      }
   cout << ans << endl;
}
