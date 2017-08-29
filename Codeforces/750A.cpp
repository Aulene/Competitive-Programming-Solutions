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

int main()
	{
		int n, m, ans=0, i=1;
		int x=0;

		cin >> n >> m;

		m=4*60-m;

		while(x<=m)
			{
				x+=5*i;
				i++;
				if(x<=m)
					ans++;
			}

		ans=min(ans, n);
		cout << ans << endl;
		return 0;
	}