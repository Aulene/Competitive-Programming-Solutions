#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	double arr[m][2];
	for(int i=0;i<m;i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	double c=0;
	for(int i=0;i<m;i++){
		c=c+arr[i][0];
	}
	for(int i=0;i<m;i++){
		if(arr[i][1]>=0){
			c=c+((n-1)/2)*arr[i][1];
		}
		else if(arr[i][1]<0){
			if(n%2==1){
				c=c+(((n+1)/2)*((n-1)/2)*arr[i][1])/(double)n;
			}
			else if(n%2==0){
				double a=(double)n/2;
				c=c+(a*(a-1)*arr[i][1]+a*arr[i][1])/n;
			}
		}
	}
	cout << c;
	// your code goes here
	return 0;
}