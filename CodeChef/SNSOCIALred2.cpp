#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int maxi(int a,int b){
	if(a>b)
	return a;
	else
	return b;
}

int mini(int a,int b){
	if(a<b)
	return a;
	else
	return b;
}

int main() {
	int T;
	cin>>T;
	while(T--){
		int n,m,i,j,x;
		cin>>m>>n;
		vector<int> max;
		int mval=0;
		int grid[m][n];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>x;
				grid[i][j]=x;
				if(x>mval){
					vector<int> v;
					v.push_back(i);
					v.push_back(j);
					max=v;
					mval=x;
				}
				else
				if(x==mval){
					max.push_back(i);
					max.push_back(j);
				}
			}
		}
		
		int k=max.size();
		int ans=0;
		for(int a=0;a<m;a++){
			for(int b=0;b<n;b++){
				int min=100000;
				for(int i=0;i<k;i+=2){
					int x=max[i];
					int y=max[i+1];
					int z=maxi(abs(a-x),abs(b-y));
//					cout<<"z="<<z<<endl;
					min=mini(z,min);
					if(min<ans)
					break;
				}
				
	//			cout<<"a= "<<a<<" b="<<b<<" min="<<min<<endl;
				
				if(min>ans)
				ans=min;
			}
		}
		
		//	cout<<"i="<<max[i]<<" j="<<max[i+1]<<endl;
		cout<<ans<<endl;
	}
	// your code goes here
	return 0;
}