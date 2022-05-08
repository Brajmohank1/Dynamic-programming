/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 



*/
class Solution {
public:
    
    
long solution(int index , int n , vector<int> &values , int buy , vector<vector<int>> &dp){

	if(index >= n)
		return 0;

if(dp[index][buy] != -1)
		return dp[index][buy];
long profit = 0;
if(buy){
	profit = max( - values[index] + solution(index + 1 , n , values , 0 ,  dp)
				,
				solution(index+ 1 , n , values , 1 , dp));
	
}
else{
	profit = max(values[index]  + solution(index + 2  , n , values , 1 ,  dp),
				solution(index + 1 , n , values , 0 ,  dp));
}

return dp[index][buy] = profit;
}
 

    int maxProfit(vector<int>& values) {
         int n = values.size();
   vector<vector<int>> dp(n+1 , vector<int>(2 , -1));
return solution(0 , n , values , 1 ,   dp);
    }
};
