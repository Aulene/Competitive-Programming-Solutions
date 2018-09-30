#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define N 1000007

bool prime[N];
int collatzDp[N];
vi vs;

void sieve()
{
	for(int i = 2; i < N; i++) prime[i] = 1;
	for(int i = 2; i < N; i++)
		if(prime[i]) { vs.pb(i); for(int j = i * i; j < N; j += i) prime[j] = 0; }
}

int numDiv(int n)
{
	int ans = 0;

	for(int i = 1; i <= sqrt(n); i++) {
		if(n % i == 0) {
			int u = i * i;
			if(u != n) ans += 2;
			else ans++;
		}
	}

	return ans;
}

int collatzMemo(int n)
{
	if(collatzDp[n] != -1) return collatzDp[n];
	if(n % 2 == 0) 
		return collatzDp[n] = 1 + collatzMemo(n / 2);
	return collatzDp[n] = 1 + collatzMemo(3 * n + 1);
}

int collatz(int n)
{
	if(n == 1) return 1;
	if(n % 2 == 0) 
		return 1 + collatz(n / 2);
	return 1 + collatz(3 * n + 1);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// sieve();
		
		memset(collatzDp, -1, sizeof(collatzDp));
		collatzDp[1] = 1;

		int ansx, ans = 0, sum = 0;

		for(int i = 1; i <= 1000000; i++) 
			{ 
				sum = collatz(i); 
				if(sum > ans) {
					ans = sum;
					ansx = i;
				}
			}

		cout << ansx << endl;

		return 0;
	}