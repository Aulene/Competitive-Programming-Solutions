#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define ll long long
ll mod=1000000007;
struct st
{
	int type,l,r;
	st(int i,int j,int k):type(i),l(j),r(k)
	{}
	st()
	{}
};
 
ll seg[400009],arr[100009];
 
void push(int root,int low,int high)
{
	if(low == high)
	return ;
 	cout << seg[2 * root + 1] << " " << seg[2 * root + 2] << endl;
	seg[2*root+1]=(seg[2*root+1]+seg[root])%mod;
	seg[2*root+2]=(seg[2*root+2]+seg[root])%mod;
	cout << seg[2 * root + 1] << " " << seg[2 * root + 2] << endl;
	seg[root]=0;
}
 
void update(int root,int low,int high,int l,int r,ll val)
{
	cout << "OPEN " << root << " " << seg[root] << endl;
	push(root,low,high);
	cout << "CLOSE" << endl;

	if(high<l || low>r)
	return ;
	if(l<=low && r>=high)
	{
		seg[root]=(seg[root] + val)%mod;
		return;
	}
 
	int left=2*root+1,right=left+1,mid=(low+high)/2;
	update(left,low,mid,l,r,val);
	update(right,mid+1,high,l,r,val);
}
 
int query(int root,int low,int high,int idx)
{
	if(low==high)
	return seg[root];
	push(root,low,high);
	int left=2*root+1,right=left+1,mid=(low+high)/2;
 
	if(idx<=mid)
	return query(left,low,mid,idx);
 
	return query(right,mid+1,high,idx);
}
vector<st> vec;
int main()
{
	ll i,j,k,l,m,n,t,val;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
 
		memset(arr,0,sizeof(arr));
 
		memset(seg,0,sizeof(seg));
		l=m;
		while(l--)
		{
			cin>>i>>j>>k;
			j--;
			k--;
 
			vec.push_back(st(i,j,k));
		}
		st temp;
		for(i=m-1;i>=0;i--)
		{
			temp=vec[i];
			val=(query(0,0,m-1,i)+1)%mod;
 
			if(temp.type==1)
				{
					arr[temp.l]=(arr[temp.l]+val)%mod;
					arr[temp.r+1]=(arr[temp.r+1] - val)%mod;
				}
			else
				update(0,0,m-1,temp.l,temp.r,val);
	
			cout << val << endl;
		}
 
		for(i=1;i<n;i++)
		arr[i]+=arr[i-1];
 
		for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
		cout<<"\n";
		vec.clear();
	}
	return 0;
}