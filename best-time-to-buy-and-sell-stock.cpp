// Brute Force:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(prices[j] > prices[i]) {
                    int profit = prices[j] - prices[i];
                    max_profit = max(max_profit, profit);
                }
                
            }
        }

        if(max_profit == INT_MIN) return 0;

        return max_profit;
    }
};

// tc -> O(n^2)
// sc -> O(1)

// Optimised Sol:
// Keep track of local minima and keep on calculating maxPro

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPro = 0;
        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++) {
            // find the local minima
            minPrice = min(minPrice, prices[i]);
            // keep track of the profits
            maxPro = max(maxPro, prices[i] - minPrice);
        }

        return maxPro;
    }
};

// tc -> O(n)
// sc -> O(1)