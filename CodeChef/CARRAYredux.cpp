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

int a[100007];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, b, i, j, m, mx, ans;
    bool check;

    cin >> t;

    while(t--)
        {
            cin >> n >> k >> b;
            
            for(i = 0; i < n; i++) cin >> a[i];
            sort(a, a + n);

            m = a[0], mx = k * a[0] + b, ans = 1;
            check = 0;
            
            for(i = 1; i < n; i++)
                if(a[i] >= mx)
                    {
                        ans++;
                        m = a[i];
                        mx = k * m + b;
                        check = 1;
                    }

            cout << ans << endl;
        }

    return 0;
}