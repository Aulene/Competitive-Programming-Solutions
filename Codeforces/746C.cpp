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
   
int main() {
	int s, x1, x2;
	int p, d, t1, t2;
	int ans=0, ans1, ans2;

	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

	if(t1>=t2) //igor ko bhagao plox
		{
			ans=abs(x2-x1);
			ans*=t2;
		}
	else if(x2<x1) //bc jitni math aati thi saari laga di
		{
			if(d==-1 && p>=x1)
				{
					ans1=(p-x2)*t1;
					ans2=(x1-x2)*t2;
					ans=min(ans1, ans2);
				}
			else if(d==-1 && p<x1)
				{
					ans1=(x1-x2)*t2;
					ans2=(2*s+(p-x2))*t1;
					ans=min(ans1, ans2);
				}
			else if(d==1)
				{
					ans1=(x1-x2)*t2;
					ans2=(2*s-x2-p)*t1;
					ans=min(ans1, ans2);
				}
			//cout << ans1 << " " << ans2 << endl;
		}
	else if(x2>x1)
		{
			if(d>0 && p<=x1)
				{
					ans1=(x2-p)*t1;
					ans2=(x2-x1)*t2;
					ans=min(ans1, ans2);
				}
			else if(d>0 && p>x1)
				{
					ans1=(x2-x1)*t2;
					ans2=(2*s+(x2-p))*t1;
					ans=min(ans1, ans2);
				}
			if(d<0)
				{
					ans1=(x2-x1)*t2;
					ans2=(x2+p)*t1;
					ans=min(ans1, ans2);
				}
			//cout << ans1 << " " << ans2 << endl;
		}

	cout << ans << endl;
	return 0;
}