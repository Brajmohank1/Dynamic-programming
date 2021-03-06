/*Brajmohan kumar Singh  
	#April long two #codechef
*/


#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
#define int long long
#define endl "\n"
using namespace __gnu_pbds;


const int sz=2e5+10;
int arr[sz];
int n;
int dp[sz][3][3];

int mod=998244353;

int solve(int i,int prev,int cur){
	
	
	if(i+1==n){
		return (prev != ((cur+arr[i])%2));
	}
	
	if(dp[i][prev][cur] != -1){
		return dp[i][prev][cur];
	}
	
	int ans=solve(i+1,prev,(cur+arr[i])%2);
	
	if(prev != ((cur+arr[i])%2)){
		ans+=solve(i+1,(cur+arr[i])%2,0);
	}
	
	return dp[i][prev][cur]=ans%mod;
}

signed main(){
//	
//	freopen("chef12.txt","r",stdin);
//	freopen("chef12_output.txt","w",stdout);
	ios_base::sync_with_stdio(0) , cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		
		for(int i=0;i<n+5;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					dp[i][j][k]=-1;
				}
			}
		}
		// dp(i,parity_of_sum_of_pervious_block, parity_of_current_ongoing_sum);
		cout<<solve(0,2,0)<<endl;
	}
	return 0;
}


/*  Question Codechef 
	You are given an array A of size N.

A partitioning of the array A is the splitting of A into one or more non-empty contiguous subarrays such that each element of A belongs to exactly one of these subarrays.

Find the number of ways to partition A such that the parity of the sum of elements within the subarrays is alternating. In other words, if Si denotes the sum of the elements in the i-th subarray, then either

S1 is odd, S2 is even, S3 is odd and so on.
or S1 is even, S2 is odd, S3 is even and so on.
For example if A=[1,2,3,3,5]. One way to partition A is [1,2][3,3][5]. Another way to partition A is [1][2][3][3,5]. Note that there exists more ways to partition this array.

Since the answer may be large, output it modulo 998244353.

*/