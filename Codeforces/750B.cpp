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
		lli n, i, sum=0, x;
		string s;
		bool ans=1;

		cin >> n;

		while(n--)
			{
				cin >> x >> s;

				if(s=="South")
					{
						if(sum==20000 || sum+x>20000)
							ans=0;
						sum+=x;
					}
				else if(s=="North")
					{
						if(sum==0 || sum-x<0)
							ans=0;
						sum-=x;
					}
				else if(s=="East" || s=="West")
					{
						if(sum==0 || sum==20000)
							ans=0;
					}
			}

		if(ans && sum==0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}