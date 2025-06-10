#include <iostream>
#include <vector>
using namespace std;

// Problem: Best Time to Buy and Sell Stock
// Approach: Track minimum price so far and compute max profit on each day
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];      // Lowest price seen so far (buying price)
        int maxProfit = 0;         // Highest profit achievable

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < mini) {
                mini = prices[i];  // Found a new minimum price
            } else {
                int profit = prices[i] - mini; // Potential profit if sold today
                if (profit > maxProfit) {
                    maxProfit = profit;       // Update max profit
                }
            }
        }

        return maxProfit;
    }
};

