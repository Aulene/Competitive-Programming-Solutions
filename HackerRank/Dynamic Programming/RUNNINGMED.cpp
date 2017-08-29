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
#define pq priority_queue

pq <int, vector<int>, greater <int> > minHeap;
pq <int, vector<int> > maxHeap;

int add(int x)
{
	if(maxHeap.size() && x>=maxHeap.top())
		minHeap.p(x);
	else
		maxHeap.p(x);

	int f=maxHeap.size(), y=minHeap.size();
	f=abs(f-y);

	if(f > 1)
		{
			if(maxHeap.size() > minHeap.size())
				{
					int t=maxHeap.top();
					maxHeap.pop();
					minHeap.p(t);
				}
			else
				{
					int t=minHeap.top();
					minHeap.pop();
					maxHeap.push(t);
				}
		}

	return 0;
}

double median(int time)
{
	double ans=0;

	if(time%2==1)
		{
			if(maxHeap.size() > minHeap.size())
				return maxHeap.top();
			else
				return minHeap.top();
		}
	else
		{
			if(!maxHeap.empty())
				ans+=maxHeap.top();
			if(!minHeap.empty())
				ans+=minHeap.top();
		}

	return ans/2;
}

int main()
	{
		int n, no=0, j, i, u, k, num;
		double ans;

		cin >> n;

		for(i=1; i<=n; i++)
			{
				cin >> u;
				add(u);
				ans=median(i);

				printf("%0.1f\n", ans);
			}

		return 0;
	}