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

#define int long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n, m, a[100007];
int val1[100007], val2[100007];
int mapx[100007], tree[100007];
bool taken[100007];
vector <int> vs;

int summation(int id) 
{
   int sum = 0;

   while(id) 
      {
         sum += tree[id];
         id -= (id & -id);
      }

   return sum;
}

void update(int id, int v) 
{
   while(id < 100007) 
      {
         tree[id] += v;
         id += (id & -id);
      }
}

int nextid(int x) 
{
   int prev = upper_bound(vs.begin(), vs.end(), x) - vs.begin();

   if(prev == vs.size()) 
      return 0;
   return vs[prev];
}

signed main() 
{
   int i, v, prev, u, newv, ans;

   cin >> n;

   for(i = 1; i <= n; i++) 
      {
         cin >> a[i];
         vs.pb(a[i]);
      }

   sort(vs.begin(), vs.end());

   m = unique(vs.begin(), vs.end()) - vs.begin();

   for(i = n; i >= 1; i--) 
      {
         update(i, 1);

         v = a[i];
         u = nextid(v);

         if(mapx[v]) 
            val1[i] = mapx[v];
         else if(mapx[u]) 
            val2[i] = mapx[u];

         mapx[v] = i;
      }

   for(i = 1; i <= n; i++) 
      {
         v = a[i], u = nextid(v);

         if(!val1[i]) 
            val1[i] = mapx[v];

         if(!val2[i] && u) 
            val2[i] = mapx[u];
      }

   // for(i = 1; i <= n; i++) 
   //    cout << i << " " << val1[i] << " " << val2[i] << endl;

   prev = ans = 0;

   for(i = 1; i <= n; i++) 
      if(a[i] == vs[0])
         {
            prev = i;
            ans += i;
            update(i, -1);
            taken[i] = 1;
            break;
         }
      
   taken[0] = 1;

   while(1) 
      {
         newv = val1[prev];

         if(newv == prev || taken[newv]) 
            newv = val2[prev];

         if(taken[newv]) 
            break;

         if(newv > prev) 
            ans = ans + summation(newv) - summation(prev);
         else 
            ans = ans + summation(n) - summation(prev) + summation(newv);

         prev = newv;
         update(prev, -1);
         taken[prev] = 1;
      }

   cout << ans << endl;
}
