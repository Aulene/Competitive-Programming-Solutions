#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define PB push_back
#define MP make_pair
#define SZ size()
#define Fr first
#define Sc second
#define si(a) scanf("%d", &a)
#define sl(a) scanf("%I64d", &a)
#define sd(a) scanf("%lf", &a)
#define ss(a) scanf("%s", a)
#define debug(x) cout << #x << ": " << x << endl
#define Fast_IO ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long Long;
typedef pair <int, int> Pii;
///<-------------------------------------------------END OF TEMPLATE-------------------------------------------------->

#define MAX 100005
int N, M, A[MAX], nxts[MAX], nxtb[MAX], upto[MAX], tree[MAX];
bool taken[MAX];
vector <int> vec;

int read(int id) {
   int sum = 0;
   while(id > 0) {
      sum += tree[id];
      id -= (id & -id);
   }
   return sum;
}

void update(int id, int v) {
   while(id < MAX) {
      tree[id] += v;
      id += (id & -id);
   }
}

int findNext(int x) {
   int p = upper_bound(vec.begin(), vec.end(), x) - vec.begin();
   if(p == vec.SZ) return 0;
   return vec[p];
}

int main() {
   si(N);
   for(int i = 1; i <= N; i++) {
      si(A[i]);
      vec.PB(A[i]);
   }
   sort(vec.begin(), vec.end());
   M = unique(vec.begin(), vec.end()) - vec.begin();
   vec.resize(M);
   int mx = vec.back();

   for(int i = N; i > 0; i--) {
      update(i, 1);
      int v = A[i], u = findNext(v);
      if(upto[v]) nxts[i] = upto[v];
      else if(upto[u]) nxtb[i] = upto[u];
      upto[v] = i;
   }
   for(int i = 1; i <= N; i++) {
      int v = A[i], u = findNext(v);
      if(!nxts[i]) {
         nxts[i] = upto[v];
      }
      if(!nxtb[i] && u) {
         nxtb[i] = upto[u];
      }
   }
   for(int i = 1; i <= N; i++) printf("nxts[%d]: %d nxtb[%d]: %d\n", i, nxts[i], i, nxtb[i]);

   int p = 0;
   Long ans = 0;
   for(int i = 1; i <= N; i++) if(A[i] == vec[0]) {
      p = i;
      ans += i;
      update(i, -1);
      taken[i] = 1;
      break;
   }
   //cout << p << endl;
   taken[0] = 1;
   while(true) {
      int nxt = nxts[p];
      if(nxt == p || taken[nxt]) nxt = nxtb[p];
      if(taken[nxt]) break;
      //cout << nxt << endl;
      if(nxt > p) ans += (read(nxt) - read(p));
      else ans += (read(N) - read(p) + read(nxt));
      //cout << (read(nxt) - read(p)) << ' ';
      //cout << (read(N) - read(p) + read(nxt)) << endl;
      p = nxt;
      update(p, -1);
      taken[p] = 1;
   }
   cout << ans << endl;
}
