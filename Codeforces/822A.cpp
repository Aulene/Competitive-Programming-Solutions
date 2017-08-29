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
		lli a, b, minab, i;
		lli ans = 1;

		cin >> a >> b;

		minab = min(a, b);

		for(i=1; i<=minab; i++)
			ans *= i;

		cout << ans << endl;
		return 0;
	}