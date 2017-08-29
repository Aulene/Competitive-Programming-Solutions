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

map <lli, int> m;
vector<lli> v;
lli facts[100007];

lli fact()
{
	lli i, ans=1;

	for(i=1; i<=10007; i++)
		{
			ans=(ans*i)%mod;
			facts[i]=ans;
		}

	return 0;
}

int main()
	{
		fact();

		int t, n, i;
		lli u;
		vector <lli>::iterator it;

		cin >> t;

		while(t--)
			{
				bool ans=0;
				lli pos=1;

				cin >> n;

				for(i=0; i<n; i++)
					{
						cin >> u;

						if(!m[u])
							v.pb(u);

						m[u]++;
					}

				sort(v.begin(), v.end());

				for(it=v.begin(); it!=v.end(); it++)
					{
						u=*it;

						pos=(pos*facts[u])%mod;
						if(pos>=3)
							{
								ans=1;
								break;
							}
					}

				if(ans)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;

				v.clear();
				m.clear();
			}

		return 0;
	}