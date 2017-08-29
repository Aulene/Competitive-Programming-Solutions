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

bool a[100007];

int main()
	{
		lli n, t, i;

		cin >> t;

		while(t--)
			{
				lli back=0, ans=0;

				cin >> n;

				for(i=0; i<n; i++)
					cin >> a[i];

				for(i=0; i<n; i++)
					{
						if(!a[i])
							{
								ans+=1000;
								back++;
							}	
						else
							{
								if(back)
									{
										back++;
									}
							}
					}

				ans=ans+100*back;
				cout << ans << endl;
			}

		return 0;
	}