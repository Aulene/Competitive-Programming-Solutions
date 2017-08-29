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

int a[100007];
bool isntRekt[100007];
int avails[100007];
vector<int> v;
int ans;

int main()
	{
		int t, n, i, maxv;
		vector<int>::iterator it, it1, it2;

		cin >> t;

		while(t--)
			{
				ans=0;

				cin >> n;

				for(i=0; i<100007; i++)
					{
						isntRekt[i]=1;
						avails[i]=0;
					}

				for(i=1; i<=n; i++)
					{
						cin >> a[i];
						v.pb(a[i]);
						avails[a[i]]++;
					}

				for(i=1; i<=n; i++)
					{
						if(a[i-1] < a[i])
							{
								
							}
					}

				for(i=1; i<=n; i++)
					if(isntRekt[i])
						ans++;

				cout << ans << endl;
			}


		return 0;
	}