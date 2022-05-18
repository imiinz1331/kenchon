#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<int,int> P;


int main() {
  double pi = acos(-1);
    double a,b,c,l,h,m=INT_MAX,mid;
    cin >> a >> b >> c;

    rep(i,101){
        if((a*i+b*sin(c*i*pi)-100)*(a*(i+1)+b*sin(c*(i+1)*pi)-100)<=0){
           l=i;
        }
    }
  
  //cout << l << endl;
    

  h = l+1;

  //cout << pi << endl;
    for(double j=l;j<=h;j=j+0.0000001){
        if(abs(a*j+b*sin(c*j*pi)-100)<=0.000001){
          cout << j << endl;
          return 0;
          
        }
    }
  return 0;

}
