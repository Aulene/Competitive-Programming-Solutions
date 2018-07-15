#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int p[100007], ans[1007];
vector <int> vs;

bool check(int n)
{
	if(ans[n] == 0) return 1;
	return 0;
}

void sieve()
{
	for(int i = 1; i < 1007; i++) ans[i] = LLONG_MAX;
	ans[1] = 1;
	// vs.pb(1);

	for(int i = 2; i < 1007; i++) p[i] = 1;

	for(int i = 2; i < 100007; i++)
		if(p[i])
			{
				vs.pb(i);
				for(int j = i * i; j < 100007; j += i)
					p[j] = 0;
			}

	for(int i = 0; i < vs.size(); i++)
		{	
			int u = 2, v = 1;

			for(int j = vs[i]; j <= 1000; j *= vs[i]) 
				{
					ans[j] = pow(u, vs[i] - 1);
					u *= vs[v];
					v++;
				}

			// if(check(vs[i]))
			// 	ans[vs[i]] = pow(2, vs[i] - 1);
			
			// if(vs[i] * vs[i] <= 1000 && check(vs[i] * vs[i]))
			// 	ans[vs[i] * vs[i]] = pow(6, vs[i] - 1);

			// for(int j = i; j < vs.size(); j++)
			// 	if(vs[i] * vs[j] <= 1000 && check(vs[i] * vs[j])) 
			// 		ans[vs[i] * vs[j]] = (pow(2, vs[j] - 1) * pow(3, vs[i] - 1));
			// 	else break;

			// for(int j = 0; j < vs.size(); j++)
			// 	for(int k = j + 1; k < vs.size(); k++)
			// 		if(vs[i] * vs[j] * vs[k] <= 1000 && check(vs[i] * vs[j] * vs[k]))
			// 			ans[vs[i] * vs[j] * vs[k]] = (pow(2, vs[k] - 1) * pow(3, vs[j] - 1) * pow(5, vs[i] - 1));
			// 		else break;
			
			for(int j = 0; j < vs.size(); j++)
				{
					if(vs[i] * vs[j] <= 1000) 
						ans[vs[i] * vs[j]] = min(ans[vs[i] * vs[j]], (int)(pow(2, vs[j] - 1) * pow(3, vs[i] - 1)));
					else break;
				}

			for(int j = 0; j < vs.size(); j++)
				for(int k = 0; k < vs.size(); k++)
					{
						if(vs[i] * vs[j] * vs[k] <= 1000)
							ans[vs[i] * vs[j] * vs[k]] = min(ans[vs[i] * vs[j] * vs[k]], (int) (pow(2, vs[k] - 1) * pow(3, vs[j] - 1) * pow(5, vs[i] - 1)));
						else break;
					}
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		sieve();

		int n, i, j = 1;

		cin >> n;
		cout << ans[n] << endl;

		return 0;
	}