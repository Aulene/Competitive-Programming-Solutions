#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>


using namespace std;

#define MAX 1000009

typedef long long ll;

class FenwickTree{
private:
  vector<ll> ft;
  int N; // Size of the tree
public:
  FenwickTree(int n){
    N = n+1;
    ft.resize(N,0);
  }
  void update(int i, ll val){
    for(;i < N; i+=(i&(-i))){
      ft[i] += val;
    }
  }
  int query(int i){
    ll sum = 0;
    for(; i > 0; i-=(i&(-i))){
      sum += ft[i];
    }
    return sum;
  }
};

int main(){
  int T;
  scanf("%d",&T);
  printf("T = %d\n",T);
  while(T--){
    int N;
    scanf("%d",&N);
    printf("N = %d\n",N);
    int a[MAX],orig[MAX];
    for(int i = 0; i < N; i++){
      scanf("%d",&orig[i]);
      // a[i] = orig[i];
    }
    sort(a,a+N);

    int idx = 0;
    int rank[MAX];
    rank[a[0]] = idx;
    for(int i = 1; i < N; i++){
      if(a[i] != a[i-1]){
  	rank[a[i]] = ++idx;
      }
    }

    FenwickTree ft(N);
    ll ans = 0;
    for(int i = 0; i < N; i++){
      ans += ft.query(rank[a[i]]-1);
      ft.update(rank[a[i]],a[i]);
    }

    printf("%lld\n",ans);
  }
  return 0;
}
