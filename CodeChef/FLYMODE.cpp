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

lli a[100007];
lli ascend[100007], descend[100007];

int main()
	{
		lli n, i, j, ansVal=0, ans=0, curAns=0, f, alt=0;
		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i];

		for(i=1; i<n; i++)
			{
				ascend[i-1]=a[i-1];
				descend[i-1]=a[i];

				if(ascend[i-1] > descend[i-1])
					{
						f=ascend[i-1];
						ascend[i-1]=descend[i-1];
						descend[i-1]=f;
					}
			}

		sort(ascend, ascend+n-1);
		sort(descend, descend+n-1);

		//for(i=0; i<n-1; i++)
		//	cout << ascend[i] << " " << descend[i] << endl;

		i=0, j=0;
		n--;

		while(i<n && j<n)
			{
				if(ascend[i] < descend[j])
					{
						i++;
						alt++;
					}
				else
					{
						j++;
						alt--;
					}

				ans=max(ans, alt);
			}

		cout << ans << endl;
		return 0;
	}