#include<bits/stdc++.h>

using namespace std;

int main()
	{
		int n, t, i;long double ans;cin>>t;while(t--)
			{ans=0; cin>>n; for(i=0; i<n; i++) ans+=pow(-1, i)/(2*i + 1);printf("%0.15Lf\n", ans);
			}
		return 0;
	}