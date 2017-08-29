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
 
#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
 
bool prime[1000007];
lli a[100007];
lli smallestPrime[1000007];
 
int sieve()
{
	lli i, j;
 
	for(i = 0; i < 1000007; i++)
		prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;
 
	for(i = 2; i < 1000007; i += 2)
		smallestPrime[i] = 2;
 
	for(i = 3; i < 1000007; i += 2)
		{
			if(prime[i])
				{
					smallestPrime[i] = i;
 
					for(j = i; j * i < 1000007; j += 2)
						{
							if(prime[i * j])
								{
									prime[i * j] = 0;
									smallestPrime[i * j] = i;	
								}
						}
				}
		}
 
	return 0;
}
 
lli primesinLogN(lli n, lli X, lli Y)
{
	lli N = n;
 
	//cout << "LOOP FOR " << N << " STARTED" << endl;
 
	lli ans = 0;
	vector <lli> fx;
	vector <lli> :: iterator it, it1, it2;
 
	while(n > 1)
		{
			//cout << n << " " << smallestPrime[n] << endl;
			fx.pb(smallestPrime[n]);
			n /= smallestPrime[n];
		}
 
	/*
	for(it = fx.begin(); it != fx.end(); it++)
		cout << *it << " ";
	cout << endl;
	*/
 
	it1 = lower_bound(fx.begin(), fx.end(), X);
	it2 = upper_bound(fx.begin(), fx.end(), Y);
	ans = it2 - it1;
 
	//cout << "LOOP FOR " << N << " ENDED" << endl;
	return ans;
}
 
lli func(lli L, lli R, lli X, lli Y)
{
	lli ans = 0, i, j;
	lli number, exponent;
 
	for(j=L; j<=R; j++)
		{
			ans += primesinLogN(a[j], X, Y);
		}
 
	return ans;
}
 
int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(NULL);
 
		lli t, l, r, x, y, i, q, n;
 
		sieve();
 
		cin >> n;
 
		for(i=1; i<=n; i++)
			cin >> a[i];
 
		cin >> q;
 
		while(q--)
			{
				cin >> l >> r >> x >> y;	
				cout << func(l, r, x, y) << endl;
			}
 
		return 0;
	} 