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

int solve1(vector<int>& arr, int index, int amount, vector<vector<int>>& dp) {
    if(amount == 0) return 1; // Base case: if we have made the exact amount
    if(amount < 0 || index >= arr.size()) return 0; // Invalid case: amount is negative or out of bounds
    
    if(dp[index][amount] != -1) return dp[index][amount]; // Memoized result

    // Take the current coin or skip it
    int take = solve1(arr, index, amount - arr[index], dp); // Take current coin
    int skip = solve1(arr, index + 1, amount, dp); // Skip current coin

    return dp[index][amount] = take + skip; // Store result in dp table
}

int coinChangeII(vector<int>& arr, int amount) {
    vector<vector<int>> dp(arr.size(), vector<int>(amount + 1, -1)); // Initialize dp table with -1
    return solve1(arr, 0, amount, dp); // Start solving from index 0
}


int main() {
    vector<int>arr={1,2,3};
    int amount=4;
    cout<<coinChangeII(arr,amount);
    return 0;
}
