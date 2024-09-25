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

int main() {
    int num;
    cout << "Enter the number: " << endl;
    cin >> num;
    //int ans = fib(num);
    //cout << "The Fibonacci of the number is: " << ans << endl;
    for(int i=0;i<5;i++){
        cout<<fib(i)<<" ";
    }
    return 0;
}
