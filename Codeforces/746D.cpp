#include<iostream>
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
#define pb push_back

int main()
	{
		int n, a, b, k, i=0;
		int contA=0, contB=0, prev;

		cin >> n >> k >> a >> b;
		string ans (n, '0');

	
		while(i<n)
			{
				bool flag=1;

				if((a>=b && contA<k) || contB==k)
					{
						if(a>0)
							{
								a--;
								ans[i]='G';
								contA++;
								contB=0;
								prev=1;
								i++;
								flag=0;
							}
					}

				if(i>=n)
					break;

				if((b>=a && contB<k) || contA==k)
					{
						if(b>0)
							{
								b--;
								ans[i]='B';
								contB++;
								contA=0;
								prev=2;
								i++;
								flag=0;
							}
					}
				//cout << ans << endl;
				if(flag)
					{
						ans="NO";
						break;
					}
				if(i>=n)
					break;
			}

		cout << ans << endl;
		return 0;
	}