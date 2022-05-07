/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 
*/





int solution(vector &prices , int index , int n , int buy , int k , vector<vector<vector>> &dp){

	if(index == n)
			return 0;

	if(k == 0)
		return 0;
int profit = 0;
if(buy){
	
	profit = max(-prices[index] + solution(prices, index+1 , n , 0 , k,dp) ,
				solution(prices , index+1 , n , 1 , k,dp));
	
}else{
	profit = max(+prices[index] + solution(prices , index+1 , n , 1 , k -1,dp),
				solution(prices , index+1 , n ,0 , k,dp));
}

	return dp[index][buy][k] =  profit;
}

int maxProfit(vector& prices)
{
int n = prices.size();
 
vector<vector<vector>> dp(n + 1,vector<vector>(2 , vector(3 ,-1)) );
return solution(prices , 0 , n , 1 , 2 , dp);

}

int maxProfit(vector<int>& prices)
{
int n = prices.size();
 
// after Recursion I'm trying to implement TABULATION 3d table
vector<vector<vector>> dp(n + 1,vector<vector>(2 , vector(3 ,0)) );

// after memoization i'm try to implement tabulation
 

for(int i = n - 1 ; i>= 0 ; i--){
	for(int j = 1 ; j>= 0 ; j--){
		for(int k = 2 ; k>= 1 ; k--){
			int profit = 0;
if(j){
	
	profit = max(-prices[i] + dp[i+1][0][k] ,
				dp[i+1][1][k]);
	
}else{
	profit = max(prices[i] + dp[i +1][ 1][k -1],
				dp[i+1][0][k]);
}

  dp[i ][j][k] =  profit;

		}
	}
}

return dp[0][1][2];
}
