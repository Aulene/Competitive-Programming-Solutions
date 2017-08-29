#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>6
2 4
75 45
8 8
16 16
247 994
1000000000 1000000
 
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define sz size()
#define s second
#define pii pair<int, int>
#define all(s) s.begin(), s.end()
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define INF INT_MAX

using namespace std;
 
const int maxn = (int)1e5 + 100;
const int mod = (int)1e9 + 7;
const int maxlog = (int)20;
const int P = mod;

vector<int> pr;
int p[maxn], q, a, b;

inline int f(int p){
  if(p <= 1)
    return 0;
  for(int i = 2; i * i <= p; i++)
    if(p % i == 0)
      return 0;
  return 1;
}
inline void build(int a, vector<pii> &v){
  if(f(a)){
    v.pb(mp(a, 1));
    return ;
  }                   
  for(int i = 2; i * i <= a; i++)
  {
    if(a % i == 0)
      {
        int cnt = 0;
        while(a % i == 0){
          cnt++;
          a /= i;
        }
        v.pb(mp(i, cnt));
      }
  }
  if(a > 1)
    v.pb(mp(a, 1));
} 
inline bool check( vector<pii> &v, vector<pii> &v1){
  int i = 0, j = 0 ;
  int n = v.sz;
  int m = v1.sz;
  while(i < n && j < m && v[i].f == v1[j].f){
    if(v[i].s >= v1[j].s){
      v[i].s -= 2;
      v1[j].s -= 1;
    }
    else {
      v[i].s -= 1;
      v1[j].s -= 2;
    }
    if(v[i].s == 0)
      i++;
    if(v1[j].s == 0)
      j++;
  }
    return (i == n && j == m);
}
 
int main () 
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  p[0] = p[1] = 1;
  for(int i = 2; i <= 100000; i++)
  {
    if(!p[i])
    {
      pr.pb(i);
      if(i * 1ll * i <= (int)1e5){
        for(int j = i * i; j <= (int)1e5; j += i)
        {
          p[i] = 1;
        }
      }
    }
  }
  cin >> q;
  while(q--){
    cin >> a >> b;
    vector<pii> v, v1;
    build(a, v);
    build(b, v1);
    if(check(v, v1))
      cout << "Yes\n";
    else
      cout << "No\n";
  }  
}