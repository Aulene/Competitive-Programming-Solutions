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

long long M[501][501];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t,n,k,l,i,j,y,lim;
	long long res,suma,mult,p,acu;
	for(i=0; i<=500; i++){
		M[i][0]= 0;
	}
	M[1][1]= 1; M[2][1]= 1; M[2][2]= 1;
	acu=1;
	for(i=3; i<=500; i++){
		for(j=2; j<i; j++){
			M[i][j]= acu;
		}
		acu= (acu*2)%mod;
		M[i][1]= acu;
		M[i][i]= acu;
	}
	cin>>t;
	for(l=0; l<t; l++){
		cin>>n;
		vector<long long> V(n+1);
		for(i=1; i<=n; i++){
			cin>>V[i];
		}
		suma= 0;
		for(i=1; i<=n; i++){
			p= (M[n][i]*V[i])%mod;
			suma= (suma+p)%mod;
		}
		mult= 0;
		for(i=1; i<n; i++){
			k= n-(i-1);
			for(j=1; j<=i; j++){
				p= 1;
				lim= j+k-1;
				for(y=j; y<=lim; y++){
					p= (p*V[y])%mod;
				}
				p= (p*M[i][j])%mod;
				mult= (mult+p)%mod;
			}
		}
		res= (suma+mult)%mod;
		cout<<res<<endl;
	}
}