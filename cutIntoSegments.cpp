#include<limits.h>
#include<algorithm>

// DP - TOP DOWN

int fn(int n, int x, int y, int z, vector<int>&dp){
	dp[0] = 0;
	for(int i  = 1; i <=n ; i++){
		int a = INT_MIN, b= INT_MIN, c= INT_MIN;
		if(i >= x && dp[i-x] != INT_MIN)
			a = dp[i-x]+1;
		if(i >= y && dp[i-y] != INT_MIN)
			b = dp[i-y]+1;
		if(i >= z && dp[i-z] != INT_MIN)
			c = dp[i-z]+1;

		dp[i] = max({a,b,c});
	}
	return dp[n];
}

// DP - TOP DOWN

// int fn(int n, int x, int y, int z, vector<int>&dp){
// 	if(n == 0) return 1;
// 	if(n < 0) return 0;

// 	if(dp[n] != -1) return dp[n];
// 	int a = 0, b = 0, c= 0;

// 	a = fn(n-x, x, y, z, dp);
// 	if(a> 0) a +=1;
// 	b = fn(n-y,x, y, z,dp);
// 	if(b > 0) b+= 1;
// 	c = fn(n-z,x, y, z, dp);
// 	if( c> 0) c+= 1;
// 	return dp[n] = max(a, max(b,c));

// }


//RECURSION
// int fn(int n, int x, int y, int z){
// 	if(n == 0) return 1;
// 	if(n < 0) return 0;
// 	int a = 0, b = 0, c= 0;

// 	a = fn(n-x, x, y, z);
// 	if(a> 0) a +=1;
// 	b = fn(n-y,x, y, z);
// 	if(b > 0) b+= 1;
// 	c = fn(n-z,x, y, z);
// 	if( c> 0) c+= 1;
// 	return max(a, max(b,c));

// }

int cutSegments(int n, int x, int y, int z) {
	vector<int>dp(n+1, INT_MIN);
	int res = fn(n,x,y,z, dp);
	if(res < 0) return 0;
	return res;
}