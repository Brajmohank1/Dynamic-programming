/*
Given an array of N integers, you have to find if it is possible to partition the array with following rules:

Each element should belong to exactly one partition.
Each partition should have atleast K elements.
Absolute difference between any pair of elements in the same partition should not exceed M.
Example 1:

Input:
N = 5
K = 2
M = 3
A[] = {8, 3, 9, 1, 2}
Output:
YES
Explanation:
We can partition the array into two 
partitions: {8, 9} and {3, 1, 2} such that
all rules are satisfied.
Your Task:
You don't need to read input or print anything. Your task is to complete the function partitionArray() which takes the number of elements N, integer K, integer M and array A[ ] as input parameters and returns true if we can partition the array such that all rules are satisfied, else returns false.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 2*105
1 ≤ K ≤ N
1 ≤ M ≤ 109
1 ≤ A[i] ≤ 109



*/

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[(int)1e6];
    bool solution(int n , int k , int m , vector<int> &a , int i){
        
        if(i >= n)
            return dp[i] = true;
            if(dp[i] != -1)
                return dp[i];
        for(int j = i + k - 1 ; j < n ; j++ ){
            
            int val = abs(a[i] - a[j]);
            if(val > m )
                break;
            
            bool next = solution(n , k , m, a , j + 1);
            if(next) return dp[i] = true;
        }
        
        return dp[i] = false;
        
    }
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
        
        sort(A.begin() , A.end());
        memset(dp , -1 , sizeof(dp));
        
        return solution(N , K , M , A , 0);
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends
