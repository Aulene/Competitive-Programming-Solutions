#include <iostream>
using namespace std;
const long long MAXN=2051;
const long long MAXC=8005001;
long long n, k, a[MAXN], b[MAXN], d[MAXN][MAXN], o=0, c[2*MAXC+1],r=0;

int main() {
	cin >> n >> k;
	for(long long i=0;i<n;i++){
		cin >> a[i];
	}
	for(long long i=0;i<k;i++){
		cin >> b[i];
	}
	o=-MAXC;
	for(long long i=0;i<n;i++){
		o+=a[i];
		for(long long j=0;j<k;j++){
			d[i][j]=b[j]-o;
		}
	}
	for(long long j=0;j<k;j++){
		for(long long i=0;i<n;i++){
			c[d[i][j]]++;
		}
	}
	for(long long i=0;i<2*MAXC+1;i++){
		if(c[i]>=k){
			r++;
		}
	}
	cout << r;
	return 0;
}