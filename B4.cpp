#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> count(batchSize, 0);
        int happyGroups = 0;

        // Count frequencies of remainders
        for (int group : groups) {
            int remainder = group % batchSize;
            if (remainder == 0) {
                happyGroups++; // Groups with no remainder are always happy
            } else {
                count[remainder]++;
            }
        }

        // Pair complementary remainders to form complete batches
        for (int i = 1; i <= batchSize / 2; i++) {
            if (i == batchSize - i) {
                // Special case: remainder pairs like (2, 2) when batchSize = 4
                happyGroups += count[i] / 2;
                count[i] %= 2;
            } else {
                int pairs = min(count[i], count[batchSize - i]);
                happyGroups += pairs;
                count[i] -= pairs;
                count[batchSize - i] -= pairs;
            }
        }

        // Remaining remainders: Use DP to optimize
        return happyGroups + dfs(count, 0, batchSize);
    }

private:
    unordered_map<string, int> memo;

    int dfs(vector<int>& count, int leftover, int batchSize) {
        // Check memoization
        string state = to_string(leftover) + ":" + vectorToString(count);
        if (memo.count(state)) return memo[state];

        // Base case: No groups left
        if (all_of(count.begin(), count.end(), [](int x) { return x == 0; })) {
            return 0;
        }

        int maxHappy = 0;
        for (int i = 1; i < count.size(); i++) {
            if (count[i] > 0) {
                count[i]--;
                int newLeftover = (leftover + i) % batchSize;
                int happyIncrement = (newLeftover == 0) ? 1 : 0;
                maxHappy = max(maxHappy, happyIncrement + dfs(count, newLeftover, batchSize));
                count[i]++;
            }
        }

        return memo[state] = maxHappy;
    }

    string vectorToString(const vector<int>& v) {
        string result;
        for (int num : v) {
            result += to_string(num) + ",";
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    int batchSize1 = 3;
    vector<int> groups1 = {1, 2, 3, 4, 5, 6};
    cout << "Max Happy Groups (Example 1): " << solution.maxHappyGroups(batchSize1, groups1) << endl;

    // Example 2
    int batchSize2 = 4;
    vector<int> groups2 = {1, 3, 2, 5, 2, 2, 1, 6};
    cout << "Max Happy Groups (Example 2): " << solution.maxHappyGroups(batchSize2, groups2) << endl;

    return 0;
}

