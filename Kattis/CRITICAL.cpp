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
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007],d[2][100007];
int s[100007], check[100007];
int b[100007];
vector <int> ans;

signed main()
{
    int n, sz = 0, lis = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i];

    for(int i = 0; i < n; i++)
        {
            int p = lower_bound(s, s + sz, a[i]) - s;

            s[p] = a[i];
            d[0][i] = p + 1;

            if(p == sz) sz++;
            a[i] = -a[i];

            lis = max(lis, d[0][i]);
        }

    sz = 0;
    for(int i = n - 1; i >= 0; i--)
        {
            int p = lower_bound(s, s + sz, a[i]) - s;
            s[p] = a[i];
            d[1][i] = p + 1;

            if(p == sz) sz++;
            
            if(d[0][i] + d[1][i] == lis + 1) check[d[0][i]]++;
        }

    for(int i = 0; i < n; i++)    
        {
            if(!(d[0][i] + d[1][i] != lis + 1) && !(check[d[0][i]] > 1)) ans.pb(b[i]);
        }

    if(ans.size())
        {
            sort(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
            cout << endl;
        }
    else cout << -1 << endl;
}
     