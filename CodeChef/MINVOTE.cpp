#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], pref[100007], suf[100007];
int rt[100007], lt[100007], ans[100007];
int n;

void sright()
{
	queue <int> q;

	for(int i = 1; i <= n; i++) rt[i] = n;

	for(int i = 1; i <= n; i++)
		{
			while(!q.empty())
				{					
					int u = q.front();
					
					// cout << i << " " << u << " " << pref[i - 1] - pref[u] << " " << a[u] << endl;

					if(pref[i - 1] - pref[u] > a[u])
						{
							rt[u] = i - 1;
							q.pop();
						}
					else
						{
							break;
						}
				}

			q.p(i);
		}
}

void sleft()
{
	queue <int> q;

	for(int i = 1; i <= n; i++) lt[i] = 1;

	for(int i = n; i >= 1; i--)
		{
			while(!q.empty())
				{					
					int u = q.front();
					
					// cout << i << " " << u << " " << suf[i + 1] - suf[u] << " " << a[u] << endl;

					if(suf[i + 1] - suf[u] > a[u])
						{
							lt[u] = i + 1;
							q.pop();
						}
					else
						{
							break;
						}
				}

			q.p(i);
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, j;

		// cin >> t;

		// while(t--)
			{
				for(i = 0; i < 100007; i++) pref[i] = suf[i] = ans[i] = 0;

				cin >> n;
				for(i = 1; i <= n; i++) cin >> a[i], pref[i] = pref[i - 1] + a[i];
				for(i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];

				sright(); 
				sleft();

				// for(i = 1; i <= n; i++) cout << rt[i] << " "; cout << endl;
				// for(i = 1; i <= n; i++) cout << lt[i] << " "; cout << endl;

				for(i = 1; i <= n; i++) cout << i << " " << lt[i] << " " << rt[i] << endl;
						
				for(i = 1; i <= n; i++)
					{
						ans[rt[i] + 1]--;
						ans[lt[i]]++;
					}

				for(i = 1; i <= n; i++) ans[i] = ans[i - 1] + ans[i];
				for(i = 1; i <= n; i++) cout << ans[i] - 1 << " "; cout << endl;
			}
		return 0;
	}