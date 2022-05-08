/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 



*/





class Solution {
public:
    long solution(int index , int n , vector<int> &values , int buy , vector<vector<int>> &dp, int fee){

	if(index >= n)
		return 0;

if(dp[index][buy] != -1)
		return dp[index][buy];
long profit = 0;
if(buy){
	profit = max( - values[index] + solution(index + 1 , n , values , 0 ,  dp,fee)
				,
				solution(index+ 1 , n , values , 1 , dp,fee));
	
}
else{
	profit = max(values[index]  - fee + solution(index + 1  , n , values , 1 ,  dp, fee),
				solution(index + 1 , n , values , 0 ,  dp,fee));
}

return dp[index][buy] = profit;
}
 



    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2 , -1));
return solution(0 , n , prices , 1 ,   dp , fee);
        
    }
};
