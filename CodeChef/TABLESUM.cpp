#include <iostream>
using namespace std;

#define MAXN 200005
int N,A[MAXN] ;
int main() {
	int j;

	// your code goes here
	cin >> N ;
	for(int i=1;i<=N;i++)
		cin >> A[i] ;
		
	for(int i=1;i<=N;i++){
		A[i] += i;
		A[i] = max(A[i],A[i-1]) ;
	}
	for(j=1; j<=N; j++)
			cout << A[j] << " ";
		cout << endl;
	//cout << A[N] << " " ;
	int cnt = 0;
	for(int i=N;i>1;i--){
		A[i] -= N ;
		A[i] = max(A[i],A[i+1])+1 ;
		++cnt ;
		A[i-1] += cnt ;
		//cout << max(A[i],A[i-1]) << " " ;
		for(j=1; j<=N; j++)
			cout << A[j] << " ";
		cout << endl;
	}
	return 0;
}