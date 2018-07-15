#include <iostream>
using namespace std;
 
const int MAXN = 1000000;
 
long long int dp[MAXN + 2][10 + 2];
int D[10 + 2];
 
long long int f(int C, int N){
	if(C < 0) return 0;
	if(C == 0) return 1;
	if(N == 0) return 0;
 
	if(dp[C][N] == -1){
		dp[C][N] = f(C, N - 1) + f(C - D[N], N);
	}
	return dp[C][N];
}
 
int main() {
	for(int i = 0; i <= MAXN; i++){
		for(int j = 0; j <= 10; j++){
			dp[i][j] = -1;
		}
	}
	int C, N;
	cin >> C >> N;
 
	for(int i = 1; i <= N; i++){
		cin >> D[i];
	}
 
	cout << f(C, N) << "\n";
	return 0;
}