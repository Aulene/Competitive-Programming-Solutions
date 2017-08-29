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

vector<int> v;
int a[100007], a1[100007], a2[100007];
int ans[100007];

int main()
	{
		int t, i, n;
		vector<int>::iterator it;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i=0; i<2*n; i++)
					cin >> a[i];

				sort(a, a+2*n);

				for(i=0; i<n; i++)
					{
						ans[i]=max(a[i], a[i+n]);
						v.pb(a[i]);
						v.pb(a[i+n]);
					}

				sort(ans, ans+n);

				cout << ans[(n-1)/2] << endl;

				for(it=v.begin(); it!=v.end(); it++)
					cout << *it << " ";
				cout << endl;

				v.clear();
			}

		return 0;
	}