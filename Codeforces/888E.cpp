#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[47];
int m;
vector <int> vs1, vs2;

void recur(vector <int> &vs, int idx, int ed, int sum)
{
    if(idx > ed) {
        vs.pb(sum);
        return;
    }   

    recur(vs, idx + 1, ed, (sum + a[idx]) % m);
    recur(vs, idx + 1, ed, sum % m);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

        int n, t, i, j, u, v, k, ans = 0;

        cin >> n >> m;        

        for(i = 1; i <= n; i++) cin >> a[i];

        int x = n / 2;

        recur(vs1, 1, x, 0);
        recur(vs2, x + 1, n, 0);

        sort(vs1.begin(), vs1.end());
        sort(vs2.begin(), vs2.end());

        // for(i = 0; i < vs1.size(); i++) cout << vs1[i] << " "; cout << endl;
        // for(i = 0; i < vs2.size(); i++) cout << vs2[i] << " "; cout << endl;

        for(i = 0; i < vs1.size(); i++) {
            ans = max(ans, vs1[i]);

            k = m - vs1[i];
            j = lower_bound(vs2.begin(), vs2.end(), k) - vs2.begin();
            j--;

            v = (vs1[i] + vs2[j]) % m;
            ans = max(ans, v);
        }

        cout << ans << endl;

		return 0;
	}