#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define endl '\n'
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define N 5000007

int prime[N], pre[N], a[N];

void compute() 
{
	for(int i = 2; i < N; i++) prime[i] = 1;

	for(int i = 2; i < N; i++) 
		if(prime[i])
			{
				for(int j = i * i; j < N; j += i)
					prime[j] = 0, a[j] = i;
			}

	for(int i = 2; i < N; i++)
		{
			if(prime[i]) pre[i] = 1;
			else pre[i] = pre[i / a[i]] + 1;
		}

	for(int i = 2; i < N; i++) pre[i] += pre[i - 1];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, n, a, b, i, j;

		cin >> t;

		compute();
		
		while(t--)
			{
				cin >> a >> b;
				cout << pre[a] - pre[b] << endl;
			}

		return 0;
	}