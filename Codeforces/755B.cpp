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

std::vector<string> v;

int main()
	{
		lli n, m, i;
		lli w1=0, w2=0;
		bool x=1;

		string s1, s2;

		cin >> n >> m;
		w1=n;
		w2=m;

		for(i=0; i<n+m; i++)
			{
				cin >> s1;
				v.pb(s1);
			}

		sort(v.begin(), v.end());

		for(i=1; i<v.size(); i++)
			if(v[i-1] == v[i])
				{
					if(x)
						m--;
					else
						n--;

					x=!x;
				}

		if(n>m)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}