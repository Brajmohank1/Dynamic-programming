
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 





*/


int maxProfit(int k, vector& prices) {
int n = prices.size();

// after Recursion I'm trying to implement TABULATION 3d table
vector<vector<vector>> dp(n + 1,vector<vector>(2 , vector(k+1 ,0)) );

// after memoization i'm try to implement tabulation

for(int i = n - 1 ; i>= 0 ; i--){
for(int j = 1 ; j>= 0 ; j--){
for(int k1 = k ; k1>= 1 ; k1--){
int profit = 0;
if(j){

profit = max(-prices[i] + dp[i+1][0][k1] ,
			dp[i+1][1][k1]);
}else{
profit = max(prices[i] + dp[i +1][ 1][k1 -1],
dp[i+1][0][k1]);
}

dp[i ][j][k1] = profit;

	}
}
}

return dp[0][1][k];

}
