#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &dp, int n) {
    if (n == 0 || n == 1) {
        return dp[n] = n;  // Base case: fib(0) = 0, fib(1) = 1
    }
    if (dp[n] != -1) {
        return dp[n];  // If already computed, return the stored value
    }
    // Recursively calculate the Fibonacci of n
    dp[n] = solve(dp, n - 1) + solve(dp, n - 2);
    return dp[n];
}

int fib(int n) {
    vector<int> dp(n + 1, -1);  // Initialize memoization array with -1
    return solve(dp, n);
}

int solve1(vector<int> arr,int index, int amount,vector<vector<int>> &dp){
    if(amount==0){
        return 1;
    }
    if(amount<0|| index >= arr.size() ){
        return 0;
    }
    if(dp[index][amount] != -1) return dp[index][amount];
    int take=solve1(arr,index,amount-arr[index],dp);
    int skip=solve1(arr,index+1,amount,dp);
    return dp[index][amount] =min(take,skip);
}

int coinChangeI(vector<int>arr, int amount){
    vector<vector<int>> dp(arr.size(),vector<int>(amount+1,-1));
    return solve1(arr,0,amount,dp);
}

int main() {
    vector<int>arr={1,2,3};
    int amount=4;
    cout<<coinChangeI(arr,amount);
    return 0;
}
