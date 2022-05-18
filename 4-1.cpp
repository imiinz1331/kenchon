#include <bits/stdc++.h>
using namespace std;
long long tri(int n){
    if(n==0||n==1) return 0;
    else if(n==2||n==3) return 1;
    else{
        return tri(n-3) + tri(n-2) + tri(n-1);
    }
}

int main(){
    int N;
    cin >> N;
    cout << tri(N) << endl;
    return 0;
}
