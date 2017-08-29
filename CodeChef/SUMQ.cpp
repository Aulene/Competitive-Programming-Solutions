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

lli b[100007];
lli prefixA[100007], prefixC[100007];
vector <lli> av, cv;

lli p, q, r;

lli input()
{
	lli i, x;
	vector <lli> :: iterator it;

	av.clear();
	cv.clear();

	cin >> p >> q >> r;

	for(i=1; i<=p; i++)
		{
			cin >> x;
			av.pb(x);
		}

	for(i=1; i<=q; i++)
		cin >> b[i];

	for(i=1; i<=r; i++)
		{
			cin >> x;
			cv.pb(x);
		}

	sort(av.begin(), av.end());
	sort(cv.begin(), cv.end());
	sort(b + 1, b + q);

	i=1;
	for(it=av.begin(); it!=av.end(); it++)
		{
			prefixA[i] = (prefixA[i-1] + *it) % mod;
			i++;
		}

	i=1;
	for(it=cv.begin(); it!=cv.end(); it++)
		{
			prefixC[i] = (prefixC[i-1] + *it) % mod;
			i++;
		}

	/*
	for(i=1; i<=p; i++)
		cout << prefixA[i] << " ";
	cout << endl;

	for(i=1; i<=r; i++)
		cout << prefixC[i] << " ";
	cout << endl;
	*/

	return 0;
}

int main()
	{
		ios::sync_with_stdio(false);	
		cin.tie(NULL);

		lli t, ans, i;
		lli A, C;

		cin >> t;

		while(t--)
			{
				ans = 0;

				input();

				for(i=1; i<=q; i++)
					{
						A = upper_bound(av.begin(), av.end(), b[i]) - av.begin();
						C = upper_bound(cv.begin(), cv.end(), b[i]) - cv.begin();

						//cout << b[i] << " " << A << " " << C << endl;
						//cout << prefixA[A] << " " << prefixC[C] << endl;
						//cout << prefixA[A] * b[i] << " " << prefixC[C] * b[i] << " " << prefixA[A] * prefixC[C] << " " << b[i] * b[i] << endl;
						//cout << ans << endl;

						ans = (ans + (((prefixA[A] * b[i]) % mod) * C) % mod) % mod; // X*Y*C
						ans = (ans + (((prefixC[C] * b[i]) % mod) * A) % mod) % mod; // Z*Y*A
						ans = (ans + (prefixA[A] * prefixC[C]) % mod) % mod; // X*Z
						ans = (ans + (((((b[i] * b[i]) % mod) * A) % mod) * C) % mod) % mod; // Y^2*A*C
					}

				cout << ans << endl;
			}

		return 0;
	}

