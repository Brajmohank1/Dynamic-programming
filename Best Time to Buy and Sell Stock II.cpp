long solution(int index , int n , vector &values , int buy , vector<vector> &dp){

	if(index == n)
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
	profit = max(values[index]  + solution(index + 1  , n , values , 1 ,  dp),
				solution(index + 1 , n , values , 0 ,  dp));
}

return dp[index][buy] = profit;
}

int maxProfit(vector<int>& values) {
    
    int n = values.size();
   vector<vector<long>> dp(n+1 , vector<long>(2 , -1));
return solution(0 , n , values , 1 ,   dp);

}

// Tabulation

 int maxProfit(vector<int>& values){
 vector<vector<long>> dp(n+1 , vector<long>(2 , -1));
return solution(0 , n , values , 1 ,   dp);

Here I'm Implementing concept of Tabulation in dp;

dp[n][0] = dp[n][1] = 0;

for(int j = n-1; j >= 0 ; j--)
{
	for(int i = 1 ; i >= 0 ; i--){
		
		long profit = 0;
if(i == 1)
	profit = max( - values[j] + dp[j+ 1][0]  ,
				 
				dp[j+ 1][1]);
	
 
 else
	profit = max(values[j]  +  dp[j + 1][1],
				dp[j + 1 ][0]);


  	dp[j][i] = profit;
		
	 
	}
 
}


	return dp[0][1];
    }


// space optimization
 int maxProfit(vector<int>& values){
  vector<long> prev(2 , 0) ,cur(2,0);
    
prev[0] = prev[1] = 0;

for(int j = n-1; j >= 0 ; j--)
{
	for(int i = 1 ; i >= 0 ; i--){
		
		long profit = 0;
if(i == 1)
	profit = max( - values[j] + prev[0]  ,
				 
				 prev[1]);
	
 
 else
	profit = max(values[j]  +  prev[1],
				prev[0]);


  	cur[i] = profit;
        prev = cur;
		
	 
	}
 
}


	return prev[1];
}
